import os

# Create directories
if not os.path.exists("src"):
    os.makedirs("src")

# ==========================================
# 1. CORE INTERFACES & LEGACY (Adapter/Observer)
# ==========================================
files = {}

files["src/Interfaces.h"] = """
#ifndef INTERFACES_H
#define INTERFACES_H

#include <vector>
#include <algorithm>
#include <string>

// --- OBSERVER PATTERN ---
class Observer {
public:
    virtual void update(int layer) = 0;
};

class Subject {
    std::vector<Observer*> observers;
public:
    void attach(Observer* o) { observers.push_back(o); }
    void notify(int layer) {
        for(auto* o : observers) o->update(layer);
    }
};

// --- STRATEGY PATTERN (For Controller Validation) ---
class IValidationStrategy {
public:
    virtual bool isValid(int layer, int max) = 0;
};

// --- LEGACY COMPONENT (For Adapter Pattern) ---
// Simulates an old library that calculates height in INCHES
class OldPhysicsLibrary {
public:
    double calculateHeightInInches(int layer) {
        // 1 layer = 0.0078 inches (approx 0.2mm)
        return layer * 0.007874; 
    }
};

#endif
"""

# ==========================================
# 2. THE MODEL (Subject)
# ==========================================
files["src/SlicingModel.h"] = """
#ifndef SLICINGMODEL_H
#define SLICINGMODEL_H

#include "Interfaces.h"

class SlicingModel : public Subject {
private:
    int currentLayer;
    int maxLayers;

public:
    SlicingModel(int max) : maxLayers(max), currentLayer(0) {}

    int getLayer() const { return currentLayer; }
    int getMax() const { return maxLayers; }

    void setLayer(int layer) {
        if (currentLayer != layer) {
            currentLayer = layer;
            notify(currentLayer); // Trigger Observers
        }
    }
};

#endif
"""

# ==========================================
# 3. THE ADAPTER (Adapts OldPhysics to Metric)
# ==========================================
files["src/HeightAdapter.h"] = """
#ifndef HEIGHTADAPTER_H
#define HEIGHTADAPTER_H

#include "Interfaces.h"

// Client expects Millimeters (float), but Adaptee gives Inches (double)
class MetricAdapter {
private:
    OldPhysicsLibrary* legacyLib;

public:
    MetricAdapter() { legacyLib = new OldPhysicsLibrary(); }
    
    float getHeightMM(int layer) {
        double inches = legacyLib->calculateHeightInInches(layer);
        return (float)(inches * 25.4); // Convert Inch to MM
    }
};

#endif
"""

# ==========================================
# 4. THE COMPOSITE VIEW (Manages State)
# ==========================================
files["src/ViewComposite.h"] = """
#ifndef VIEWCOMPOSITE_H
#define VIEWCOMPOSITE_H

#include "Interfaces.h"
#include "HeightAdapter.h"
#include <string>
#include <sstream>

// This acts as the "Server-Side View State"
// It observes the model and prepares the JSON for the clients.
class ViewManager : public Observer {
private:
    std::string cachedJSON;
    MetricAdapter* adapter; // Using the Adapter

public:
    ViewManager() {
        adapter = new MetricAdapter();
        cachedJSON = "{ \\"layer\\": 0, \\"height\\": 0.00 }";
    }

    // Observer Update: Re-calculate the state when Model changes
    void update(int layer) override {
        float heightMM = adapter->getHeightMM(layer);
        
        std::stringstream ss;
        ss << "{ \\"layer\\": " << layer 
           << ", \\"height\\": " << heightMM << " }";
        
        cachedJSON = ss.str();
    }

    std::string getJSON() {
        return cachedJSON;
    }
};

#endif
"""

# ==========================================
# 5. THE CONTROLLER (Strategy)
# ==========================================
files["src/SlicingController.h"] = """
#ifndef SLICINGCONTROLLER_H
#define SLICINGCONTROLLER_H

#include "SlicingModel.h"
#include "Interfaces.h"

// Strategy: Standard Validation
class StandardValidation : public IValidationStrategy {
public:
    bool isValid(int layer, int max) override {
        return (layer >= 0 && layer <= max);
    }
};

class SlicingController {
private:
    SlicingModel* model;
    IValidationStrategy* strategy;

public:
    SlicingController(SlicingModel* m) : model(m) {
        strategy = new StandardValidation();
    }

    void processInput(int inputLayer) {
        if (strategy->isValid(inputLayer, model->getMax())) {
            model->setLayer(inputLayer);
        }
    }
};

#endif
"""

# ==========================================
# 6. MAIN SERVER (Orchestration)
# ==========================================
files["src/main.cpp"] = """
#include <iostream>
#include "httplib.h" // Ensure this is downloaded
#include "SlicingModel.h"
#include "SlicingController.h"
#include "ViewComposite.h"

int main() {
    // 1. Setup MVC Components
    SlicingModel model(1000);
    SlicingController controller(&model);
    ViewManager viewManager; // The Composite/Observer View

    // 2. Wire Observer
    model.attach(&viewManager);

    // 3. Setup Server
    httplib::Server svr;

    // --- CONTROLLER ENDPOINT ---
    svr.Get("/set_layer", [&](const httplib::Request& req, httplib::Response& res) {
        if (req.has_param("val")) {
            int val = std::stoi(req.get_param_value("val"));
            controller.processInput(val);
        }
        res.set_content("OK", "text/plain");
    });

    // --- VIEW ENDPOINT ---
    // Returns the cached JSON state from the ViewManager
    svr.Get("/get_state", [&](const httplib::Request& req, httplib::Response& res) {
        res.set_content(viewManager.getJSON(), "application/json");
    });

    // Serve HTML
    svr.set_mount_point("/", "./html");

    std::cout << "--- MVC Pattern Server Running ---" << std::endl;
    std::cout << "Composite View & Adapter Patterns Active." << std::endl;
    std::cout << "Open browser at port 8080..." << std::endl;
    
    svr.listen("0.0.0.0", 8080);
    return 0;
}
"""

# ==========================================
# 7. HTML FILES (The Dumb Terminals)
# ==========================================
if not os.path.exists("html"):
    os.makedirs("html")

# Common JavaScript for Robust Sync
common_js = """
    const slider = document.getElementById('slider');
    const display = document.getElementById('display');
    let isDragging = false;

    // 1. Handle Dragging (Don't update from server while I am dragging)
    slider.addEventListener('mousedown', () => { isDragging = true; });
    slider.addEventListener('mouseup', () => { 
        isDragging = false; 
        // Force an immediate fetch to sync nicely
        fetchUpdate(); 
    });

    // 2. Controller: Send data on Input (Continuous or Release)
    slider.addEventListener('input', () => {
        // Send updates immediately for smooth feel on OTHER window
        fetch(`/set_layer?val=${slider.value}`);
        updateText(slider.value); // Optimistic UI update
    });

    function updateText(layer, height = null) {
        if(window.viewType === 'image') {
            display.innerText = `Layer: ${layer} | Image: slice_${layer}.png`;
        } else {
            // If we don't have height yet, wait for server
            if(height !== null) display.innerText = `Z-Height: ${height.toFixed(2)} mm`;
        }
    }

    function fetchUpdate() {
        // Anti-Cache: Add timestamp to prevent browser from reusing old data
        fetch('/get_state?t=' + Date.now())
            .then(res => res.json())
            .then(data => {
                // Only update slider if I am NOT dragging it
                if (!isDragging) {
                    if(Math.abs(slider.value - data.layer) > 0) {
                        slider.value = data.layer;
                    }
                }
                // ALWAYS update the text/visuals
                updateText(data.layer, data.height);
            });
    }

    // Poll every 100ms for fast interaction
    setInterval(fetchUpdate, 100);
"""

files["html/image_view.html"] = f"""
<!DOCTYPE html>
<html>
<head><style>body{{font-family:sans-serif; padding:30px; background:#eee;}} .box{{background:white; padding:20px; border-radius:10px;}}</style></head>
<body>
    <div class="box">
        <h2>Slice Image Viewer</h2>
        <h1 id="display">Waiting...</h1>
        <input type="range" id="slider" min="0" max="1000" style="width:100%">
    </div>
    <script>
        window.viewType = 'image';
        {common_js}
    </script>
</body>
</html>
"""

files["html/model_view.html"] = f"""
<!DOCTYPE html>
<html>
<head><style>body{{font-family:sans-serif; padding:30px; background:#333; color:white;}} .box{{border:2px solid orange; padding:20px; border-radius:10px;}}</style></head>
<body>
    <div class="box">
        <h2>3D Model Viewer (Adapter Pattern)</h2>
        <h1 id="display">Waiting...</h1>
        <input type="range" id="slider" min="0" max="1000" style="width:100%">
    </div>
    <script>
        window.viewType = '3d';
        {common_js}
    </script>
</body>
</html>
"""

# Write all files
for path, content in files.items():
    with open(path, "w") as f:
        f.write(content.strip())
    print(f"Created {path}")

print("Done! Now compile with: g++ src/main.cpp -o app -I src -lpthread")
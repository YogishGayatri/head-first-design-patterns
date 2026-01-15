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
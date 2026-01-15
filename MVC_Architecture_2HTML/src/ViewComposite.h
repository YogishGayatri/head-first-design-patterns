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
        cachedJSON = "{ \"layer\": 0, \"height\": 0.00 }";
    }

    // Observer Update: Re-calculate the state when Model changes
    void update(int layer) override {
        float heightMM = adapter->getHeightMM(layer);
        
        std::stringstream ss;
        ss << "{ \"layer\": " << layer 
           << ", \"height\": " << heightMM << " }";
        
        cachedJSON = ss.str();
    }

    std::string getJSON() {
        return cachedJSON;
    }
};

#endif
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
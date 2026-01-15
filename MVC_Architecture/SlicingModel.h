#ifndef SLICINGMODEL_H
#define SLICINGMODEL_H

#include "Observer.h"

class SlicingModel : public Subject {
private:
    int currentLayer;
    int maxLayers;
    const float layerThickness = 0.2f; // mm

public:
    SlicingModel(int totalLayers);
    
    // Getters
    int getLayer() const;
    float getZHeight() const;

    // Setters
    void setLayer(int layer);
};

#endif
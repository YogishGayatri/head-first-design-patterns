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
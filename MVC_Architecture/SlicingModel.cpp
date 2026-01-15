#include "SlicingModel.h"

SlicingModel::SlicingModel(int totalLayers) : maxLayers(totalLayers), currentLayer(0) {}

int SlicingModel::getLayer() const { 
    return currentLayer; 
}

float SlicingModel::getZHeight() const { 
    return currentLayer * layerThickness; 
}

void SlicingModel::setLayer(int layer) {
    if (layer < 0) layer = 0;
    if (layer > maxLayers) layer = maxLayers;

    // Only notify if the value actually changed
    if (currentLayer != layer) {
        currentLayer = layer;
        notifyObservers(); // This triggers the update in both windows
    }
}
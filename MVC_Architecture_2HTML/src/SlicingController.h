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
#include "SlicingController.h"
#include "SlicingModel.h" // Now we include the full model definition
#include <iostream>

SlicingController::SlicingController(SlicingModel* m) : model(m) {}

void SlicingController::onSliderDrag(int tempValue) {
    // We log it, but we DO NOT update the model.
    std::cout << ">> [Controller] Slider dragging at " << tempValue << "... (Model NOT updated)" << std::endl;
}

void SlicingController::onSliderRelease(int finalValue) {
    std::cout << ">> [Controller] Slider Released. Committing value " << finalValue << " to Model." << std::endl;
    model->setLayer(finalValue);
}
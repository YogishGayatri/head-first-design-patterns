#include "Views.h"
#include "SlicingModel.h"
#include "SlicingController.h"
#include <iostream>

// --- Base Window Implementation ---
BaseWindow::BaseWindow(SlicingModel* m, SlicingController* c, std::string name) 
    : model(m), controller(c), windowName(name) {
    model->registerObserver(this);
}

BaseWindow::~BaseWindow() {
    model->removeObserver(this);
}

void BaseWindow::simulateUserDragSlider(int val) {
    std::cout << "\n[User Interaction on " << windowName << "]" << std::endl;
    controller->onSliderDrag(val);
}

void BaseWindow::simulateUserReleaseSlider(int val) {
    std::cout << "\n[User Interaction on " << windowName << "]" << std::endl;
    controller->onSliderRelease(val);
}

// --- SliceImageViewer Implementation ---
SliceImageViewer::SliceImageViewer(SlicingModel* m, SlicingController* c) 
    : BaseWindow(m, c, "Slice Image Viewer") {}

void SliceImageViewer::update() {
    // 1. Get data from model
    int layer = model->getLayer();
    // 2. Render logic
    std::cout << "   [DISPLAY UPDATE] " << windowName << " rendering: layer_" << layer << ".png" << std::endl;
}

// --- Model3DViewer Implementation ---
Model3DViewer::Model3DViewer(SlicingModel* m, SlicingController* c) 
    : BaseWindow(m, c, "AQA Model Viewer") {}

void Model3DViewer::update() {
    // 1. Get data from model
    float height = model->getZHeight();
    // 2. Render logic (different from window 1)
    std::cout << "   [DISPLAY UPDATE] " << windowName << " rendering 3D Mesh at Z-Height: " << height << "mm" << std::endl;
}
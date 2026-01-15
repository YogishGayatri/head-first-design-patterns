#include "SlicingModel.h"
#include "SlicingController.h"
#include "Views.h"
#include <iostream>

int main() {
    // 1. Initialize Model
    SlicingModel* model = new SlicingModel(1000); 

    // 2. Initialize Controller
    SlicingController* controller = new SlicingController(model);

    // 3. Initialize Views
    SliceImageViewer* window1 = new SliceImageViewer(model, controller);
    Model3DViewer* window2 = new Model3DViewer(model, controller);

    std::cout << "--- MVC System Initialized ---" << std::endl;

    // --- Interaction Loop ---

    // Scenario: User drags slider on "Slice Image Viewer"
    window1->simulateUserDragSlider(150);
    window1->simulateUserDragSlider(160);
    
    // User releases mouse -> Triggers update in BOTH windows
    window1->simulateUserReleaseSlider(200);

    // Scenario: User drags slider on "AQA Model Viewer"
    window2->simulateUserDragSlider(490);
    
    // User releases mouse -> Triggers update in BOTH windows
    window2->simulateUserReleaseSlider(500);

    // Cleanup
    delete window1;
    delete window2;
    delete controller;
    delete model;

    return 0;
}
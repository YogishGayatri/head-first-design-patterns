#ifndef VIEWS_H
#define VIEWS_H

#include "Observer.h"
#include <string>

// Forward declarations
class SlicingModel;
class SlicingController;

// Base Window Class
class BaseWindow : public Observer {
protected:
    SlicingModel* model;
    SlicingController* controller;
    std::string windowName;

public:
    BaseWindow(SlicingModel* m, SlicingController* c, std::string name);
    virtual ~BaseWindow();

    // Simulation methods
    void simulateUserDragSlider(int val);
    void simulateUserReleaseSlider(int val);
};

// Window 1: Slice Viewer (Shows Layer #)
class SliceImageViewer : public BaseWindow {
public:
    SliceImageViewer(SlicingModel* m, SlicingController* c);
    void update() override;
};

// Window 2: Model Viewer (Shows 3D Height)
class Model3DViewer : public BaseWindow {
public:
    Model3DViewer(SlicingModel* m, SlicingController* c);
    void update() override;
};

#endif
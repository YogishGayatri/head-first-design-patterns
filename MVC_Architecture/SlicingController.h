#ifndef SLICINGCONTROLLER_H
#define SLICINGCONTROLLER_H

// Forward declaration to avoid circular dependency issues
class SlicingModel; 

class SlicingController {
private:
    SlicingModel* model;

public:
    SlicingController(SlicingModel* m);

    // Logic for handling "Drag" (Continuous) vs "Release" (Commit)
    void onSliderDrag(int tempValue);
    void onSliderRelease(int finalValue);
};

#endif
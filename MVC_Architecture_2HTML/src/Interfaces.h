#ifndef INTERFACES_H
#define INTERFACES_H

#include <vector>
#include <algorithm>
#include <string>

// --- OBSERVER PATTERN ---
class Observer {
public:
    virtual void update(int layer) = 0;
};

class Subject {
    std::vector<Observer*> observers;
public:
    void attach(Observer* o) { observers.push_back(o); }
    void notify(int layer) {
        for(auto* o : observers) o->update(layer);
    }
};

// --- STRATEGY PATTERN (For Controller Validation) ---
class IValidationStrategy {
public:
    virtual bool isValid(int layer, int max) = 0;
};

// --- LEGACY COMPONENT (For Adapter Pattern) ---
// Simulates an old library that calculates height in INCHES
class OldPhysicsLibrary {
public:
    double calculateHeightInInches(int layer) {
        // 1 layer = 0.0078 inches (approx 0.2mm)
        return layer * 0.007874; 
    }
};

#endif
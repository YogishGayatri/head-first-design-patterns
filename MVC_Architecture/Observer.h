#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <algorithm>

// The Interface for objects that need to be notified (The Windows)
class Observer {
public:
    virtual ~Observer() {}
    virtual void update() = 0;
};

// The Interface for the object that holds the data (The Model)
class Subject {
private:
    std::vector<Observer*> observers;
public:
    virtual ~Subject() {}

    void registerObserver(Observer* o) {
        observers.push_back(o);
    }

    void removeObserver(Observer* o) {
        observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
    }

    void notifyObservers() {
        for (Observer* o : observers) {
            o->update();
        }
    }
};

#endif
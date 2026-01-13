#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include "QuackObservable.hpp"
#include "Observer.hpp"
#include <vector>

class Observable : public QuackObservable {
private:
    std::vector<Observer*> observers;
public:
    void registerObserver(Observer* observer) override {
        observers.push_back(observer);
    }
    void notifyObservers() override {
        for (auto observer : observers) {
            observer->update(this);
        }
    }
};

#endif
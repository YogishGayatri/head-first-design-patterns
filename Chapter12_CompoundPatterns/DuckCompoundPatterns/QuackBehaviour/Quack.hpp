#ifndef QUACK_HPP
#define QUACK_HPP

#include <iostream>
#include "../Observer/QuackObservable.hpp"
#include "../Observer/Observable.hpp"

class Quack : public QuackObservable {
public:
    virtual void quack() = 0;
    void registerObserver(Observer* observer) override {
        observable.registerObserver(observer);
    }
    void notifyObservers() override {
        observable.notifyObservers();
    }
private:
    Observable observable;
};

#endif
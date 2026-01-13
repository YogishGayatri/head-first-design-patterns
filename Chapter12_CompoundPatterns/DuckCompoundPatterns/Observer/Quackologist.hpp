#ifndef QUACKOLOGIST_HPP
#define QUACKOLOGIST_HPP

#include "../Observer/Observer.hpp"
#include "../Observer/QuackObservable.hpp"
#include <iostream>

class Quackologist : public Observer {
public:
    void update(QuackObservable* duck) override {
        std::cout << "Quackologist: " << typeid(*duck).name() << " just quacked." << std::endl;
    }
};

#endif
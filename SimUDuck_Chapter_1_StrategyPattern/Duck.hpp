#ifndef DUCK_HPP
#define DUCK_HPP

#include <iostream>
#include <memory>
#include "behaviors/FlyBehavior.hpp"
#include "behaviors/QuackBehavior.hpp"

class Duck {
protected:
    // Pointers to the interfaces
    std::unique_ptr<FlyBehavior> flyBehavior;
    std::unique_ptr<QuackBehavior> quackBehavior;

public:
    virtual ~Duck() = default;
    virtual void display() = 0;

    // Delegate behavior to the interface objects
    void performFly() {
        flyBehavior->fly();
    }

    void performQuack() {
        quackBehavior->quack();
    }

    // Setters for dynamic behavior changes
    void setFlyBehavior(std::unique_ptr<FlyBehavior> fb) {
        flyBehavior = std::move(fb);
    }

    void setQuackBehavior(std::unique_ptr<QuackBehavior> qb) {
        quackBehavior = std::move(qb);
    }
};

#endif
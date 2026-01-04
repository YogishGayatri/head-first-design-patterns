#ifndef RUBBER_DUCK_HPP
#define RUBBER_DUCK_HPP

#include "../Duck.hpp"
#include "../behaviors/FlyNoWay.hpp"
#include "../behaviors/Squeak.hpp"

class RubberDuck : public Duck {
public:
    RubberDuck() {
        // A Rubber Duck can't fly and squeaks
        flyBehavior = std::make_unique<FlyNoWay>();
        quackBehavior = std::make_unique<Squeak>();
    }

    void display() override {
        std::cout << "I'm a Rubber Duckie." << std::endl;
    }
};

#endif
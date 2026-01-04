#ifndef MALLARD_DUCK_HPP
#define MALLARD_DUCK_HPP

#include "../Duck.hpp"
#include "../behaviors/FlyWithWings.hpp"
#include "../behaviors/Quack.hpp"

class MallardDuck : public Duck {
public:
    MallardDuck() {
        // A Mallard uses wings to fly and quacks loudly
        flyBehavior = std::make_unique<FlyWithWings>();
        quackBehavior = std::make_unique<Quack>();
    }

    void display() override {
        std::cout << "I'm a real Mallard duck." << std::endl;
    }
};

#endif
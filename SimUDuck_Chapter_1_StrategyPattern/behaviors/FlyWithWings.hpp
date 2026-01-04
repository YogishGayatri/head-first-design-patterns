#ifndef FLY_WITH_WINGS_HPP
#define FLY_WITH_WINGS_HPP

#include "FlyBehavior.hpp"
#include <iostream>

class FlyWithWings : public FlyBehavior {
public:
    void fly() override { std::cout << "I'm flying!!" << std::endl; }
};

#endif
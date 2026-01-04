#ifndef FLY_NO_WAY_HPP
#define FLY_NO_WAY_HPP

#include "FlyBehavior.hpp"
#include <iostream>

class FlyNoWay : public FlyBehavior {
public:
    void fly() override { std::cout << "I can't fly." << std::endl; }
};

#endif
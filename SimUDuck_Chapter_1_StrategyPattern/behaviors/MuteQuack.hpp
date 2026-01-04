#ifndef MUTE_QUACK_HPP
#define MUTE_QUACK_HPP

#include "QuackBehavior.hpp"
#include <iostream>

class MuteQuack : public QuackBehavior {
public:
    void quack() override { std::cout << "<< Silence >>" << std::endl; }
};

#endif
#ifndef LIGHT_HPP
#define LIGHT_HPP
#include <iostream>
#include <string>

class Light {
    std::string location;
public:
    Light(std::string loc) : location(loc) {}

    void on() { std::cout << location << " Light is On" << std::endl; }
    void off() { std::cout << location << " Light is Off" << std::endl; }
};
#endif
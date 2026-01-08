#ifndef CEILING_FAN_HPP
#define CEILING_FAN_HPP
#include <iostream>
#include <string>

class CeilingFan {
    std::string location;
    int speed;

public:
    // Constants for speed
    static const int HIGH = 3;
    static const int MEDIUM = 2;
    static const int LOW = 1;
    static const int OFF = 0;

    CeilingFan(std::string loc) : location(loc), speed(OFF) {}

    void high() { speed = HIGH; std::cout << location << " Ceiling Fan is on HIGH" << std::endl; }
    void medium() { speed = MEDIUM; std::cout << location << " Ceiling Fan is on MEDIUM" << std::endl; }
    void low() { speed = LOW; std::cout << location << " Ceiling Fan is on LOW" << std::endl; }
    void off() { speed = OFF; std::cout << location << " Ceiling Fan is OFF" << std::endl; }
    
    int getSpeed() const { return speed; }
};
#endif
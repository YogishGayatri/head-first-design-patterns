#ifndef STEREO_HPP
#define STEREO_HPP
#include <iostream>
#include <string>

class Stereo {
    std::string location;
public:
    Stereo(std::string loc) : location(loc) {}

    void on() { std::cout << location << " Stereo is On" << std::endl; }
    void off() { std::cout << location << " Stereo is Off" << std::endl; }
    void setCD() { std::cout << location << " Stereo is set for CD input" << std::endl; }
    void setVolume(int volume) { std::cout << location << " Stereo volume set to " << volume << std::endl; }
};
#endif
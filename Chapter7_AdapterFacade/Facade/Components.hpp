#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP
#include <iostream>
#include <string>
//Directly defining various components of a Home Theater System
class Amplifier {
public:
    void on() { std::cout << "Amp on" << std::endl; }
    void setDvd(std::string dvd) { std::cout << "Amp setting DVD to " << dvd << std::endl; }
    void setSurroundSound() { std::cout << "Amp surround sound on (5 speakers, 1 subwoofer)" << std::endl; }
    void setVolume(int level) { std::cout << "Amp setting volume to " << level << std::endl; }
    void off() { std::cout << "Amp off" << std::endl; }
};

class Tuner { /* ... radio logic ... */ };

class DvdPlayer {
public:
    void on() { std::cout << "DVD Player on" << std::endl; }
    void play(std::string movie) { std::cout << "DVD Player playing \"" << movie << "\"" << std::endl; }
    void stop() { std::cout << "DVD Player stopped" << std::endl; }
    void eject() { std::cout << "DVD Player eject" << std::endl; }
    void off() { std::cout << "DVD Player off" << std::endl; }
};

class Projector {
public:
    void on() { std::cout << "Projector on" << std::endl; }
    void wideScreenMode() { std::cout << "Projector in widescreen mode (16x9)" << std::endl; }
    void off() { std::cout << "Projector off" << std::endl; }
};

class Screen {
public:
    void down() { std::cout << "Theater Screen going down" << std::endl; }
    void up() { std::cout << "Theater Screen going up" << std::endl; }
};

class PopcornPopper {
public:
    void on() { std::cout << "Popcorn Popper on" << std::endl; }
    void pop() { std::cout << "Popcorn Popper popping popcorn!" << std::endl; }
    void off() { std::cout << "Popcorn Popper off" << std::endl; }
};
#endif
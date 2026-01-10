#ifndef TURKEY_HPP
#define TURKEY_HPP
#include <iostream>

class Turkey {
public:
    virtual ~Turkey() = default;
    virtual void gobble() = 0;
    virtual void fly() = 0; // Turkeys fly short distances
};

class WildTurkey : public Turkey {
public:
    void gobble() override { std::cout << "Gobble gobble" << std::endl; }
    void fly() override { std::cout << "I'm flying a short distance" << std::endl; }
};
#endif
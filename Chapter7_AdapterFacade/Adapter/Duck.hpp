#ifndef DUCK_HPP
#define DUCK_HPP
#include <iostream>

class Duck {
public:
    virtual ~Duck() = default;
    virtual void quack() = 0;
    virtual void fly() = 0;
};

class MallardDuck : public Duck {
public:
    void quack() override { std::cout << "Quack" << std::endl; }
    void fly() override { std::cout << "I'm flying" << std::endl; }
};
#endif
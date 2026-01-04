// bad_designs/InterfaceTrap.cpp
#include <iostream>

// --- THE TRAP ---
// An interface has NO code, so we can't reuse logic.
class Flyable {
public:
    virtual void fly() = 0;
};

class Duck {
public:
    virtual void display() = 0;
};

// 1. Mallard Implementation
class MallardDuck : public Duck, public Flyable {
public:
    void display() override { std::cout << "I'm a Mallard." << std::endl; }
    
    // DUPLICATION #1
    void fly() override { 
        std::cout << "I'm flying with wings!" << std::endl; 
    }
};

// 2. Redhead Implementation
class RedheadDuck : public Duck, public Flyable {
public:
    void display() override { std::cout << "I'm a Redhead." << std::endl; }

    // DUPLICATION #2 (Imagine doing this for 50 ducks)
    void fly() override { 
        std::cout << "I'm flying with wings!" << std::endl; 
    }
};

int main() {
    std::cout << "--- INTERFACE TRAP ---" << std::endl;
    MallardDuck mallard;
    RedheadDuck redhead;
    
    mallard.fly();
    redhead.fly();
    
    return 0;
}
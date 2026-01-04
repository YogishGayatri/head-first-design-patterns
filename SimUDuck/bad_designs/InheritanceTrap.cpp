// bad_designs/InheritanceTrap.cpp
#include <iostream>

// --- THE TRAP ---
// By adding fly() here, we force it on everyone.
class Duck {
public:
    virtual void display() = 0;
    
    void fly() { 
        std::cout << "I am flying with wings!" << std::endl; 
    }
    
    void quack() { std::cout << "Quack!" << std::endl; }
};

class MallardDuck : public Duck {
public:
    void display() override { std::cout << "I'm a Mallard." << std::endl; }
};

class RubberDuck : public Duck {
public:
    void display() override { std::cout << "I'm a Rubber Duck." << std::endl; }
    // OOPS! We forgot to override fly(), so now rubber ducks fly!
};

int main() {
    std::cout << "--- INHERITANCE TRAP ---" << std::endl;
    RubberDuck toy;
    toy.display();
    
    std::cout << "Testing flight: ";
    toy.fly(); // Output: I am flying with wings! (BUG)
    
    return 0;
}
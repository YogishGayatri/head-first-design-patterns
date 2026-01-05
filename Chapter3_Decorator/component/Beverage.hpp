#ifndef BEVERAGE_HPP
#define BEVERAGE_HPP

#include <string>
#include <iostream>

// The Sizes Enum
enum Size { TALL, GRANDE, VENTI };
//Why didnt we use the interface here?
class Beverage {
protected:
    std::string description = "Unknown Beverage";
    Size size = TALL; // Default size

public:
    virtual ~Beverage() = default;

    virtual std::string getDescription() {
        return description;
    }

    virtual void setSize(Size s) {
        this->size = s;
    }

    virtual Size getSize() {
        return this->size;
    }

    // Pure virtual function: subclasses MUST define their own cost
    virtual double cost() = 0;
};

#endif
#ifndef MOCHA_HPP
#define MOCHA_HPP

#include "../component/CondimentDecorator.hpp"

class Mocha : public CondimentDecorator {
private:
    Beverage* beverage; // The object we are wrapping

public:
    // We pass the beverage we want to wrap into the constructor
    Mocha(Beverage* b) : beverage(b) {}

    std::string getDescription() override {
        return beverage->getDescription() + ", Mocha";
    }

    double cost() override {
        double cost = beverage->cost();
        
        // Size-based pricing logic
        if (beverage->getSize() == TALL) {
            cost += 0.20;
        } else if (beverage->getSize() == GRANDE) {
            cost += 0.25;
        } else if (beverage->getSize() == VENTI) {
            cost += 0.30;
        }
        
        return cost;
    }
};

#endif
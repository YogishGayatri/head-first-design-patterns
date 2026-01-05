#ifndef SOY_HPP
#define SOY_HPP

#include "../component/CondimentDecorator.hpp"

class Soy : public CondimentDecorator {
private:
    Beverage* beverage;

public:
    Soy(Beverage* b) : beverage(b) {}

    std::string getDescription() override {
        return beverage->getDescription() + ", Soy";
    }

    double cost() override {
        double cost = beverage->cost();
        if (beverage->getSize() == TALL) {
            cost += 0.10;
        } else if (beverage->getSize() == GRANDE) {
            cost += 0.15;
        } else if (beverage->getSize() == VENTI) {
            cost += 0.20;
        }
        return cost;
    }
};

#endif
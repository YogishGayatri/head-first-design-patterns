#ifndef WHIP_HPP
#define WHIP_HPP

#include "../component/CondimentDecorator.hpp"

class Whip : public CondimentDecorator {
private:
    Beverage* beverage;

public:
    Whip(Beverage* b) : beverage(b) {}

    std::string getDescription() override {
        return beverage->getDescription() + ", Whip";
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
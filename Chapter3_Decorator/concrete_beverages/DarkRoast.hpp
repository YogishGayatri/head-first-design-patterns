#ifndef DARK_ROAST_HPP
#define DARK_ROAST_HPP

#include "../component/Beverage.hpp"

class DarkRoast : public Beverage {
public:
    DarkRoast() {
        description = "Dark Roast Coffee";
    }

    double cost() override {
        return 0.99;
    }
};

#endif
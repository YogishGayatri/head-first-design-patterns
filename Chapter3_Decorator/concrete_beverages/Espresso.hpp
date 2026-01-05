#ifndef ESPRESSO_HPP
#define ESPRESSO_HPP

#include "../component/Beverage.hpp"

class Espresso : public Beverage {
public:
    Espresso() {
        description = "Espresso"; //Despriction of the beverage through the constructor
    }

    double cost() override {
        return 1.99;
    }
};

#endif
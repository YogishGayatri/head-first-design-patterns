#ifndef CONDIMENT_DECORATOR_HPP
#define CONDIMENT_DECORATOR_HPP

#include "Beverage.hpp"

// Decorators MUST be a Beverage (Is-A relationship)
// so they can wrap other Beverages.
class CondimentDecorator : public Beverage {
public:
    // We force decorators to re-implement getDescription
    // so they can append their name (e.g., ", Mocha")
    virtual std::string getDescription() = 0;
};

#endif
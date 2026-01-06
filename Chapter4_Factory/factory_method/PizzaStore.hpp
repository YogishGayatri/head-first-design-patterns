#ifndef PIZZA_STORE_HPP
#define PIZZA_STORE_HPP
#include "Pizza.hpp"

class PizzaStore {
public:
    virtual ~PizzaStore() = default;

    Pizza* orderPizza(std::string type) {
        Pizza* pizza;
        
        // METHOD CALL (We don't know what this returns yet)
        pizza = createPizza(type);

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }

protected:
    // FACTORY METHOD (Abstract)
    // The subclasses MUST implement this.
    //This the uniqueness of the Factory Method Pattern
    // It lets subclasses decide which concrete Product to create.
    virtual Pizza* createPizza(std::string type) = 0;
};
#endif
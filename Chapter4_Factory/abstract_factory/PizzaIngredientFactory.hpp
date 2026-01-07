#ifndef PIZZA_INGREDIENT_FACTORY_HPP
#define PIZZA_INGREDIENT_FACTORY_HPP
#include "Ingredients.hpp"

// THE ABSTRACT FACTORY INTERFACE
class PizzaIngredientFactory {
public:
    virtual Dough* createDough() = 0;
    virtual Sauce* createSauce() = 0;
    virtual Cheese* createCheese() = 0;
};
#endif
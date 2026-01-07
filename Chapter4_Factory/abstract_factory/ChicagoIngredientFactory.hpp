#ifndef CHICAGO_INGREDIENT_FACTORY_HPP
#define CHICAGO_INGREDIENT_FACTORY_HPP
#include "PizzaIngredientFactory.hpp"
#include "Ingredients.hpp"


//factory for Chicago implements its own version of create Ingredients
class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    Dough* createDough() override { return new ThickCrustDough(); }
    Sauce* createSauce() override { return new PlumTomatoSauce(); }
    Cheese* createCheese() override { return new MozzarellaCheese(); }
};
#endif
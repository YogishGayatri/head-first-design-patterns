#ifndef NY_INGREDIENT_FACTORY_HPP
#define NY_INGREDIENT_FACTORY_HPP
#include "PizzaIngredientFactory.hpp"

//factory for NY implements its own version of create Ingredients
class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    Dough* createDough() override { return new ThinCrustDough(); }
    Sauce* createSauce() override { return new MarinaraSauce(); }
    Cheese* createCheese() override { return new ReggianoCheese(); }
};
#endif
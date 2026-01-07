#ifndef PIZZA_STORE_AF_HPP
#define PIZZA_STORE_AF_HPP
#include "Pizza.hpp"
#include "NYIngredientFactory.hpp"
#include "ChicagoIngredientFactory.hpp"
// NY Store with Abstract Factory
class PizzaStore {
public:
    virtual ~PizzaStore() = default;
    Pizza* orderPizza(std::string type) {
        Pizza* pizza = createPizza(type);
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }
protected:
    virtual Pizza* createPizza(std::string type) = 0;
};


class NYPizzaStore : public PizzaStore {
protected:
    Pizza* createPizza(std::string type) override {
        Pizza* pizza = nullptr;
        // Create the NY specific factory
        PizzaIngredientFactory* ingredientFactory = new NYPizzaIngredientFactory();

        if (type == "cheese") {
            pizza = new CheesePizza(ingredientFactory);
            pizza->setName("New York Style Cheese Pizza");
        }
        return pizza;
    }
};

class ChicagoPizzaStore : public PizzaStore {
protected:
    Pizza* createPizza(std::string type) override {
        Pizza* pizza = nullptr;
        // Create the Chicago specific factory
        PizzaIngredientFactory* ingredientFactory = new ChicagoPizzaIngredientFactory();

        if (type == "cheese") {
            pizza = new CheesePizza(ingredientFactory);
            pizza->setName("Chicago Style Cheese Pizza");
        }
        return pizza;
    }
};
#endif
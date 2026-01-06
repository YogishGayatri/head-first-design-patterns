#ifndef CHICAGO_PIZZA_STORE_HPP
#define CHICAGO_PIZZA_STORE_HPP
#include "PizzaStore.hpp"

class ChicagoStyleCheesePizza : public Pizza {
public:
    ChicagoStyleCheesePizza() {
        name = "Chicago Style Deep Dish Cheese Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        toppings.push_back("Shredded Mozzarella Cheese");
    }
    void cut() override {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

class ChicagoStylePepperoniPizza : public Pizza {
public:
    ChicagoStylePepperoniPizza() {
        name = "Chicago Style Deep Dish Pepperoni Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        toppings.push_back("Shredded Mozzarella Cheese");
        toppings.push_back("Frozen Black Olives");
        toppings.push_back("Spinach");
        toppings.push_back("Eggplant");
        toppings.push_back("Sliced Pepperoni");
    }
 
    void cut() override {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

class ChicagoPizzaStore : public PizzaStore {
protected:
    Pizza* createPizza(std::string type) override {
        if (type == "cheese") {
            return new ChicagoStyleCheesePizza();
        }
        else if (type == "pepperoni") {
            return new ChicagoStylePepperoniPizza();
        }
        else {
            return nullptr;
        }
    }
};
#endif
#ifndef NY_PIZZA_STORE_HPP
#define NY_PIZZA_STORE_HPP
#include "PizzaStore.hpp"

// Concrete Product

//Nystyle cheese pizza class derived from Pizza
class NYStyleCheesePizza : public Pizza {
public:
    NYStyleCheesePizza() {
        name = "NY Style Sauce and Cheese Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        toppings.push_back("Grated Reggiano Cheese");
    }
};
class NYStylePepperoniPizza : public Pizza {
public:
    NYStylePepperoniPizza() {
        name = "NY Style Pepperoni Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        toppings.push_back("Grated Reggiano Cheese");
        toppings.push_back("Sliced Pepperoni");
        toppings.push_back("Garlic");
    }
};



// Concrete Creator
class NYPizzaStore : public PizzaStore {
protected:
    Pizza* createPizza(std::string type) override {
        if (type == "cheese") {
            return new NYStyleCheesePizza();
        } 
        else if (type == "pepperoni") {
            return new NYStylePepperoniPizza();
        }
        else {
            return nullptr;
        }
    }
};
#endif
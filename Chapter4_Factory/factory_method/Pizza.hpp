#ifndef PIZZA_HPP
#define PIZZA_HPP
#include <iostream>
#include <string>
#include <vector>

class Pizza {
protected:
    std::string name;
    std::string dough;
    std::string sauce;
    std::vector<std::string> toppings;

public:
    virtual ~Pizza() = default;

    void prepare() {
        std::cout << "Preparing " << name << std::endl;
        std::cout << "Tossing dough..." << std::endl;
        std::cout << "Adding sauce..." << std::endl;
        std::cout << "Adding toppings: ";
        for (const auto& topping : toppings) std::cout << topping << " ";
        std::cout << std::endl;
    }

    virtual void bake() { std::cout << "Bake for 25 mins at 350" << std::endl; }
    virtual void cut() { std::cout << "Cutting the pizza into diagonal slices" << std::endl; }
    virtual void box() { std::cout << "Place pizza in official PizzaStore box" << std::endl; }
    std::string getName() { return name; }
};
#endif
#ifndef MENU_ITEM_HPP
#define MENU_ITEM_HPP

#include "MenuComponent.hpp"

class MenuItem : public MenuComponent {
    std::string name;
    std::string description;
    bool vegetarian;
    double price;

public:
    MenuItem(std::string n, std::string d, bool v, double p) 
        : name(n), description(d), vegetarian(v), price(p) {}

    std::string getName() const override { return name; }
    std::string getDescription() const override { return description; }
    double getPrice() const override { return price; }
    bool isVegetarian() const override { return vegetarian; }

    void print() const override {
        std::cout << "  " << getName();
        if (isVegetarian()) std::cout << "(v)";
        std::cout << ", " << getPrice() << std::endl;
        std::cout << "     -- " << getDescription() << std::endl;
    }
};
#endif
#ifndef MENU_ITEM_HPP
#define MENU_ITEM_HPP
#include <string>
#include <iostream>

class MenuItem {
    std::string name;
    std::string description;
    bool vegetarian;
    double price;

public:
    MenuItem(std::string n, std::string d, bool v, double p) 
        : name(n), description(d), vegetarian(v), price(p) {}

    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    double getPrice() const { return price; }
    
    // Helper to print
    void print() const {
        std::cout << name << ", $" << price << " -- " << description << std::endl;
    }
};
#endif
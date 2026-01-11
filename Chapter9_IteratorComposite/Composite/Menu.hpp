#ifndef MENU_HPP
#define MENU_HPP

#include "MenuComponent.hpp"
#include <vector>
#include <algorithm>
//The composite Menu class
// MenuComponent is the base class for both Menu and MenuItem
class Menu : public MenuComponent {
    std::vector<MenuComponent*> menuComponents;
    std::string name;
    std::string description;

public:
    Menu(std::string n, std::string d) : name(n), description(d) {}

    // 1. Management Methods
    void add(MenuComponent* menuComponent) override {
        menuComponents.push_back(menuComponent);
    }

    // 2. Data Methods
    std::string getName() const override { return name; }
    std::string getDescription() const override { return description; }

    // 3. The Recursive Print
    void print() const override {
        std::cout << "\n" << getName();
        std::cout << ", " << getDescription() << std::endl;
        std::cout << "---------------------" << std::endl;

        // Recursion happens here!
        for (MenuComponent* component : menuComponents) {
            component->print(); 
        }
    }
    
    // Cleanup
    ~Menu() {
        for(auto c : menuComponents) delete c;
    }
};
#endif
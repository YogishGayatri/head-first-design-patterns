#ifndef PANCAKE_HOUSE_MENU_HPP
#define PANCAKE_HOUSE_MENU_HPP
#include "Menu.hpp"
#include "PancakeMenuIterator.hpp"
#include <vector>

class PancakeHouseMenu : public Menu {
    std::vector<MenuItem*> menuItems; // Standard Vector

public:
    PancakeHouseMenu() {
        addItem("K&B's Pancake Breakfast", "Pancakes with scrambled eggs", true, 2.99);
        addItem("Regular Pancake Breakfast", "Pancakes with fried eggs", false, 2.99);
        addItem("Blueberry Pancakes", "Pancakes with fresh blueberries", true, 3.49);
    }

    void addItem(std::string n, std::string d, bool v, double p) {
        menuItems.push_back(new MenuItem(n, d, v, p));
    }

    // THE FACTORY METHOD
    Iterator* createIterator() override {
        return new PancakeMenuIterator(menuItems);
    }
};
#endif
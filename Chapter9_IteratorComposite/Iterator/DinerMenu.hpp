#ifndef DINER_MENU_HPP
#define DINER_MENU_HPP
#include "Menu.hpp"
#include "DinerMenuIterator.hpp"

class DinerMenu : public Menu {
    static const int MAX_ITEMS = 6;
    int numberOfItems = 0;
    MenuItem* menuItems[MAX_ITEMS]; // Fixed Array

public:
    DinerMenu() {
        // Initialize array to null
        for(int i=0; i<MAX_ITEMS; i++) menuItems[i] = nullptr;
        
        addItem("Vegetarian BLT", "Fakin' Bacon on wheat", true, 2.99);
        addItem("BLT", "Bacon on wheat", false, 2.99);
        addItem("Hotdog", "A hot dog with relish", false, 3.05);
    }

    void addItem(std::string n, std::string d, bool v, double p) {
        if (numberOfItems >= MAX_ITEMS) {
            std::cout << "Sorry, menu is full!" << std::endl;
        } else {
            menuItems[numberOfItems] = new MenuItem(n, d, v, p);
            numberOfItems++;
        }
    }

    // THE FACTORY METHOD
    Iterator* createIterator() override {
        return new DinerMenuIterator(menuItems, MAX_ITEMS);
    }
};
#endif
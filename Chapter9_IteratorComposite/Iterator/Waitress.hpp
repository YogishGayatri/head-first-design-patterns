#ifndef WAITRESS_HPP
#define WAITRESS_HPP
#include "Menu.hpp"
#include "Iterator.hpp"

class Waitress {
    Menu* pancakeHouseMenu;
    Menu* dinerMenu;

public:
    Waitress(Menu* p, Menu* d) : pancakeHouseMenu(p), dinerMenu(d) {}

    void printMenu() {
        // 1. Get the iterators
        Iterator* pancakeIterator = pancakeHouseMenu->createIterator();
        Iterator* dinerIterator = dinerMenu->createIterator();

        std::cout << "MENU\n----\nBREAKFAST" << std::endl;
        printMenu(pancakeIterator);

        std::cout << "\nLUNCH" << std::endl;
        printMenu(dinerIterator);
        
        // Clean up iterators (important in C++)
        delete pancakeIterator;
        delete dinerIterator;
    }

private:
    // ONE LOOP TO RULE THEM ALL
    void printMenu(Iterator* iterator) {
        while (iterator->hasNext()) {
            MenuItem* menuItem = iterator->next();
            menuItem->print();
        }
    }
};
#endif
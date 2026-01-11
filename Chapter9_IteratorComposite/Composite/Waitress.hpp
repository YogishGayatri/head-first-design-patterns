#ifndef WAITRESS_HPP
#define WAITRESS_HPP

#include "MenuComponent.hpp"

class Waitress {
    MenuComponent* allMenus;

public:
    Waitress(MenuComponent* menus) : allMenus(menus) {}

    void printMenu() {
        allMenus->print();
    }
};
#endif
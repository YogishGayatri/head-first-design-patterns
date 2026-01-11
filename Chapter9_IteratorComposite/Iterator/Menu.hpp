#ifndef MENU_INTERFACE_HPP
#define MENU_INTERFACE_HPP
#include "Iterator.hpp"
// Menu Interface
class Menu {
public:
    virtual ~Menu() = default;
    virtual Iterator* createIterator() = 0;
};
#endif
#ifndef PANCAKE_MENU_ITERATOR_HPP
#define PANCAKE_MENU_ITERATOR_HPP
#include "Iterator.hpp"
#include <vector>

class PancakeMenuIterator : public Iterator {
    std::vector<MenuItem*>& items; // Reference to the vector
    int position;

public:
    PancakeMenuIterator(std::vector<MenuItem*>& itemsVector) 
        : items(itemsVector), position(0) {}

    bool hasNext() override {
        if (position >= items.size()) {
            return false;
        } else {
            return true;
        }
    }

    MenuItem* next() override {
        MenuItem* menuItem = items[position];
        position++;
        return menuItem;
    }
};
#endif
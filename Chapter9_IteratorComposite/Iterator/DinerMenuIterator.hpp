#ifndef DINER_MENU_ITERATOR_HPP
#define DINER_MENU_ITERATOR_HPP
#include "Iterator.hpp"

class DinerMenuIterator : public Iterator {
    MenuItem** items; // Pointer to the array of pointers
    int position;
    int maxItems;

public:
    DinerMenuIterator(MenuItem** itemsArray, int max) 
        : items(itemsArray), position(0), maxItems(max) {}

    bool hasNext() override {
        // Check bounds AND check if the slot is null (end of menu)
        if (position >= maxItems || items[position] == nullptr) {
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
#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "MenuItem.hpp"
// Iterator Interface
class Iterator {
public:
    virtual ~Iterator() = default;
    
    // Returns true if there are more elements to iterate over
    virtual bool hasNext() = 0;
    
    // Returns the next element
    virtual MenuItem* next() = 0;
};
#endif
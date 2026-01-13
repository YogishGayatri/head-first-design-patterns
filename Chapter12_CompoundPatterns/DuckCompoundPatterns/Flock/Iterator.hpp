#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "../QuackBehaviour/Quack.hpp"

class Iterator {
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() = 0;
    virtual Quack* next() = 0;
};

#endif
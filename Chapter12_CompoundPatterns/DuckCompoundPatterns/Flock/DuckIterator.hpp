#ifndef DUCKITERATOR_HPP
#define DUCKITERATOR_HPP

#include "Iterator.hpp"
#include <vector>

class DuckIterator : public Iterator {
private:
    std::vector<Quack*> ducks;
    size_t position = 0;
public:
    DuckIterator(const std::vector<Quack*>& d) : ducks(d) {}
    bool hasNext() override {
        return position < ducks.size();
    }
    Quack* next() override {
        if (!hasNext()) return nullptr;
        return ducks[position++];
    }
};

#endif
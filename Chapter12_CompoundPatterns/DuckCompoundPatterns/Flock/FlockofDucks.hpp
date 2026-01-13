#ifndef FLOCKOFDUCKS_HPP
#define FLOCKOFDUCKS_HPP
#include <vector>
#include <memory>
#include "../QuackBehaviour/Quack.hpp"
#include "Iterator.hpp"
#include "DuckIterator.hpp"


class FlockofDucks : public Quack{
    std::vector<std::unique_ptr<Quack>> ducks;
    public:
    void add(std::unique_ptr<Quack> duck){
        ducks.push_back(std::move(duck));
    }
    void quack() override {
        for(auto& duck : ducks){
            duck->quack();
        }
    }
    Iterator* createIterator() {
        std::vector<Quack*> rawPtrs;
        for(auto& duck : ducks) {
            rawPtrs.push_back(duck.get());
        }
        return new DuckIterator(rawPtrs);
    }

};


#endif
#ifndef QUACKCOUNTER_HPP
#define QUACKCOUNTER_HPP
#include <memory>
#include <iostream>
#include "../QuackBehaviour/Quack.hpp"
class QuackCounter: public Quack {
    std::unique_ptr<Quack> duck;
    static int numberofQuacks;
    public:
    QuackCounter(std::unique_ptr<Quack> qc) : duck(std::move(qc)){}
    void quack(){
        duck->quack();
        numberofQuacks ++;
        notifyObservers();
    }
    static int getquacks(){
        return numberofQuacks;
    }
};
int QuackCounter::numberofQuacks = 0;  // Definition of static member
#endif
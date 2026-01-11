#ifndef SOLD_OUT_STATE_HPP
#define SOLD_OUT_STATE_HPP
#include "../State.hpp"
#include "../GumballMachine.hpp"

class SoldOutState : public State {
public:
    void insertQuarter(GumballMachine* machine) override {
        std::cout << "You can't insert a quarter, the machine is sold out" << std::endl;
    }
    void ejectQuarter(GumballMachine* machine) override {
        std::cout << "You can't eject, you haven't inserted a quarter yet" << std::endl;
    }
    void turnCrank(GumballMachine* machine) override {
        std::cout << "You turned, but there are no gumballs" << std::endl;
    }
    void dispense(GumballMachine* machine) override {
        std::cout << "No gumball dispensed" << std::endl;
    }
    
    // THE REFILL MAGIC
    void refill(GumballMachine* machine) override { 
        machine->setState(machine->getNoQuarterState());
    }
};
#endif
#ifndef SOLD_STATE_HPP
#define SOLD_STATE_HPP
#include "../State.hpp"
#include "../GumballMachine.hpp"

class SoldState : public State {
public:
    void insertQuarter(GumballMachine* machine) override {
        std::cout << "Please wait, we're already giving you a gumball" << std::endl;
    }
    void ejectQuarter(GumballMachine* machine) override {
        std::cout << "Sorry, you already turned the crank" << std::endl;
    }
    void turnCrank(GumballMachine* machine) override {
        std::cout << "Turning twice doesn't get you another gumball!" << std::endl;
    }
    
    void dispense(GumballMachine* machine) override {
        machine->releaseBall(); // Physically drop the ball
        
        if (machine->getCount() > 0) {
            machine->setState(machine->getNoQuarterState());
        } else {
            std::cout << "Oops, out of gumballs!" << std::endl;
            machine->setState(machine->getSoldOutState());
        }
    }
    void refill(GumballMachine* machine) override { }
};
#endif
#ifndef NO_QUARTER_STATE_HPP
#define NO_QUARTER_STATE_HPP
#include "../State.hpp"
#include "../GumballMachine.hpp"

class NoQuarterState : public State {
public:
    void insertQuarter(GumballMachine* machine) override {
        std::cout << "You inserted a quarter" << std::endl;
        machine->setState(machine->getHasQuarterState());
    }
    void ejectQuarter(GumballMachine* machine) override {
        std::cout << "You haven't inserted a quarter" << std::endl;
    }
    void turnCrank(GumballMachine* machine) override {
        std::cout << "You turned, but there's no quarter" << std::endl;
    }
    void dispense(GumballMachine* machine) override {
        std::cout << "You need to pay first" << std::endl;
    }
    void refill(GumballMachine* machine) override { 
        // Logic handled in machine, or just ignored here
    }
};
#endif
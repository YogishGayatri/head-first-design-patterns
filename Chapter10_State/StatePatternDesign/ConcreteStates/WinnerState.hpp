#ifndef WINNER_STATE_HPP
#define WINNER_STATE_HPP
#include "../State.hpp"
#include "../GumballMachine.hpp"

class WinnerState : public State {
public:
    // ... insert/eject/crank same as SoldState (omitted for brevity) ...
    void insertQuarter(GumballMachine* m) override { std::cout << "Error" << std::endl; }
    void ejectQuarter(GumballMachine* m) override { std::cout << "Error" << std::endl; }
    void turnCrank(GumballMachine* m) override { std::cout << "Error" << std::endl; }

    void dispense(GumballMachine* machine) override {
        std::cout << "YOU'RE A WINNER! You get two gumballs for your quarter" << std::endl;
        
        // 1. Release first ball
        machine->releaseBall();
        
        if (machine->getCount() == 0) {
            machine->setState(machine->getSoldOutState());
        } else {
            // 2. Release second ball
            machine->releaseBall();
            if (machine->getCount() > 0) {
                machine->setState(machine->getNoQuarterState());
            } else {
                std::cout << "Oops, out of gumballs!" << std::endl;
                machine->setState(machine->getSoldOutState());
            }
        }
    }
    void refill(GumballMachine* machine) override { }
};
#endif
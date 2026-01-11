#ifndef HAS_QUARTER_STATE_HPP
#define HAS_QUARTER_STATE_HPP
#include "../State.hpp"
#include "../GumballMachine.hpp"
#include <random>

class HasQuarterState : public State {
    std::mt19937 rng; // Random number generator

public:
    HasQuarterState() {
        // Seed random generator
        std::random_device rd;
        rng.seed(rd());
    }

    void insertQuarter(GumballMachine* machine) override {
        std::cout << "You can't insert another quarter" << std::endl;
    }
    void ejectQuarter(GumballMachine* machine) override {
        std::cout << "Quarter returned" << std::endl;
        machine->setState(machine->getNoQuarterState());
    }
    
    // --- THE CRITICAL TRANSITION ---
    void turnCrank(GumballMachine* machine) override {
        std::cout << "You turned..." << std::endl;
        
        // 10% Chance to win!
        std::uniform_int_distribution<int> dist(0, 9);
        int winner = dist(rng);

        if ((winner == 0) && (machine->getCount() > 1)) {
            // WINNER!
            machine->setState(machine->getWinnerState());
        } else {
            // NORMAL
            machine->setState(machine->getSoldState());
        }
    }
    
    void dispense(GumballMachine* machine) override {
        std::cout << "No gumball dispensed" << std::endl;
    }
    void refill(GumballMachine* machine) override { }
};
#endif
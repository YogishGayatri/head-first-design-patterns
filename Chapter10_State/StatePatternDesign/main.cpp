#include "GumballMachine.hpp"
#include <iostream>

int main() {
    // 1. Create machine with 5 balls
    GumballMachine* gumballMachine = new GumballMachine(5);

    std::cout << "--- TESTING WINNER STATE ---" << std::endl;
    // We try to turn the crank multiple times to trigger the 10% chance
    for(int i=0; i<10; i++) {
        if(gumballMachine->getCount() > 0) {
            std::cout << "\nAttempt " << i+1 << ":" << std::endl;
            gumballMachine->insertQuarter();
            gumballMachine->turnCrank();
        }
    }

    std::cout << "\n--- TESTING REFILL ---" << std::endl;
    // Machine should be empty now
    gumballMachine->insertQuarter(); // Should fail
    gumballMachine->refill(5);       // Refill
    gumballMachine->insertQuarter(); // Should work
    gumballMachine->turnCrank();

    delete gumballMachine;
    return 0;
}
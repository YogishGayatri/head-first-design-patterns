#include <iostream>
#include <string>

class BadGumballMachine {
    // STATE CONSTANTS
    const static int SOLD_OUT = 0;
    const static int NO_QUARTER = 1;
    const static int HAS_QUARTER = 2;
    const static int SOLD = 3;
    
    int state = SOLD_OUT;
    int count = 0;

public:
    BadGumballMachine(int count) : count(count) {
        if (count > 0) state = NO_QUARTER;
    }

    // THE NIGHTMARE METHOD
    // Imagine adding a "Winner" state here. You have to edit this file 
    // and risk breaking existing code.
    void insertQuarter() {
        if (state == HAS_QUARTER) {
            std::cout << "You can't insert another quarter" << std::endl;
        } else if (state == NO_QUARTER) {
            state = HAS_QUARTER;
            std::cout << "You inserted a quarter" << std::endl;
        } else if (state == SOLD_OUT) {
            std::cout << "You can't insert a quarter, the machine is sold out" << std::endl;
        } else if (state == SOLD) {
            std::cout << "Please wait, we're already giving you a gumball" << std::endl;
        }
    }
    
    // ... ejectQuarter(), turnCrank(), dispense() all look exactly like this ...
};
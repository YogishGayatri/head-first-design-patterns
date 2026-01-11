#ifndef GUMBALL_MACHINE_HPP
#define GUMBALL_MACHINE_HPP

#include <iostream>
#include "State.hpp"

class GumballMachine {
    // The 5 States
    State* soldOutState;
    State* noQuarterState;
    State* hasQuarterState;
    State* soldState;
    State* winnerState;

    State* currentState;
    int count = 0;

public:
    GumballMachine(int numberGumballs);
    ~GumballMachine();

    // Actions called by user
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    
    // Actions called by State classes
    void setState(State* state);
    void releaseBall();
    
    // Refill Logic
    void refill(int numGumBalls);

    // Getters for states
    State* getSoldOutState() { return soldOutState; }
    State* getNoQuarterState() { return noQuarterState; }
    State* getHasQuarterState() { return hasQuarterState; }
    State* getSoldState() { return soldState; }
    State* getWinnerState() { return winnerState; }
    
    int getCount() const { return count; }
};

#endif
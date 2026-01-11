#include "GumballMachine.hpp"
// Include all concrete states
#include "ConcreteStates/SoldOutState.hpp"
#include "ConcreteStates/NoQuarterState.hpp"
#include "ConcreteStates/HasQuarterState.hpp"
#include "ConcreteStates/SoldState.hpp"
#include "ConcreteStates/WinnerState.hpp"

GumballMachine::GumballMachine(int numberGumballs) {
    soldOutState = new SoldOutState();
    noQuarterState = new NoQuarterState();
    hasQuarterState = new HasQuarterState();
    soldState = new SoldState();
    winnerState = new WinnerState();

    this->count = numberGumballs;
    if (numberGumballs > 0) {
        currentState = noQuarterState;
    } else {
        currentState = soldOutState;
    }
}

GumballMachine::~GumballMachine() {
    delete soldOutState;
    delete noQuarterState;
    delete hasQuarterState;
    delete soldState;
    delete winnerState;
}

// --- DELEGATION TO STATE ---
void GumballMachine::insertQuarter() {
    currentState->insertQuarter(this);
}
void GumballMachine::ejectQuarter() {
    currentState->ejectQuarter(this);
}
void GumballMachine::turnCrank() {
    currentState->turnCrank(this);
    // Note: dispense is an internal action, usually called by turnCrank's logic 
    // or automatically after. In this design, we call it if state implies it.
    if (currentState == soldState || currentState == winnerState) {
        currentState->dispense(this);
    }
}

// --- INTERNAL HELPERS ---
void GumballMachine::setState(State* state) {
    this->currentState = state;
}

void GumballMachine::releaseBall() {
    std::cout << "A gumball comes rolling out the slot..." << std::endl;
    if (count != 0) {
        count = count - 1;
    }
}

void GumballMachine::refill(int numGumBalls) {
    this->count += numGumBalls;
    std::cout << "The machine was just refilled; it's new count is: " << this->count << std::endl;
    // Let the current state handle the transition (e.g., SoldOut -> NoQuarter)
    currentState->refill(this); 
}
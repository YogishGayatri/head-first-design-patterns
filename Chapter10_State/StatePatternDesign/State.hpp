#ifndef STATE_HPP
#define STATE_HPP

class GumballMachine; // Forward declaration

class State {
public:
    virtual ~State() = default;
    virtual void insertQuarter(GumballMachine* machine) = 0;
    virtual void ejectQuarter(GumballMachine* machine) = 0;
    virtual void turnCrank(GumballMachine* machine) = 0;
    virtual void dispense(GumballMachine* machine) = 0;
    virtual void refill(GumballMachine* machine) = 0;
};
#endif
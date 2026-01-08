#ifndef CEILING_FAN_COMMANDS_HPP
#define CEILING_FAN_COMMANDS_HPP
#include "../interfaces/Command.hpp"
#include "../receivers/CeilingFan.hpp"

class CeilingFanHighCommand : public Command {
    CeilingFan* fan;
    int prevSpeed; // STATE: Remember what speed we were at

public:
    CeilingFanHighCommand(CeilingFan* f) : fan(f) {}

    void execute() override {
        prevSpeed = fan->getSpeed(); // 1. Save state
        fan->high();                 // 2. Change state
    }

    void undo() override {
        // Restore the fan to its previous speed
        if (prevSpeed == CeilingFan::HIGH) fan->high();
        else if (prevSpeed == CeilingFan::MEDIUM) fan->medium();
        else if (prevSpeed == CeilingFan::LOW) fan->low();
        else if (prevSpeed == CeilingFan::OFF) fan->off();
    }
};

class CeilingFanOffCommand : public Command {
    CeilingFan* fan;
    int prevSpeed;

public:
    CeilingFanOffCommand(CeilingFan* f) : fan(f) {}

    void execute() override {
        prevSpeed = fan->getSpeed();
        fan->off();
    }

    void undo() override {
        if (prevSpeed == CeilingFan::HIGH) fan->high();
        else if (prevSpeed == CeilingFan::MEDIUM) fan->medium();
        else if (prevSpeed == CeilingFan::LOW) fan->low();
        else if (prevSpeed == CeilingFan::OFF) fan->off();
    }
};

// --- MEDIUM COMMAND ---
class CeilingFanMediumCommand : public Command {
    CeilingFan* fan;
    int prevSpeed; // State variable

public:
    CeilingFanMediumCommand(CeilingFan* f) : fan(f) {}

    void execute() override {
        prevSpeed = fan->getSpeed(); // 1. Save current speed
        fan->medium();               // 2. Set to Medium
    }

    void undo() override {
        // Restore to whatever it was before
        if (prevSpeed == CeilingFan::HIGH) fan->high();
        else if (prevSpeed == CeilingFan::MEDIUM) fan->medium();
        else if (prevSpeed == CeilingFan::LOW) fan->low();
        else if (prevSpeed == CeilingFan::OFF) fan->off();
    }
};

// --- LOW COMMAND ---
class CeilingFanLowCommand : public Command {
    CeilingFan* fan;
    int prevSpeed;

public:
    CeilingFanLowCommand(CeilingFan* f) : fan(f) {}

    void execute() override {
        prevSpeed = fan->getSpeed(); // 1. Save current speed
        fan->low();                  // 2. Set to Low
    }

    void undo() override {
        // Restore
        if (prevSpeed == CeilingFan::HIGH) fan->high();
        else if (prevSpeed == CeilingFan::MEDIUM) fan->medium();
        else if (prevSpeed == CeilingFan::LOW) fan->low();
        else if (prevSpeed == CeilingFan::OFF) fan->off();
    }
};
#endif
#ifndef REMOTE_CONTROL_HPP
#define REMOTE_CONTROL_HPP

#include <vector>
#include <string>
#include <iostream>
#include "../interfaces/Command.hpp"

class RemoteControl {
    // Array of commands for 7 slots
    std::vector<Command*> onCommands;
    std::vector<Command*> offCommands;
    
    // The stash for the "Undo" button
    Command* undoCommand;

    // Helper to print slot info
    NoCommand* noCommand;

public:
    RemoteControl() {
        noCommand = new NoCommand();
        onCommands.resize(7, noCommand);
        offCommands.resize(7, noCommand);
        undoCommand = noCommand;
    }

    void setCommand(int slot, Command* onCmd, Command* offCmd) {
        onCommands[slot] = onCmd;
        offCommands[slot] = offCmd;
    }

    void onButtonWasPushed(int slot) {
        onCommands[slot]->execute();
        undoCommand = onCommands[slot]; // Save for undo
    }

    void offButtonWasPushed(int slot) {
        offCommands[slot]->execute();
        undoCommand = offCommands[slot]; // Save for undo
    }

    void undoButtonWasPushed() {
        std::cout << "--- UNDO ---" << std::endl;
        undoCommand->undo();
    }
    
    // Destructor to clean up NoCommand
    ~RemoteControl() {
        delete noCommand;
    }
};
#endif
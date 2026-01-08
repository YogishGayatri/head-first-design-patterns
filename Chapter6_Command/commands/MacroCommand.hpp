#ifndef MACRO_COMMAND_HPP
#define MACRO_COMMAND_HPP
#include <vector>
#include "../interfaces/Command.hpp"

class MacroCommand : public Command {
    std::vector<Command*> commands;

public:
    MacroCommand(std::vector<Command*> cmds) : commands(cmds) {}

    void execute() override {
        for (auto cmd : commands) {
            cmd->execute();
        }
    }

    void undo() override {
        // IMPORTANT: We must undo in REVERSE order!
        // If Party Mode turned Light ON then Fan ON...
        // Undo should turn Fan OFF then Light OFF.
        for (auto it = commands.rbegin(); it != commands.rend(); ++it) {
            (*it)->undo();
        }
    }
};
#endif
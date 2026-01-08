#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0; // New requirement!
};

// A "Null Object" so we don't have to check if(slot != nullptr) every time
class NoCommand : public Command {
public:
    void execute() override {}
    void undo() override {}
};
#endif
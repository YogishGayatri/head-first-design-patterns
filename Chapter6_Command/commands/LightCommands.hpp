#ifndef LIGHT_COMMANDS_HPP
#define LIGHT_COMMANDS_HPP
#include "../interfaces/Command.hpp"
#include "../receivers/Light.hpp"

class LightOnCommand : public Command {
    Light* light;
public:
    LightOnCommand(Light* l) : light(l) {}
    void execute() override { light->on(); }
    void undo() override { light->off(); } // Reverse is OFF
};

class LightOffCommand : public Command {
    Light* light;
public:
    //you get respective receiver object through constructor
    LightOffCommand(Light* l) : light(l) {}
    void execute() override { light->off(); }
    void undo() override { light->on(); } // Reverse is ON
};
#endif
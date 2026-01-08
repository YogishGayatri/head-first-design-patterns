#ifndef STEREO_COMMANDS_HPP
#define STEREO_COMMANDS_HPP
#include "../interfaces/Command.hpp"
#include "../receivers/Stereo.hpp"

class StereoOnWithCDCommand : public Command {
    Stereo* stereo;
public:
    StereoOnWithCDCommand(Stereo* s) : stereo(s) {}
    
    void execute() override {
        stereo->on();
        stereo->setCD();
        stereo->setVolume(11);
    }
    void undo() override {
        stereo->off(); // Simple undo
    }
};

class StereoOffCommand : public Command {
    Stereo* stereo;
public:
    StereoOffCommand(Stereo* s) : stereo(s) {}
    void execute() override { stereo->off(); }
    void undo() override { stereo->on(); stereo->setCD(); stereo->setVolume(11); }
};
#endif
#ifndef HOME_THEATER_FACADE_HPP
#define HOME_THEATER_FACADE_HPP

#include "Components.hpp"

class HomeTheaterFacade {
    Amplifier* amp;
    DvdPlayer* dvd;
    Projector* projector;
    Screen* screen;
    PopcornPopper* popper;

public:
    // We pass in all the complex components
    HomeTheaterFacade(Amplifier* a, DvdPlayer* d, Projector* p, Screen* s, PopcornPopper* pp) 
        : amp(a), dvd(d), projector(p), screen(s), popper(pp) {}

    // THE ONE BUTTON TO RULE THEM ALL
    void watchMovie(std::string movie) {
        std::cout << "Get ready to watch a movie..." << std::endl;
        popper->on();
        popper->pop();
        screen->down();
        projector->on();
        projector->wideScreenMode();
        amp->on();
        amp->setDvd(movie);
        amp->setSurroundSound();
        amp->setVolume(5);
        dvd->on();
        dvd->play(movie);
    }

    void endMovie() {
        std::cout << "\nShutting movie theater down..." << std::endl;
        popper->off();
        screen->up();
        projector->off();
        amp->off();
        dvd->stop();
        dvd->eject();
        dvd->off();
    }
};
#endif
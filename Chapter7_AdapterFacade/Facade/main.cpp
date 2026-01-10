#include "HomeTheaterFacade.hpp"

int main() {
    // 1. Setup the components (Usually done via dependency injection or config)
    Amplifier* amp = new Amplifier();
    DvdPlayer* dvd = new DvdPlayer();
    Projector* projector = new Projector();
    Screen* screen = new Screen();
    PopcornPopper* popper = new PopcornPopper();

    // 2. Create the Facade with all the components
    HomeTheaterFacade* homeTheater = new HomeTheaterFacade(amp, dvd, projector, screen, popper);

    // 3. Watch the movie (Look how simple this line is!)
    homeTheater->watchMovie("Raiders of the Lost Ark");

    // 4. End it
    homeTheater->endMovie();

    return 0;
}
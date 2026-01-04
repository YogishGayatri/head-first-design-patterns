#ifndef OBSERVER_HPP
#define OBSERVER_HPP

class Observer {
public:
    virtual ~Observer() = default;
    
    // PULL MODEL: No arguments. The Observer grabs what it needs.
    virtual void update() = 0;

    /* // PUSH MODEL (Alternative):
    // The Subject forces the data on the Observer.
    virtual void update(float temp, float humidity, float pressure) = 0;
    */
};

#endif
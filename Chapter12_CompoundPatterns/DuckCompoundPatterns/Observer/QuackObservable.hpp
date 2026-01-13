#ifndef QUACKOBSERVABLE_HPP
#define QUACKOBSERVABLE_HPP

class Observer;

class QuackObservable {
public:
    virtual ~QuackObservable() = default;
    virtual void registerObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

#endif
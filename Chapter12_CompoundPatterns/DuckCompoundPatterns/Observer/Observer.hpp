#ifndef OBSERVER_HPP
#define OBSERVER_HPP

class QuackObservable;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(QuackObservable* duck) = 0;
};

#endif
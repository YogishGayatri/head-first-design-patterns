#ifndef QUACK_BEHAVIOR_HPP
#define QUACK_BEHAVIOR_HPP

class QuackBehavior {
public:
    virtual ~QuackBehavior() = default;
    virtual void quack() = 0; // Pure virtual function
};

#endif
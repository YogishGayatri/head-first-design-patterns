#ifndef FLY_BEHAVIOR_HPP
#define FLY_BEHAVIOR_HPP

class FlyBehavior {
public:
    virtual ~FlyBehavior() = default;
    virtual void fly() = 0; // Pure virtual function
};

#endif
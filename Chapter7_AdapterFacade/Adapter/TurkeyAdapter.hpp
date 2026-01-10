#ifndef TURKEY_ADAPTER_HPP
#define TURKEY_ADAPTER_HPP
#include "Duck.hpp"
#include "Turkey.hpp"
// it inherits from the Target interface (Duck) and holds an instance of the Adaptee (Turkey)
class TurkeyAdapter : public Duck {
    Turkey* turkey; // 1. Composition: We hold a reference to the Adaptee

public:
    TurkeyAdapter(Turkey* t) : turkey(t) {}

    // 2. Translation: Translate Quack to Gobble
    void quack() override {
        turkey->gobble();
    }

    // 3. Logic Adjustment: Turkeys need to fly 5 times to match 1 duck flight
    void fly() override {
        for(int i=0; i < 5; i++) {
            turkey->fly();
        }
    }
};
#endif 
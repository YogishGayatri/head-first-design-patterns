#ifndef GOOSEADAPTOR_HPP
#define GOOSEADAPTOR_HPP
#include <memory>
#include "../QuackBehaviour/Quack.hpp"
#include "../Ducks/Ducks.hpp"

class GooseAdapter : public Quack {
    std::unique_ptr<Goose> goose;
    public:
    GooseAdapter(std::unique_ptr<Goose> g) : goose(std::move(g)){}
    void quack() override {
        goose->honk();
    }
};
#endif
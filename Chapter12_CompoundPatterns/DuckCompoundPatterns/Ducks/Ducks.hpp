#ifndef DUCKS_HPP
#define DUCKS_HPP
#include "../QuackBehaviour/Quack.hpp"

class MallardDuck : public Quack {
    public:
    void quack() override {
        std::cout << "Mallard Duck Quack!" << std::endl;
    }
};

class RedheadDuck : public Quack {
    public:
    void quack() override {
        std::cout << "Redhead Duck Quack !"<<std::endl;
    }
};

class Duckcall : public Quack {
    public:
    void quack() override {
        std::cout << "Duckcall quack ! " << std::endl;
    }
};
class RubberDuck : public Quack {
    public:
    void quack() override {
        std::cout <<"Rubber Duck Squeak "<<std::endl;
    }
};
class Goose {
    public:
    void honk(){
        std::cout << "Goose Honk !" << std::endl;
    }
};

#endif
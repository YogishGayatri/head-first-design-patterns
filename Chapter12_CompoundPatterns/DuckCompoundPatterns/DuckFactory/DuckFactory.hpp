#ifndef DUCKFACTORY_HPP
#define DUCKFACTORY_HPP

#include "../Ducks/Ducks.hpp"
#include "../Ducks/QuackCounter.hpp"
#include <memory>
#include <iostream>

class AbstractDuckFactory {
    public:
    virtual ~AbstractDuckFactory() = default;
    virtual std::unique_ptr<Quack> createMallardDuck () = 0;
    virtual std::unique_ptr<Quack> createRedHeadDuck () = 0;
    virtual std::unique_ptr<Quack> createDuckCall () = 0;
    virtual std::unique_ptr<Quack> createRubberDuck () = 0;
};
class DuckFactory : public AbstractDuckFactory{
    public:
    std::unique_ptr<Quack> createMallardDuck(){
        return std::make_unique<MallardDuck>();
    }
    std::unique_ptr<Quack> createRedHeadDuck(){
        return std::make_unique<RedheadDuck>();
    }
    std::unique_ptr<Quack> createDuckCall(){
        return std::make_unique<Duckcall>();
    }
    std::unique_ptr<Quack> createRubberDuck(){
        return std::make_unique<RubberDuck>();
    }
};

class DuckCountingFactory : public AbstractDuckFactory{
    public:
    std::unique_ptr<Quack> createMallardDuck(){
        return std::make_unique<QuackCounter>(std::make_unique<MallardDuck>());
    }
    std::unique_ptr<Quack> createRedHeadDuck(){
        return std::make_unique<QuackCounter>(std::make_unique<RedheadDuck>());
    }
    std::unique_ptr<Quack> createDuckCall(){
        return std::make_unique<QuackCounter>(std::make_unique<Duckcall>());
    }
    std::unique_ptr<Quack> createRubberDuck(){
        return std::make_unique<QuackCounter>(std::make_unique<RubberDuck>());
    }
};

#endif
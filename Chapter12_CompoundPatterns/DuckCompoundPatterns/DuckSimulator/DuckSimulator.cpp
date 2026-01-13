
#include <iostream>
#include "../Ducks/Ducks.hpp"
#include "../QuackBehaviour/Quack.hpp"
#include "../Ducks/GooseAdaptor.hpp"
#include "../Ducks/QuackCounter.hpp"
#include "../DuckFactory/DuckFactory.hpp"
#include "../Flock/FlockofDucks.hpp"
#include "../Observer/Quackologist.hpp"

#include <memory>
//used the smart pointer for the goose and normal pointers for the ducks

class DuckSimulator {
public : 
    void simulate(){
        DuckCountingFactory* duckFactory = new DuckCountingFactory();
        
        Quackologist* quackologist = new Quackologist();
        
        FlockofDucks flock;
        auto mallard = duckFactory->createMallardDuck();
        mallard->registerObserver(quackologist);
        flock.add(std::move(mallard));
        
        auto redhead = duckFactory->createRedHeadDuck();
        redhead->registerObserver(quackologist);
        flock.add(std::move(redhead));
        
        auto duckcall = duckFactory->createDuckCall();
        duckcall->registerObserver(quackologist);
        flock.add(std::move(duckcall));
        
        auto rubberduck = duckFactory->createRubberDuck();
        rubberduck->registerObserver(quackologist);
        flock.add(std::move(rubberduck));
        
        auto goose = std::make_unique<QuackCounter>(std::make_unique<GooseAdapter>(std::make_unique<Goose>()));
        goose->registerObserver(quackologist);
        flock.add(std::move(goose));

        std::cout << "Duck Simulator Game ! " << std::endl;
        Iterator* iterator = flock.createIterator();
        while(iterator->hasNext()){
            simulateQuack(*iterator->next());
        }
        delete iterator;
        std::cout << "The duck quacked " << QuackCounter::getquacks() <<" times"<<std::endl;
    }
    /*
    void simulate(){
        
        Quack* mallard = new MallardDuck();
        Quack* redhead = new RedheadDuck();
        Quack* duckcall = new Duckcall();
        Quack* rubberduck = new RubberDuck();
        Quack* goose = new GooseAdapter(std::make_unique<Goose>());
              
        
        auto mallard = std::make_unique<QuackCounter>(std::make_unique<MallardDuck>());
        auto redhead = std::make_unique<QuackCounter>(std::make_unique<RedheadDuck>());
        auto duckcall = std::make_unique<QuackCounter>(std::make_unique<Duckcall>());
        auto rubberduck = std::make_unique<QuackCounter>(std::make_unique<RubberDuck>());
        auto goose = std::make_unique<GooseAdapter>(std::make_unique<Goose>());

        std::cout << "Duck Simulator Game ! " << std::endl;
        simulateQuack(*mallard);
        simulateQuack(*redhead);
        simulateQuack(*duckcall);
        simulateQuack(*rubberduck);
        simulateQuack(*goose);
        std::cout << "The duck quacked " << rubberduck->getquacks() <<"times"<<std::endl;
    }
    
    void simulateQuack(Quack* duck){
        duck->quack();
    }
    */
    void simulateQuack(Quack& duck){
        duck.quack();
    }
};
int main(){
    DuckSimulator* simulator = new DuckSimulator();
    simulator->simulate();
    std::cout << "Total quacks: " << QuackCounter::getquacks() << std::endl;
    return 0;
}
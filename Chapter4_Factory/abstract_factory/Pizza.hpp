#ifndef PIZZA_AF_HPP
#define PIZZA_AF_HPP
#include "PizzaIngredientFactory.hpp"

class Pizza {
protected:
    std::string name;
    Dough* dough;
    Sauce* sauce;
    Cheese* cheese;

public:
    virtual ~Pizza() = default;
    
    // Abstract because the specific pizza knows what factory to use
    virtual void prepare() = 0;

    void bake() { std::cout << "Bake for 25 mins at 350\n"; }
    void cut() { std::cout << "Cutting the pizza into diagonal slices\n"; }
    void box() { std::cout << "Place pizza in official PizzaStore box\n"; }
    void setName(std::string n) { name = n; }
    std::string getName() { return name; }
};

// A concrete pizza that USES the factory
class CheesePizza : public Pizza {
    PizzaIngredientFactory* ingredientFactory;

public:
    // We pass the factory in the constructor!
    CheesePizza(PizzaIngredientFactory* factory) : ingredientFactory(factory) {}

    void prepare() override {
        std::cout << "Preparing " << name << std::endl;
        // The magic happens here: Composition!
        dough = ingredientFactory->createDough();
        sauce = ingredientFactory->createSauce();
        cheese = ingredientFactory->createCheese();
        std::cout << "   - " << dough->toString() << "\n";
        std::cout << "   - " << sauce->toString() << "\n";
        std::cout << "   - " << cheese->toString() << "\n";
    }
};
#endif
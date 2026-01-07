#include <iostream>
#include <string>

// Dummy Pizza classes for the bad example
class Pizza { public: virtual void prepare() = 0; virtual void bake() = 0; virtual void box() = 0; };
class NYStyleCheesePizza : public Pizza { public: void prepare() { std::cout << "Prep NY Cheese\n"; } void bake() { std::cout << "Bake NY\n"; } void box() { std::cout << "Box NY\n"; } };
class ChicagoStyleCheesePizza : public Pizza { public: void prepare() { std::cout << "Prep Chicago Cheese\n"; } void bake() { std::cout << "Bake Chicago\n"; } void box() { std::cout << "Box Chicago\n"; } };

class PizzaStore {
public:
    Pizza* orderPizza(std::string style, std::string type) {
        Pizza* pizza = nullptr;

        // THE BAD PART:
        // We are manually checking strings and creating concrete objects.
        // If we add "CaliforniaStyle", we have to break open this code.
        // This violates the Open/Closed Principle.
        // Also, the PizzaStore is tightly coupled to all Pizza subclasses.
        if (style == "NY") {
            if (type == "cheese") {
                pizza = new NYStyleCheesePizza();
            }
            // else if (type == "pepperoni")...
        } else if (style == "Chicago") {
            if (type == "cheese") {
                pizza = new ChicagoStyleCheesePizza();
            }
        }

        pizza->prepare();
        pizza->bake();
        pizza->box();
        return pizza;
    }
};

int main() {
    PizzaStore store;
    store.orderPizza("NY", "cheese");
    return 0;
}
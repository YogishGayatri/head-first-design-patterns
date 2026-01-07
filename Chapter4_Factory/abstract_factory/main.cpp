#include "PizzaStore.hpp"

int main() {
    PizzaStore* nyStore = new NYPizzaStore();
    
    std::cout << "--- Ethan orders a NY Pizza (Abstract Factory) ---" << std::endl;
    Pizza* pizza = nyStore->orderPizza("cheese");
    
    PizzaStore* chicagoStore = new ChicagoPizzaStore();
    
    std::cout << "--- Joel orders a Chicago Pizza (Abstract Factory) ---" << std::endl;
    Pizza* pizza2 = chicagoStore->orderPizza("cheese");
    
    return 0;
}
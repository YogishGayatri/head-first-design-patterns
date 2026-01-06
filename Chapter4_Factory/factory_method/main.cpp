#include "NYPizzaStore.hpp"
#include "ChicagoPizzaStore.hpp"

int main() {
    PizzaStore* nyStore = new NYPizzaStore();
    PizzaStore* chicagoStore = new ChicagoPizzaStore();

    std::cout << "--- Ethan orders a NY Pizza ---" << std::endl;
    Pizza* pizza = nyStore->orderPizza("cheese");
    std::cout << "Ethan ordered a " << pizza->getName() << "\n" << std::endl;

    std::cout << "--- Joel orders a Chicago Pizza ---" << std::endl;
    pizza = chicagoStore->orderPizza("cheese");
    std::cout << "Joel ordered a " << pizza->getName() << "\n" << std::endl;
    
    // Clean up memory in real code
    return 0;
}
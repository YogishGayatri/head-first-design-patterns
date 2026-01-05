#include <iostream>
#include <iomanip> // For std::setprecision

#include "concrete_beverages/Espresso.hpp"
#include "concrete_beverages/DarkRoast.hpp"
#include "decorators/Mocha.hpp"
#include "decorators/Whip.hpp"
#include "decorators/Soy.hpp"

int main() {
    // Formatting output for currency
    std::cout << std::fixed << std::setprecision(2);

    // 1. Simple Order: Espresso (No Decorators)
    Beverage* beverage = new Espresso();
    std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;

    // 2. Complex Order: Dark Roast with Double Mocha and Whip
    // Start with the base
    Beverage* beverage2 = new DarkRoast();
    beverage2->setSize(VENTI); // Setting size affects condiment prices!

    // Wrap it in Mocha
    beverage2 = new Mocha(beverage2);
    // Wrap it in a SECOND Mocha
    beverage2 = new Mocha(beverage2);
    // Wrap it in Whip
    beverage2 = new Whip(beverage2);

    std::cout << beverage2->getDescription() 
              << " $" << beverage2->cost() << std::endl;

    // 3. Soy Example
    Beverage* beverage3 = new Espresso();
    beverage3->setSize(TALL);
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);

    std::cout << beverage3->getDescription() 
              << " $" << beverage3->cost() << std::endl;

    return 0;
}
#include <iostream>
#include "ducks/MallardDuck.hpp"
#include "ducks/RubberDuck.hpp"
#include "behaviors/FlyNoWay.hpp" // Needed for runtime change example

int main() {
    // 1. Test the Mallard Duck
    std::cout << "--- Testing Mallard ---" << std::endl;
    MallardDuck mallard;
    mallard.display();
    mallard.performQuack();
    mallard.performFly();

    // 2. Test the Rubber Duck
    std::cout << "\n--- Testing Rubber Duck ---" << std::endl;
    RubberDuck rubberDuckie;
    rubberDuckie.display();
    rubberDuckie.performQuack();
    rubberDuckie.performFly();

    // 3. Test Runtime Behavior Change (Strategy Pattern Power!)
    std::cout << "\n--- Testing Runtime Change ---" << std::endl;
    std::cout << "Mallard gets injured..." << std::endl;
    
    // Changing the Mallard's behavior dynamically
    mallard.setFlyBehavior(std::make_unique<FlyNoWay>());
    mallard.performFly();

    return 0;
}
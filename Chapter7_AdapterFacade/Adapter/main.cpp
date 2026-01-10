#include "TurkeyAdapter.hpp"

// The Client only knows how to use Ducks
void testDuck(Duck* duck) {
    duck->quack();
    duck->fly();
}

int main() {
    MallardDuck* duck = new MallardDuck();
    
    WildTurkey* turkey = new WildTurkey();
    
    // WRAP THE TURKEY
    // To the test function, this looks like a Duck!
    Duck* turkeyAdapter = new TurkeyAdapter(turkey);

    std::cout << "--- The Duck says ---" << std::endl;
    testDuck(duck);

    std::cout << "\n--- The TurkeyAdapter says ---" << std::endl;
    testDuck(turkeyAdapter);

    return 0;
}
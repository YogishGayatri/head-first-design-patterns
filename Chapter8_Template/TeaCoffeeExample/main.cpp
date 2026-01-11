#include "Tea.hpp"
#include "Coffee.hpp"
#include <iostream>

int main() {
    std::cout << "--- MAKING TEA ---" << std::endl;
    Tea* myTea = new Tea();
    
    // We call the Template Method. 
    // Notice: We do NOT call myTea->brew() or myTea->boilWater() directly.
    // The Hollywood Principle: We ask the class to run its recipe.
    myTea->prepareRecipe();


    std::cout << "\n--- MAKING COFFEE ---" << std::endl;
    Coffee* myCoffee = new Coffee();
    
    // This will trigger the interactive hook
    myCoffee->prepareRecipe();

    // Cleanup
    delete myTea;
    delete myCoffee;

    return 0;
}
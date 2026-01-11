#ifndef CAFFEINE_BEVERAGE_HPP
#define CAFFEINE_BEVERAGE_HPP

#include <iostream>

class CaffeineBeverage {
public:
    virtual ~CaffeineBeverage() = default;

    // --- THE TEMPLATE METHOD ---
    // This is the "Script". It is declared 'final' so subclasses
    // CANNOT change the steps. The Director is in charge!
    // Note: 'final' is a C++11 feature.
    virtual void prepareRecipe() final {
        boilWater();
        brew();                   // Call the subclass
        pourInCup();
        
        // THE HOOK IN ACTION
        // We ask the subclass: "Do you want condiments?"
        if (customerWantsCondiments()) {
            addCondiments();      // Call the subclass
        }
    }

    // --- CONCRETE METHODS (Shared Steps) ---
    void boilWater() const {
        std::cout << "Boiling water" << std::endl;
    }

    void pourInCup() const {
        std::cout << "Pouring into cup" << std::endl;
    }

    // --- PRIMITIVE OPERATIONS (Abstract Steps) ---
    // The subclasses MUST implement these.
    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    // --- THE HOOK ---
    // A method with a default implementation (usually empty or true/false).
    // Subclasses can override it if they want, but they don't have to.
    virtual bool customerWantsCondiments() {
        return true; // Default: Always add condiments
    }
};

#endif
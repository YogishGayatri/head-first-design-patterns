#include <iostream>
#include <string>

// --- THE BAD DESIGN: The All-Knowing Base Class ---
class Beverage {
protected:
    std::string description;
    
    // THE TRAP: Adding variables for every possible condiment here.
    // What happens when Starbuzz adds "Oat Milk"? We have to edit this file.
    // What if I want double Mocha? Boolean only handles yes/no!
    bool milk;
    bool soy;
    bool mocha;
    bool whip;

public:
    Beverage() : milk(false), soy(false), mocha(false), whip(false) {}
    virtual ~Beverage() = default;

    virtual std::string getDescription() {
        std::string fullDesc = description;
        if (milk) fullDesc += ", Steamed Milk";
        if (soy) fullDesc += ", Soy";
        if (mocha) fullDesc += ", Mocha";
        if (whip) fullDesc += ", Whip";
        return fullDesc;
    }

    // THE MONSTER METHOD
    // The superclass calculates the cost of condiments.
    virtual double cost() {
        double condimentCost = 0.0;
        if (milk) condimentCost += 0.10;
        if (soy) condimentCost += 0.15;
        if (mocha) condimentCost += 0.20;
        if (whip) condimentCost += 0.10;
        return condimentCost;
    }

    // Getters and Setters for every single condiment
    void setMilk(bool hasMilk) { milk = hasMilk; }
    void setSoy(bool hasSoy) { soy = hasSoy; }
    void setMocha(bool hasMocha) { mocha = hasMocha; }
    void setWhip(bool hasWhip) { whip = hasWhip; }
};

// --- CONCRETE CLASSES ---
// They now look simple, but they are rigid.

class DarkRoast : public Beverage {
public:
    DarkRoast() {
        description = "Dark Roast Coffee";
    }

    double cost() override {
        // We get the condiment cost from the parent, then add our own
        return 0.99 + Beverage::cost(); 
    }
};

class Espresso : public Beverage {
public:
    Espresso() {
        description = "Espresso";
    }

    double cost() override {
        return 1.99 + Beverage::cost();
    }
};

int main() {
    std::cout << "--- THE RIGID BEVERAGE APP ---" << std::endl;

    // 1. Order a Dark Roast with Mocha and Whip
    DarkRoast myOrder;
    myOrder.setMocha(true);
    myOrder.setWhip(true);

    std::cout << myOrder.getDescription() << " $" << myOrder.cost() << std::endl;

    // --- WHY THIS FAILS ---
    
    // FAIL #1: Double Mocha?
    // You cannot do myOrder.setMocha(2). It's just a boolean.
    
    // FAIL #2: Tea?
    // If we add a "Tea" class that inherits from Beverage, 
    // it still has methods like 'setMocha()' and 'setWhip()'.
    // Use your imagination: Do you put whipped cream on Iced Tea? 
    // The base class forces functions on subclasses that don't need them.

    return 0;
}
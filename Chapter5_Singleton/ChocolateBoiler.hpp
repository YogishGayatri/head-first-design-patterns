#ifndef CHOCOLATE_BOILER_HPP
#define CHOCOLATE_BOILER_HPP

#include <iostream>

class ChocolateBoiler {
private:
    bool empty;
    bool boiled;

    // PRIVATE CONSTRUCTOR
    // This runs only ONCE when the static instance is created.
    ChocolateBoiler() {
        empty = true;
        boiled = false;
        std::cout << "Creating unique instance of Chocolate Boiler" << std::endl;
    }

public:
    // --- THE MEYERS' SINGLETON ---
    // Thread-safe in C++11 and later.
    static ChocolateBoiler& getInstance() {
        static ChocolateBoiler instance; 
        return instance;
    }
// --- DANGERS OF NOT DELETING COPY CONSTRUCTOR ---
// 1. Get the official instance
//ChocolateBoiler& original = ChocolateBoiler::getInstance();

// 2. ACCIDENTAL CLONE!
// Without '= delete', C++ creates a COPY of the boiler here.
//ChocolateBoiler fakeCopy = original; 
// Now you have TWO boilers in memory. 
// One might be empty, the other might be boiling. Disaster!


    // --- SAFETY: PREVENT COPIES ---
    // If you could copy it, you'd have two boilers!
    ChocolateBoiler(const ChocolateBoiler&) = delete;
    void operator=(const ChocolateBoiler&) = delete;

    // --- BUSINESS LOGIC ---
    
    void fill() {
        if (isEmpty()) {
            empty = false;
            boiled = false;
            std::cout << "Fill: Filling the boiler with a milk/chocolate mixture" << std::endl;
        } else {
            std::cout << "Error: Boiler already full!" << std::endl;
        }
    }

    void drain() {
        if (!isEmpty() && isBoiled()) {
            // Drain the boiled milk and chocolate
            empty = true;
            std::cout << "Drain: Draining the boiled milk and chocolate" << std::endl;
        } else {
            std::cout << "Error: Can't drain (Either empty or not boiled yet!)" << std::endl;
        }
    }

    void boil() {
        if (!isEmpty() && !isBoiled()) {
            // Bring the contents to a boil
            boiled = true;
            std::cout << "Boil: Boiling the contents..." << std::endl;
        } else {
            std::cout << "Error: Can't boil (Either empty or already boiled!)" << std::endl;
        }
    }

    bool isEmpty() const {
        return empty;
    }

    bool isBoiled() const {
        return boiled;
    }
};

#endif
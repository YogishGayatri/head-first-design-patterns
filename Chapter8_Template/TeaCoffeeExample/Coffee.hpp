#ifndef COFFEE_HPP
#define COFFEE_HPP

#include "CaffeineBeverage.hpp"
#include <string>
#include <algorithm> // For transform

class Coffee : public CaffeineBeverage {
public:
    void brew() override {
        std::cout << "Dripping Coffee through filter" << std::endl;
    }

    void addCondiments() override {
        std::cout << "Adding Sugar and Milk" << std::endl;
    }

    // --- OVERRIDING THE HOOK ---
    // This connects the algorithm to the user's live decision.
    bool customerWantsCondiments() override {
        std::string answer = getUserInput();

        // Check if answer starts with 'y' or 'Y'
        if (!answer.empty() && (answer[0] == 'y' || answer[0] == 'Y')) {
            return true;
        } else {
            return false;
        }
    }

private:
    std::string getUserInput() {
        std::string answer;
        std::cout << "Would you like milk and sugar with your coffee (y/n)? ";
        std::cin >> answer;
        return answer;
    }
};

#endif
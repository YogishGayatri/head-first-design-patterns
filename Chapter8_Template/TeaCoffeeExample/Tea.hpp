#ifndef TEA_HPP
#define TEA_HPP

#include "CaffeineBeverage.hpp"

class Tea : public CaffeineBeverage {
public:
    // 1. Implement the specific brew logic
    void brew() override {
        std::cout << "Steeping the tea bag" << std::endl;
    }

    // 2. Implement the specific condiment logic
    void addCondiments() override {
        std::cout << "Adding Lemon" << std::endl;
    }
    
    // We do NOT override the hook, so it defaults to true.
};

#endif
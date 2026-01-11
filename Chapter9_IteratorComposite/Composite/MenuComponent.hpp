#ifndef MENU_COMPONENT_HPP
#define MENU_COMPONENT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class MenuComponent {
public:
    virtual ~MenuComponent() = default;

    // --- COMPOSITE METHODS (Management) ---
    virtual void add(MenuComponent* menuComponent) {
        throw std::runtime_error("Unsupported Operation: add");
    }
    virtual void remove(MenuComponent* menuComponent) {
        throw std::runtime_error("Unsupported Operation: remove");
    }
    virtual MenuComponent* getChild(int i) {
        throw std::runtime_error("Unsupported Operation: getChild");
    }

    // --- LEAF METHODS (Data) ---
    virtual std::string getName() const {
        throw std::runtime_error("Unsupported Operation: getName");
    }
    virtual std::string getDescription() const {
        throw std::runtime_error("Unsupported Operation: getDescription");
    }
    virtual double getPrice() const {
        throw std::runtime_error("Unsupported Operation: getPrice");
    }
    virtual bool isVegetarian() const {
        throw std::runtime_error("Unsupported Operation: isVegetarian");
    }

    // --- THE COMMON OPERATION ---
    virtual void print() const {
        throw std::runtime_error("Unsupported Operation: print");
    }
};
#endif
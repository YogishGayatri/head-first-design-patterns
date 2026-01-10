#include <iostream>

class Thermostat {
public:
    float getTemp() { return 98.6f; }
};

class Engine {
    Thermostat thermo;
public:
    // WRAPPER METHOD
    // The Engine handles the delegation internally.
    float getTemperature() { 
        return thermo.getTemp(); 
    }
};

class Car {
    Engine engine;
public:
    void getEngineTemp() {
        // GOOD DESIGN
        // We only talk to our friend (the Engine).
        // You are not calling any methods on objects returned by the Engine.
        float temp = engine.getTemperature();
        std::cout << "Engine Temp: " << temp << std::endl;
    }
};
#include <iostream>

class Thermostat {
public:
    float getTemp() { return 98.6f; }
};

class Engine {
    Thermostat thermo;
public:
    Thermostat& getThermostat() { return thermo; }
};

class Car {
    Engine engine;
public:
    void getEngineTemp() {
        // BAD DESIGN (The Train Wreck)
        // The Car is reaching THROUGH the Engine to touch the Thermostat.
        // If Engine changes (e.g., removes Thermostat), this code breaks.
        float temp = engine.getThermostat().getTemp(); 
        std::cout << "Engine Temp: " << temp << std::endl;
    }
};

int main() {
    Car c;
    c.getEngineTemp();
    return 0;
}
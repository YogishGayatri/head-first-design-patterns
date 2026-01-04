#ifndef FORECAST_DISPLAY_HPP
#define FORECAST_DISPLAY_HPP

#include <iostream>
#include "../interfaces/Observer.hpp"
#include "../interfaces/DisplayElement.hpp"
#include "../weather/WeatherData.hpp"

class ForecastDisplay : public Observer, public DisplayElement {
private:
    float currentPressure = 29.92f;  
    float lastPressure;
    WeatherData* weatherData;

public:
    ForecastDisplay(WeatherData* wd) : weatherData(wd) {
        weatherData->registerObserver(this);
    }

    void update() override {
        // PULL: We only care about Pressure here!
        lastPressure = currentPressure;
        currentPressure = weatherData->getPressure();
        display();
    }

    void display() override {
        std::cout << "Forecast: ";
        if (currentPressure > lastPressure) {
            std::cout << "Improving weather on the way!" << std::endl;
        } else if (currentPressure == lastPressure) {
            std::cout << "More of the same." << std::endl;
        } else {
            std::cout << "Watch out for cooler, rainy weather." << std::endl;
        }
    }
};

#endif
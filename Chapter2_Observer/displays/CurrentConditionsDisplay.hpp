#ifndef CURRENT_CONDITIONS_DISPLAY_HPP
#define CURRENT_CONDITIONS_DISPLAY_HPP

#include <iostream>
#include "../interfaces/Observer.hpp"
#include "../interfaces/DisplayElement.hpp"
#include "../weather/WeatherData.hpp"

class CurrentConditionsDisplay : public Observer, public DisplayElement {
private:
    float temperature;
    float humidity;
    WeatherData* weatherData; // Reference to Subject for "Pulling"

public:
    CurrentConditionsDisplay(WeatherData* wd) : weatherData(wd) {
        weatherData->registerObserver(this);
    }

    // PULL MODEL UPDATE
    void update() override {
        // We act proactively to fetch ONLY what we need
        this->temperature = weatherData->getTemperature();
        this->humidity = weatherData->getHumidity();
        display();
    }

    /*
    // PUSH MODEL UPDATE (Alternative)
    void update(float temp, float humidity, float pressure) override {
        this->temperature = temp;
        this->humidity = humidity;
        display();
    }
    */

    void display() override {
        std::cout << "Current conditions: " << temperature 
                  << "F degrees and " << humidity << "% humidity" << std::endl;
    }
};

#endif
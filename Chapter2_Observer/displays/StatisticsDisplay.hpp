#ifndef STATISTICS_DISPLAY_HPP
#define STATISTICS_DISPLAY_HPP

#include <iostream>
#include <algorithm> // for std::max/min
#include "../interfaces/Observer.hpp"
#include "../interfaces/DisplayElement.hpp"
#include "../weather/WeatherData.hpp"

class StatisticsDisplay : public Observer, public DisplayElement {
private:
    float maxTemp = 0.0f;
    float minTemp = 200;
    float tempSum = 0.0f;
    int numReadings = 0;
    WeatherData* weatherData;

public:
    StatisticsDisplay(WeatherData* wd) : weatherData(wd) {
        weatherData->registerObserver(this);
    }

    void update() override {
        // PULL: We only care about Temperature here!
        float temp = weatherData->getTemperature();
        
        tempSum += temp;
        numReadings++;

        if (temp > maxTemp) maxTemp = temp;
        if (temp < minTemp) minTemp = temp;

        display();
    }

    void display() override {
        std::cout << "Avg/Max/Min temperature = " << (tempSum / numReadings)
                  << "/" << maxTemp << "/" << minTemp << std::endl;
    }
};

#endif
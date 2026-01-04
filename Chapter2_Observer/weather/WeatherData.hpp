#ifndef WEATHER_DATA_HPP
#define WEATHER_DATA_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include "../interfaces/Subject.hpp"

class WeatherData : public Subject {
private:
    std::vector<Observer*> observers;
    float temperature;
    float humidity;
    float pressure;

public:
    void registerObserver(Observer* o) override {
        observers.push_back(o);
    }

    void removeObserver(Observer* o) override {
        // Standard C++ remove-erase idiom
        observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
    }

    void notifyObservers() override {
        for (Observer* observer : observers) {
            // PULL MODEL: We just say "Hey, things changed!"
            observer->update();

            /* // PUSH MODEL (Alternative):
            // We pass the data directly.
            observer->update(temperature, humidity, pressure);
            */
        }
    }

    void measurementsChanged() {
        notifyObservers();
    }

    // Methods to simulate new weather data coming in
    void setMeasurements(float temp, float humidity, float pressure) {
        this->temperature = temp;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChanged();
    }

    // GETTERS (Crucial for the PULL Model)
    float getTemperature() const { return temperature; }
    float getHumidity() const { return humidity; }
    float getPressure() const { return pressure; }
};

#endif
#include <iostream>

// --- THE CONCRETE DISPLAYS (Tight Coupling) ---
// In the bad design, these don't implement a common Observer interface.
// They are just random classes that we have to know about explicitly.

class CurrentConditionsDisplay {
public:
    void update(float temp, float humidity, float pressure) {
        std::cout << "Current Conditions: " << temp << "F, " << humidity << "% humidity" << std::endl;
    }
};

class StatisticsDisplay {
public:
    void update(float temp, float humidity, float pressure) {
        std::cout << "Stats: " << temp << "F (We are ignoring other data)" << std::endl;
    }
};

class ForecastDisplay {
public:
    void update(float temp, float humidity, float pressure) {
        std::cout << "Forecast: " << (pressure > 29.92 ? "Sunny" : "Rain") << std::endl;
    }
};

// --- THE SUBJECT (The Trap) ---
class WeatherData {
private:
    // VIOLATION: Programming to an implementation!
    // We are locked into these specific classes.
    CurrentConditionsDisplay* currentDisplay;
    StatisticsDisplay* statisticsDisplay;
    ForecastDisplay* forecastDisplay;

    float temperature;
    float humidity;
    float pressure;

public:
    WeatherData() {
        // We have to manage these objects ourselves...
        currentDisplay = new CurrentConditionsDisplay();
        statisticsDisplay = new StatisticsDisplay();
        forecastDisplay = new ForecastDisplay();
    }

    // VIOLATION: This method handles what varies (the displays).
    // If we want to add a 4th display, we have to edit this code.
    void measurementsChanged() {
        float temp = getTemperature();
        float humidity = getHumidity();
        float pressure = getPressure();

        // THE MISTAKE:
        // We are manually updating each concrete display.
        // We cannot add/remove displays at runtime.
        currentDisplay->update(temp, humidity, pressure);
        statisticsDisplay->update(temp, humidity, pressure);
        forecastDisplay->update(temp, humidity, pressure);
    }

    void setMeasurements(float t, float h, float p) {
        this->temperature = t;
        this->humidity = h;
        this->pressure = p;
        measurementsChanged();
    }

    float getTemperature() { return temperature; }
    float getHumidity() { return humidity; }
    float getPressure() { return pressure; }
};

int main() {
    std::cout << "--- THE BAD WEATHER APP ---" << std::endl;
    WeatherData wd;
    
    // It works, BUT...
    // 1. We can't turn off the ForecastDisplay easily.
    // 2. We can't add a ThirdPartyDisplay without rewriting WeatherData.cpp.
    wd.setMeasurements(80, 65, 30.4f);

    return 0;
}
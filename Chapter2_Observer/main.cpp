#include "weather/WeatherData.hpp"
#include "displays/CurrentConditionsDisplay.hpp"
#include "displays/StatisticsDisplay.hpp"
#include "displays/ForecastDisplay.hpp"

int main() {
    // 1. Create the Subject
    WeatherData weatherData;

    // 2. Create Observers (They register themselves in their constructors)
    CurrentConditionsDisplay currentDisplay(&weatherData); 
    StatisticsDisplay statisticsDisplay(&weatherData);
    ForecastDisplay forecastDisplay(&weatherData);

    // 3. Simulate new weather measurements
    std::cout << "\n--- First Update: 80F, 65% Humidity, 30.4 Pressure ---" << std::endl;
    weatherData.setMeasurements(80, 65, 30.4f);

    std::cout << "\n--- Second Update: 82F, 70% Humidity, 29.2 Pressure ---" << std::endl;
    weatherData.setMeasurements(82, 70, 29.2f);

    std::cout << "\n--- Third Update: 78F, 90% Humidity, 29.2 Pressure ---" << std::endl;
    weatherData.setMeasurements(78, 90, 29.2f);

    return 0;
}
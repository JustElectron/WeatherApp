#include <iostream>
#include <memory>

#include "weatherapi.h"

void PrintUsage() {
    std::cout << "Usage: weatherapp <current|forecast> <city>" << std::endl;
    std::cout << "Example: weatherapp current Copenhagen" << std::endl;
    std::cout << "This will print the current weather for Copenhagen." << std::endl;
}

void PrintCurrentWeather(std::string& city) {
    WeatherApi weather_api("insert api key here");

    WeatherData weather_response = weather_api.GetCurrentWeather(city);

    // TODO: Print the weather in a nicer way
    std::cout << "Weather Response: " << weather_response.current.temperature << std::endl;

}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        PrintUsage();
        return 1;
    }

    std::string command = argv[1];
    std::string city = argv[2];

    if (command == "current" || command == "Current") {
        PrintCurrentWeather(city);
    }
    else if (command == "forecast" || command == "Forecast") {
        std::cout << "Forecast command is not implemented yet." << std::endl;
    }
    else {
        std::cout << "Unknown command: " << command << std::endl;
        PrintUsage();
        return 1;
    }

    return 0;
}
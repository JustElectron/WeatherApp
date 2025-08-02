#include <iostream>
#include <memory>

#include <restclient-cpp/restclient.h>

#include "weatherapi.h"

int main() {
    // Correct the URL
    std::unique_ptr<HttpClient> client = std::make_unique<HttpClient>("http://example.com");

    // Perform a GET request
    RestClient::Response res = client->Get("/");
    std::cout << "Welcome to WeatherApp!" << std::endl;

    std::cout << "Response: " << res.body << std::endl;

    WeatherApi weather_api("insert api key here");

    WeatherData weather_response = weather_api.GetCurrentWeather("Copenhagen");

    std::cout << "Weather Response: " << weather_response.current.temperature << std::endl;

    return 0;
}
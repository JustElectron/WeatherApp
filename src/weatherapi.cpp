#include "weatherapi.h"

#include <iostream>

WeatherApi::WeatherApi(const std::string& api_key)
    : api_key_(api_key) {
    // Initialize the HTTP client with the base URL for the weather API
    http_client_ = std::make_unique<HttpClient>("https://api.weatherstack.com");
}

WeatherApi::~WeatherApi() {
    // Destructor can be empty as unique_ptr will handle cleanup
}

WeatherData WeatherApi::GetCurrentWeather(const std::string& location) {
    // // Construct the endpoint URL with the location and API key
    // std::string endpoint = "/current?access_key=" + api_key_ + "&query=" + location;

    // RestClient::Response response = http_client_->Get(endpoint);

    // if ( response.code != 200 ) {
    //     throw std::runtime_error("Failed to fetch weather data: " + response.body);
    // }

    json weather_json = json::parse(mockJsonWeatherData);
    WeatherData weather_data = weather_json.template get<WeatherData>();

    // Make a GET request to the weather API
    return weather_data;
}
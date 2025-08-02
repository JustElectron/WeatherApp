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
    std::string jsonData = R"({
        "request": {
            "type": "City",
            "query": "Copenhagen, Denmark",
            "language": "en",
            "unit": "m"
        },
        "location": {
            "name": "Copenhagen",
            "country": "Denmark",
            "region": "Hovedstaden",
            "lat": "55.667",
            "lon": "12.583",
            "timezone_id": "Europe/Copenhagen",
            "localtime": "2025-08-02 14:20",
            "localtime_epoch": 1754144400,
            "utc_offset": "2.0"
        },
        "current": {
            "observation_time": "12:20 PM",
            "temperature": 20,
            "weather_code": 389,
            "weather_icons": [
            "https://cdn.worldweatheronline.com/images/wsymbols01_png_64/wsymbol_0024_thunderstorms.png"
            ],
            "weather_descriptions": [
            "Rain With Thunderstorm"
            ],
            "astro": {
            "sunrise": "05:18 AM",
            "sunset": "09:13 PM",
            "moonrise": "04:10 PM",
            "moonset": "11:09 PM",
            "moon_phase": "Waxing Gibbous",
            "moon_illumination": 54
            },
            "air_quality": {
            "co": "327.45",
            "no2": "10.36",
            "o3": "96",
            "so2": "0.74",
            "pm2_5": "10.915",
            "pm10": "17.39",
            "us-epa-index": "1",
            "gb-defra-index": "1"
            },
            "wind_speed": 15,
            "wind_degree": 180,
            "wind_dir": "S",
            "pressure": 1007,
            "precip": 0.7,
            "humidity": 68,
            "cloudcover": 75,
            "feelslike": 20,
            "uv_index": 5,
            "visibility": 10,
            "is_day": "yes"
        }
        })";

    json weather_json = json::parse(response.body);
    WeatherData weather_data = weather_json.template get<WeatherData>();

    // Make a GET request to the weather API
    return weather_data;
}
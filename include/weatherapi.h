#include <memory>

#include "weatherdata.h"
#include "httpclient.h"

class WeatherApi {
public:
    // Constructor
    WeatherApi(const std::string& api_key);

    // Destructor
    ~WeatherApi();

    // Method to get weather data
    WeatherData GetCurrentWeather(const std::string& location);
private:
    std::unique_ptr<HttpClient> http_client_; // HTTP client for making requests
    std::string api_key_; // API key for authentication

};
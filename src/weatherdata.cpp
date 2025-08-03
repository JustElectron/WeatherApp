#include "weatherdata.h"

#include "nlohmann/json.hpp"

using json = nlohmann::json;

std::string mockJsonWeatherData = R"({
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

// Manual mapping for AirQuality
void from_json(const json& j, AirQuality& a) {
    j.at("us-epa-index").get_to(a.us_epa_index);
    j.at("gb-defra-index").get_to(a.gb_defra_index);
}

void to_json(json& j, const AirQuality& a) {
    j = json{
        {"us-epa-index", a.us_epa_index},
        {"gb-defra-index", a.gb_defra_index}
    };
}
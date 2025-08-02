#include <string>
#include <vector>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

struct Request {
    std::string type;
    std::string query;
    std::string language;
    std::string unit;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Request, type, query, language, unit)
};

struct Location {
    std::string name;
    std::string country;
    std::string region;
    std::string lat;
    std::string lon;
    std::string timezone_id;
    std::string localtime;
    int localtime_epoch;
    std::string utc_offset;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Location, name, country, region, lat, lon, timezone_id, localtime, localtime_epoch, utc_offset)
};

struct Astro {
    std::string sunrise;
    std::string sunset;
    std::string moonrise;
    std::string moonset;
    std::string moon_phase;
    int moon_illumination;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Astro, sunrise, sunset, moonrise, moonset, moon_phase, moon_illumination)
};

struct AirQuality {
    std::string co;
    std::string no2;
    std::string o3;
    std::string so2;
    std::string pm2_5;
    std::string pm10;
    std::string us_epa_index;
    std::string gb_defra_index;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(AirQuality, co, no2, o3, so2, pm2_5, pm10)
};

struct Current {
    std::string observation_time;
    int temperature;
    int weather_code;
    std::vector<std::string> weather_icons;
    std::vector<std::string> weather_descriptions;
    Astro astro;
    AirQuality air_quality;
    int wind_speed;
    int wind_degree;
    std::string wind_dir;
    int pressure;
    double precip;
    int humidity;
    int cloudcover;
    int feelslike;
    int uv_index;
    int visibility;
    std::string is_day;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Current, observation_time, temperature, weather_code, weather_icons, weather_descriptions, astro, air_quality, wind_speed, wind_degree, wind_dir, pressure, precip, humidity, cloudcover, feelslike, uv_index, visibility, is_day)
};

struct WeatherData {
    Request request;
    Location location;
    Current current;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(WeatherData, request, location, current)
};

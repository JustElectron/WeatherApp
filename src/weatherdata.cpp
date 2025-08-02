#include "weatherdata.h"

#include "nlohmann/json.hpp"

using json = nlohmann::json;

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
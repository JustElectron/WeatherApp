cmake_minimum_required(VERSION 3.10)

# Project name and version
project(WeatherApp VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
add_executable(WeatherApp src/main.cpp src/httpclient.cpp src/weatherapi.cpp src/weatherdata.cpp)

# Include directories
target_include_directories(WeatherApp PRIVATE include)

# Add third-party libraries
add_subdirectory(3rdparty)

# Link restclient-cpp
target_link_libraries(WeatherApp PRIVATE restclient-cpp nlohmann_json::nlohmann_json)

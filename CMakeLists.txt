cmake_minimum_required(VERSION 3.10)

# Project name and version
project(WeatherApp VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
add_executable(WeatherApp src/main.cpp)

# Include directories
target_include_directories(WeatherApp PRIVATE include)

# Add third-party libraries (example: HTTP client)
add_subdirectory(3rdparty)

# Link third-party libraries (example: libcurl)
# target_link_libraries(WeatherApp PRIVATE curl)

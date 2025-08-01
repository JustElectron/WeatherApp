# WeatherApp Architecture

## Overview
WeatherApp is designed to be modular and extensible. The application uses CMake for build configuration and supports third-party libraries for additional functionality.

## Components
1. **Main Application**: Entry point (`main.cpp`).
2. **HTTP Client**: A third-party library (e.g., libcurl) for fetching weather data.
3. **Modular Design**: Separate source and header files for better organization.

## Third-Party Libraries
- **HTTP Client**: Used for making API requests to weather services.
- **Future Libraries**: Additional libraries can be added to the `3rdparty` folder.

## Build System
The project uses CMake to manage builds and dependencies. Third-party libraries are included as subdirectories and linked to the main application.

## Future Enhancements
- Add unit tests.
- Implement a configuration system for API keys and endpoints.
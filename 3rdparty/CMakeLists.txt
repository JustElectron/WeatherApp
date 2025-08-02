# Placeholder CMakeLists.txt for 3rdparty directory
# Add configurations for third-party libraries here in the future.

# Add restclient-cpp as a third-party library
add_subdirectory(restclient-cpp)
add_subdirectory(json)

# Remove this line as it is now handled in restclient-cpp's CMakeLists.txt
# target_include_directories(restclient-cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/restclient-cpp/include)

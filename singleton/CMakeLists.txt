project(Singleton)
cmake_minimum_required(VERSION 3.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(inc)

# Add source files
set(SOURCES
    src/singleton.cpp
    main.cpp
)

# Specify the executable and its sources
add_executable(Singleton ${SOURCES})

# Set the output directory to 'build'
set_target_properties(Singleton PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
)

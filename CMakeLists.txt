cmake_minimum_required(VERSION 3.16)

project(dice_roll LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files
include_directories(src)

# Add all source files
file(GLOB SOURCES "src/*.cpp")

add_executable(dice_roll ${SOURCES})
# Set minimum CMake version required to run
cmake_minimum_required(VERSION 3.2)

# Set project name + used languages
project(DivFeature C)

# Include .cmake script containing macro
include("${CMAKE_SOURCE_DIR}/feature.cmake")

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# Add source files and create the DivFeature target
file(GLOB DIV_SRC ${PROJECT_SOURCE_DIR}/src/*.c)
add_library(DivFeature STATIC ${DIV_SRC})

# Add directory path
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)

# Call macro in .cmake script depending on build argument
if (DEFINED CONFIG)
    message(STATUS "CONFIG value: ${CONFIG}")  # Debug message
    if (CONFIG STREQUAL "4") # Enable
        message(STATUS "Adding DIV Library")
        configFeature("4")
    else() # Disable
        message(STATUS "Removing DIV Library")
        configFeature(9)
    endif()
endif()

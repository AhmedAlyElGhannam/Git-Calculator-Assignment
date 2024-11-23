# Set minimum CMake version required to run
cmake_minimum_required(VERSION 3.2)

# Set project name + used languages
project(DivFeature C)

# Include .cmake script containing macro
include("${CMAKE_CURRENT_SOURCE_DIR}/../../feature.cmake")

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# Add source files and create the DivFeature target
file(GLOB DIV_SRC ${PROJECT_SOURCE_DIR}/src/*.c)
add_library(DivFeature STATIC ${DIV_SRC})

# Add directory path
# INTERFACE cuz div.c does not need div.h and will just pass it to Calculator (main.c) to use it
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)

# Call macro in .cmake script depending on build argument
if (DEFINED CONFIG)
    message(STATUS "CONFIG value: ${CONFIG}")  # Debug message
    if (CONFIG STREQUAL "4") # Enable
        message(STATUS "Adding DIV Library")
        configFeature(${PROJECT_NAME} ${CONFIG})
    else() # Disable
        message(STATUS "Removing DIV Library")
        configFeature(${PROJECT_NAME} ${CONFIG})
    endif()
endif()

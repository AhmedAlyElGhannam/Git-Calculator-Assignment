# set minimum CMake version required to run
Cmake_minimum_required(VERSION 3.2)

# set project name + used languages
project(DivFeature C)

# include .cmake script containing macro
include("${CMAKE_SOURCE_DIR}/feature.cmake")

# call macro in .cmake script depending on build argument)
if (DEFINED CONFIG)
    message(STATUS "CONFIG value: ${CONFIG}")  # debug message THAT DOES NOT EVEN SHOW ANYTHING!
    if (CONFIG STREQUAL "4") # enable
    # give an indicator message based on the passed argument when building
        message(STATUS "Adding DIV Library")
        # calling macro that edits configuration.h using config.py script
        configFeature(4)
    else() # disable
        # give an indicator message based on the passed argument when building 
        message(STATUS "Removing DIV Library")
        # calling macro that edits configuration.h using config.py script
        configFeature(9)
    endif()
endif()

# to add all .c files in src folder
file(GLOB DIV_SRC ${PROJECT_SOURCE_DIR}/src/*.c)

# to create a library out of these files
add_library(DivFeature STATIC ${DIV_SRC})

# to add directory path
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc) 

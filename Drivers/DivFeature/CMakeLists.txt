# set minimum CMake version required to run
cmake_minimum_required(VERSION 3.2)

# set project name + used languages
project(DivFeature C)

# defining environment variables to configure DivFeature
set(DIV_ON  4)
set(DIV_OFF 9)

# include .cmake script containing macro to launch .py script in order to be able to call it
include("${CMAKE_CURRENT_SOURCE_DIR}/../../feature.cmake")

# adding include directory of div.h cuz main app will need it
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# collect all .c files into one variable DIV_SRC
file(GLOB DIV_SRC ${PROJECT_SOURCE_DIR}/src/*.c)

# create a static library using DIV_SRC 
add_library(${PROJECT_NAME} STATIC ${DIV_SRC})

# Add directory path
# INTERFACE cuz div.c does not need div.h and will just pass it to Calculator (main.c) to use it
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/inc)

# include directory for configuration.h path (in main build dir aka CMAKE_BINARY_DIR)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR})

# check if there was a passed argument related to this feature
if (DEFINED DIV)
    # indicator that argument was read successfully
    message(STATUS "DIV value: ${DIV}")  
else()
    # DIV was not defined => turn off DivFeature
    set(DIV "OFF")
endif()

# configure feature by passing right value to macro
if (DIV STREQUAL "ON") # enable
    message(STATUS "Adding DIV Library")
    configFeature(${PROJECT_NAME} ${DIV_ON}) # turn feature on
elseif(DIV STREQUAL "OFF") # disable
    message(STATUS "Removing DIV Library")
    configFeature(${PROJECT_NAME} ${DIV_OFF}) # turn feature off
endif()

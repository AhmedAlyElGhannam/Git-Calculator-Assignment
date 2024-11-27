# set minimum CMake version required to run
cmake_minimum_required(VERSION 3.2)

# set project name + used languages
project(SumFeature C)

# defining environment variables to configure DivFeature
set(SUM_ON  1)
set(SUM_OFF 6)

# include .cmake script containing macro to launch .py script in order to be able to call it
include("${CMAKE_CURRENT_SOURCE_DIR}/../../feature.cmake")

# adding include directory of div.h cuz main app will need it
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# collect all .c files into one variable SUM_SRC
file(GLOB SUM_SRC ${PROJECT_SOURCE_DIR}/src/*.c)

# create a static library using SUM_SRC 
add_library(${PROJECT_NAME} STATIC ${SUM_SRC})

# Add directory path
# INTERFACE cuz div.c does not need div.h and will just pass it to Calculator (main.c) to use it
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/inc)

# include directory for configuration.h path (in main build dir aka CMAKE_BINARY_DIR)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR})

# check if there was a passed argument related to this feature
if (DEFINED SUM)
    # indicator that argument was read successfully
    message(STATUS "SUM value: ${SUM}")  
else()
    # DIV was not defined => turn off DivFeature
    set(SUM "OFF")
endif()

# configure feature by passing right value to macro
if (SUM STREQUAL "ON") # enable
    message(STATUS "Adding SUM Library")
    configFeature(${PROJECT_NAME} ${SUM_ON}) # turn feature on
elseif(SUM STREQUAL "OFF") # disable
    message(STATUS "Removing SUM Library")
    configFeature(${PROJECT_NAME} ${SUM_OFF}) # turn feature off
endif()

# set minimum CMake version required to run
cmake_minimum_required(VERSION 3.2)

# set project name + used languages
project(SubFeature C)

# defining environment variables to configure SubFeature
set(SUB_ON  2)
set(SUB_OFF 7)

# include .cmake script containing macro to launch .py script in order to be able to call it
include("${CMAKE_CURRENT_SOURCE_DIR}/../../feature.cmake")

# adding include directory of sub.h cuz main app will need it
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# collect all .c files into one variable Sub_SRC
file(GLOB Sub_SRC ${PROJECT_SOURCE_DIR}/src/*.c)

# create a static library using Sub_SRC
add_library(${PROJECT_NAME} STATIC ${Sub_SRC})

# Add directory path
# INTERFACE cuz sub.c does not need sub.h and will just pass it to Calculator (main.c) to use it
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/inc)

# include directory for configuration.h path (in main build dir aka CMAKE_BINARY_DIR)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR})

# check if there was a passed argument related to this feature
if (DEFINED SUB)
    # indicator that argument was read successfully
    message(STATUS "SUB value: ${SUB}")  
else()
    # SUB was not defined => turn off SubFeature
    set(SUB "OFF")
endif()

# configure feature by passing right value to macro
if (SUB STREQUAL "ON") # enable
    message(STATUS "Adding SUB Library")
    configFeature(${PROJECT_NAME} ${SUB_ON}) # turn feature on
elseif(SUB STREQUAL "OFF") # disable
    message(STATUS "Removing SUB Library")
    configFeature(${PROJECT_NAME} ${SUB_OFF}) # turn feature off
endif()

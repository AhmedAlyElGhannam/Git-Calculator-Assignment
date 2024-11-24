# set minimum CMake version required to run
cmake_minimum_required(VERSION 3.2)

# set project name + used languages
project(MulFeature C)

# defining environment variables to configure MulFeature
set(MUL_ON  3)
set(MUL_OFF 8)

# include .cmake script containing macro to launch .py script in order to be able to call it
include("${CMAKE_CURRENT_SOURCE_DIR}/../../feature.cmake")

# adding include directory of mul.h cuz main app will need it
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# collect all .c files into one variable MUL_SRC
file(GLOB MUL_SRC ${PROJECT_SOURCE_DIR}/src/*.c)

# create a static library using MUL_SRC 
add_library(${PROJECT_NAME} STATIC ${MUL_SRC})

# Add directory path
# INTERFACE cuz mul.c does not need mul.h and will just pass it to Calculator (main.c) to use it
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/inc)

# include directory for configuration.h path (in main build dir aka CMAKE_BINARY_DIR)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR})

# check if there was a passed argument related to MUL feature
if (DEFINED MUL)
    # indicator that argument was read successfully
    message(STATUS "MUL value: ${MUL}")  
else()
    # MUL was not defined => turn off MulFeature
    set(MUL "OFF")
endif()

# configure feature by passing right value to macro
if (MUL STREQUAL "ON") # enable
    message(STATUS "Adding MUL Library")
    configFeature(${PROJECT_NAME} ${MUL_ON}) # turn MUL feature on
elseif(MUL STREQUAL "OFF") # disable
    message(STATUS "Removing MUL Library")
    configFeature(${PROJECT_NAME} ${MUL_OFF}) # turn MUL feature off
endif()
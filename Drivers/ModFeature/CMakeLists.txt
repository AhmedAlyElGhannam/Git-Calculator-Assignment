# set minimum CMake version required to run
cmake_minimum_required(VERSION 3.2)

# set project name + used languages
project(ModFeature C)

# defining environment variables to configure ModFeature
set(MOD_ON  5)
set(MOD_OFF 0)

# include .cmake script containing macro to launch .py script in order to be able to call it
include("${CMAKE_CURRENT_SOURCE_DIR}/../../feature.cmake")

# adding include directory of mod.h because main app will need it
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# collect all .c files into one variable MOD_SRC
file(GLOB MOD_SRC ${PROJECT_SOURCE_DIR}/src/*.c)

# create a static library using MOD_SRC
add_library(${PROJECT_NAME} STATIC ${MOD_SRC})

# Add directory path
# INTERFACE because mod.c does not need mod.h and will just pass it to Calculator (main.c) to use it
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/inc)

# include directory for configuration.h path (in main build dir aka CMAKE_BINARY_DIR)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR})

# check if there was a passed argument related to this feature
if (DEFINED MOD)
    # indicator that argument was read successfully
    message(STATUS "MOD value: ${MOD}")  
else()
    # MOD was not defined => turn off ModFeature
    set(MOD "OFF")
endif()

# configure feature by passing right value to macro
if (MOD STREQUAL "ON") # enable
    message(STATUS "Adding MOD Library")
    configFeature(${PROJECT_NAME} ${MOD_ON}) # turn feature on
elseif(MOD STREQUAL "OFF") # disable
    message(STATUS "Removing MOD Library")
    configFeature(${PROJECT_NAME} ${MOD_OFF}) # turn feature off
endif()

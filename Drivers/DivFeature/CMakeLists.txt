# set minimum CMake version required to run
Cmake_minimum_required(VERSION 3.2)

# set project name + used languages
project(DivFeature C)

# to add directory path 

# to add all .c files in src folder
file(GLOB DIV_SRC ${PROJECT_SOURCE_DIR}/src/*.c)

# to create a library out of these files
add_library(DivFeature STATIC ${DIV_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc) 
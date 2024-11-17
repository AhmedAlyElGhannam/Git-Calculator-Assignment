# set minimum CMake version required to run
Cmake_minimum_required(VERSION 3.2)

# set project name + used languages
project(SumFeature C)

# to add directory path 
include_directories(${PROJECT_SOURCE_DIR}/inc) 

# to add all .c files in src folder
file(GLOB SUM_SRC ${PROJECT_SOURCE_DIR}/src/*.c)

# to create a library out of these files
add_library(sum STATIC ${SUM_SRC})


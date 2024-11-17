#set miinimun CMake version required to run
Cmake_minimum_required(VERSION 3.2)

#set project name + used languages
project(MulFeature C) 

#to add directory path
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/inc)

#to add all .c files iin scr folder
file(GLOB MUL_SRC ${PROJECT_SOURCE_DIR}/src/*.c)

#to create a library out of these files
add_library(Mul_Library STATIC ${MUL_SRC})

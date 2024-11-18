CMAKE_MINIMUM_REQUIRED(VERSION 3.2) 

# set project name + used languages
project(ModFeature C)

# to add directory path 
include_directories(${PROJECT_SOURCE_DIR}/inc) 

# to add all .c files in src folder
file(GLOB MOD_SRC ${PROJECT_SOURCE_DIR}/src/*.c)

# to create a library out of these files
add_library(ModFeature STATIC ${MOD_SRC})
# set minimum CMake version required to run
cmake_minimum_required(VERSION 3.10)

# set project name + used languages
project(MyProject VERSION 1.0 LANGUAGES C)

# Set output directories for compiled libraries and executables
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add SubFeature as a subdirectory, which has its own CMakeLists.txt
add_subdirectory(SubFeature)

# Add the include directory for SubFeature headers
include_directories(${PROJECT_SOURCE_DIR}/SubFeature/inc)

# Add the executable from main.c
add_executable(main_exec main.c)

# Link the executable with the library from SubFeature
target_link_libraries(main_exec PRIVATE mylibrary)







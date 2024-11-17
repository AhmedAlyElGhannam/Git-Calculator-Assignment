#Cmake_minimum_required(3.2)
project(myapp C ASM CXX) 
set(C-SOURCE main.c)
add_executable(${PROJECT_NAME} main.c)
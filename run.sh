#!/bin/bash

# run cmake command for main project
cmake -S . -B build

# change directory to build
cd build

# run make
make

# run executable
./Calculator

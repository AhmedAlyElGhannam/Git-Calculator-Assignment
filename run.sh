#!/bin/bash

# function to display usage
usage() {
    echo "Usage: $0 {all|none|div_on|div_off|clean|launch}"
}

# function to display all options if no arguments are passed
show_options() {
    echo "Available options:"
    echo "  all       - add all features from product"
    echo "  none      - removes all features from product"
    echo "  div_on    - enables div feature only"
    echo "  div_off   - disables div feature only"
    echo "  clean     - removes build directory to do a clean build"
    echo "  launch    - launches the app after building is done"
}

# check if an argument is passed
if [ $# -ne 1 ]; then
    show_options
    usage
    return 1  # Use return instead of exit to avoid terminating the shell
fi

# get the command argument
command=$1

# define the commands for each rule
case "$command" in
    all) # add all features from product
        cmake -S . -B build -DADD=ON -DSUB=ON -DMUL=ON -DDIV=ON -DMOD=ON
        cmake --build build
        ;;
    none) # removes all features from products
        cmake -S . -B build -DADD=OFF -DSUB=OFF -DMUL=OFF -DDIV=OFF -DMOD=OFF
        cmake --build build
        ;;
    div_on) # enables div feature only
        cmake -S . -B build -DADD=OFF -DSUB=OFF -DMUL=OFF -DDIV=ON -DMOD=OFF
        cmake --build build
        ;;
    div_off) # disables div feature only
        cmake -S . -B build -DADD=ON -DSUB=ON -DMUL=ON -DDIV=OFF -DMOD=ON
        cmake --build build
        ;;
    clean) # removes build directory to do a clean build
        rm -r build
        ;;
    launch) # launches the app after building is done
        if [ -f "./build/Calculator" ]; then
            ./build/Calculator
        else
            echo "Error: Application not found. Please build the project first."
        fi
        ;;
    *)
        usage
        return 1  # Use return instead of exit
        ;;
esac

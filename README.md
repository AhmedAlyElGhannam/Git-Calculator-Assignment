# Git-Gud

## Introduction
>A simple calculator project with the aim of learning how to utilize Git in managing a multi-contributor project and making use of CMake in building different modules and linking them together. This repository was created as means of practising the knowledge acquired from Git && CMake Courses taught by our brilliant instructor [Eng. Fady Khalil](https://github.com/FadyKhalil). 

## About The Team
We are ITI 9-Month Scholarship Alumini in Embedded Systems Track: 
* [Yasmeen Yasser](https://github.com/YasmeenYasser611)
* [Ahmed Ali](https://github.com/AhmedAlyElGhannam)
* [Ali El-Mansoury](https://github.com/Ali-Elmansoury)
* [Aliaa Mortada](https://github.com/aliaamortada)
* [Mariam Hossam](https://github.com/Mariam-Hossam-Saleh)

## Using The App
There are two ways to launch the app---both can be found in the project's root directory:
1. Using the `MakeFile`.
2. Using the 'run.sh' bash script.

### Makefile
Makefiles are such simple yet marvelous tools: by just typing `make` and pressing `tab` you can see all the available build rules.

### Bash Script
This script performs the exact same function as the `Makefile`; I just wanted to refresh my memory on how to write bash scripts. By sourcing the bash script with no arguments 
```bash
source run.sh
```
all the options can be seen.
```bash
Available options:
  all       - add all features from product
  none      - removes all features from product
  div_on    - enables div feature only
  div_off   - disables div feature only
  mul_on    - enables mul feature only
  mul_off   - disables mul feature only
  sub_on    - enables sub feature only
  sub_off   - disables sub feature only
  mod_on    - enables mod feature only
  mod_off   - disables mod feature only
  add_on    - enables add feature only
  add_off   - disables add feature only
  clean     - removes build directory to do a clean build
  launch    - launches the app after building is done
```

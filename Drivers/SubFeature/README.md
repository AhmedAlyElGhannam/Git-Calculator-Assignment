# Hello to Sub Feature Documentation :)
# What is the Sub Feature?
>Subtraction is one of the basic arithmetic operations. It involves taking one number (the subtrahend) away from another number (the minuend). The result of subtraction is called the difference.

For example: In the equation
```
8 - 3 = 5
```
8 is the minuend, 3 is the subtrahend, and 5 is the difference.

# Breakdown of what each line in the driver `SUB_FEATUE.c` do.
```c
#include "Sub_Feature.h"

```
* `#include "Sub_Feature.h"`: This line tells the preprocessor to include the contents of the `Sub_Feature.h` header file.This allows the compiler to recognize functions or variables that are defined elsewhere in the project.

```c
float subtract(float a, float b)
{
    return a - b;
}
```
* Parameters:
	* The function subtract accepts two arguments, a and b, which are both of type float. This means that the function is designed to work with floating-point numbers (numbers that may have decimals).
* Subtraction:
	* Inside the function, it simply subtracts `b` from `a` using the `-` operator.
* Return Value:
	* The result of the subtraction (a floating-point number) is returned to the caller.
# Example Usage:
If you call this function like so:
```c
float result = subtract(10.5, 3.2);

```
The function will subtract `3.2` from `10.5` and return `7.3` (i.e., `10.5 - 3.2 = 7.3`).

if you want to read more about the subtractin check this [Subtraction](https://www.mathsisfun.com/numbers/subtraction.html).

# CMakeLists.txt explanation
>this file is used to configure a CMake project that will build a static library from source files in a directory`SUB_FEATUE.c`. Here is a detailed explanation of each line:
```
CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
```
This line specifies the minimum version of CMake that is required to configure and build the project. In this case, the minimum version is 3.2. This ensures that the features and syntax used in the CMakeLists.txt file are compatible with CMake version 3.2 or later.
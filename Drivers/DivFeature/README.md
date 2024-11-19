# Division Feature Driver

*taps code* this baby can perform division operations while avoiding `divide by zero exception`. The C code is compiled and converted into a static library using CMake.

## C Code

The code is divided into a single source file and a single header file---each is located in the folders `src` and `inc` respectively.

```c
#ifndef DIV_H
#define DIV_H

float divide(float a, float b);

#endif
```

The header file contains a guard to prevent multiple inclusions and the division function prototype. 


```c
#include "div.h"

float divide(float a, float b)
{
	if (b == 0)
		return 0.0;
	return (a / b);
}
```

The function is simple enough: it either returns `0.0` if the 2nd argument is zero to avoid division by zero, or returns the result of dividing the two arguments.

## CMakeLists File

CMake, a powerful tool used to generate top-tier Makefiles, is used to build the static library for division. 

```cmake
# set minimum CMake version required to run
Cmake_minimum_required(VERSION 3.2)

# set project name + used languages
project(DivFeature C)

# to add directory path 
include_directories(${PROJECT_SOURCE_DIR}/inc) 

# to add all .c files in src folder
file(GLOB DIV_SRC ${PROJECT_SOURCE_DIR}/src/*.c)

# to create a library out of these files
add_library(DivFeature STATIC ${DIV_SRC})
```

> Cmake_minimum_required(VERSION 3.2)

This line is used to determine the minimum version of CMake required in order to run this file.

> project(DivFeature C)

This line is used to set the project's name and programming languages used. Here, `C` was written to indicate the used programming language is C.

> include_directories(${PROJECT_SOURCE_DIR}/inc) 

This command is used to pass the inserted include directory to the compiler with the flag `-I` in the generated Makefile. 

> file(GLOB DIV_SRC ${PROJECT_SOURCE_DIR}/src/*.c)

This command collects all the `.c` files in the folder `src` and passes them to the compiler in the Makefile.

> add_library(DivFeature STATIC ${DIV_SRC})

The final line is used to create a static library out of the compiled files. 

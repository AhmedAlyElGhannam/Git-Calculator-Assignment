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

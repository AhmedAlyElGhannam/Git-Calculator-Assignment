<!--  -->
# Multiplication Feature Library ✖️

## 📜Table of Contents

- [Description](#description)
- [Source Code](#source-code-)
- [Header file](#header-file-)
- [Example of Usage](#example-of-usage-)

##  📖 Description

This folder contains the implementation of the **Multiplication** feature in our calculator project. The feature is designed to take two inputs and return their multiplication.


### Header File :

```c
/****************    Header File Guard    ****************/
#ifndef MUL_H
#define MUL_H
/***************    Functioon Prototype    ***************/
double multiply(float a, float b);

#endif // MUL_H 
```

### Source Code :

```c
#include <stdio.h>
#include "Mul.h"
/***************    Function Implementation    ***************/
double multiply(float a, float b)
{
	return (a * b);
}
```

### 📚 Example of Usage :

```c
int main(void)
{
    int num1 = 5, num2 = 4, result;
    result = multiply(num1,num2);
    /* Output : result = 20 */ 
}
```


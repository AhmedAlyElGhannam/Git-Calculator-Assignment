# Modulus Operation Feature

This feature is a simple feature that allows you to perform a modulus operation on a number. The modulus operation is the __remainder__ of a __division operation__. For example, `5` divided by `2` is `2` with a remainder of `1`. The modulus operation of `5` divided by `2` is `1`.

## Usage
---

To use this feature, you need to call the `mod` function and pass in two arguments. The first argument is the number you want to perform the modulus operation on, and the second argument is the number you want to divide the first number by.

```c
int Modulus(int a, int b)
{
	if (b == 0)
		return 0;

	return (a % b);
}
```

The `mod` function will return the remainder of the division operation.

## Example
---

```c
#include <stdio.h>
#include "mod.h"

int main()
{
    int a = 5;
    int b = 2;

    int result = Modulus(a, b);

    printf("The modulus of %d divided by %d is %d\n", a, b, result);

    return 0;
}
```

This will output:

```
The modulus of 5 divided by 2 is 1
```

## License

This project is for educational purposes only and is not intended for commercial use.

---

*Developed by Eng. Ali Mohamed Ali Elmansoury as part of the ITI Embedded Systems Track.*
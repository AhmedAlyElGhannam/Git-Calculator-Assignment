# Modulus Operation Feature  

The **ModFeature** is a library that provides functionality for performing the **modulus operation** (remainder calculation) on two integers. The modulus operation computes the remainder after dividing one number by another. For example, `5` divided by `2` equals `2` with a remainder of `1`, so the modulus operation result is `1`.  

---

## Usage  

To use this feature, include the `mod.h` header file and link the library. Then, call the `Modulus` function, passing two integer arguments:  
- **First argument**: The number you want to divide (dividend).  
- **Second argument**: The number you want to divide by (divisor).  

```c
int Modulus(int a, int b)
{
    if (b == 0)
        return 0;

    return (a % b);
}
```

The `Modulus` function will return the remainder of the division operation. If the divisor is `0`, the function will return `0` to avoid division errors.

---

## Example  

Here is an example usage of the `ModFeature`:

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

### Output:
```
The modulus of 5 divided by 2 is 1
```

---

## Configuration  

The `ModFeature` can be enabled or disabled using CMake configuration options:

- **Enable the feature**:  
  Pass `-DMOD=ON` during the CMake build process to include the ModFeature.

  Example:
  ```bash
  cmake -DMOD=ON ..
  ```

- **Disable the feature**:  
  Pass `-DMOD=OFF` to exclude the ModFeature.

  Example:
  ```bash
  cmake -DMOD=OFF ..
  ```

---

## License  

This project is for educational purposes only and is not intended for commercial use.

---

*Developed by Eng. Ali Mohamed Ali Elmansoury as part of the ITI Embedded Systems Track.*  

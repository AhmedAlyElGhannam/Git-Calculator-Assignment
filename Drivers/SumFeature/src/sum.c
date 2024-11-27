#include <stdio.h>
#include "configuration.h"

#ifdef ADD
float add(float a, float b)
{
	return a + b;
}

#else

float add(float a, float b)
{
	printf("Purchase Feature to Unlock!\n");
	printf("Press CTRL + C to Exit The Program and Launch It Again\n");
	while(1);
}
#endif
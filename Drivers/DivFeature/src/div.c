#include "div.h"
#include "configuration.h"
#include <stdio.h>

#ifdef DIV
float divide(float a, float b)
{
	if (b == 0)
		return 0.0;
	return (a / b);
}
#else
float divide(float a, float b)
{
	printf("Purchase Feature to Unlock!\n");
}
#endif

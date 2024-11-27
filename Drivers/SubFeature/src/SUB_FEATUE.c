#include "configuration.h"
#include <stdio.h>

#ifdef SUB
float subtract(float a, float b)
{
	
	return a-b ;
}
#else
float subtract(float a, float b)
{
	printf("Purchase Feature to Unlock!\n");
	printf("Press CTRL + C to Exit The Program and Launch It Again\n");
	while(1);
}
#endif

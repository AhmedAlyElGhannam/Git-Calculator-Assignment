#include <stdio.h>
#include <stdlib.h>

float add(float a, float b);
float subtract(float a, float b);
double multiply(float a, float b);
float divide(float a, float b);

int main(void)
{
	printf("Sum = %.2f",add(2.5,3));
	return 1;
}
float add(float a, float b)
{
	return a + b;
}
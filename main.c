#include <stdio.h>
#include <stdlib.h>

float add(float a, float b);
float subtract(float a, float b);
double multiply(float a, float b);
float divide(float a, float b);

int main(void)
{
	printf("Sum = %.2f",add(2.5,3));
	printf("Dividing 9.9 over 6.2 yields %f\n", divide(9.9, 6.2));
	return 1;
}

float divide(float a, float b)
{
	if (b == 0)
		return 0.0;

	return (a / b);
}

float add(float a, float b)
{
	return a + b;
}


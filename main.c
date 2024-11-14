#include <stdio.h>
#include <stdlib.h>

float add(float a, float b);
float subtract(float a, float b);
double multiply(float a, float b);
float divide(float a, float b);
int Modulus(int a, int b);

int main(void)
{
	printf("8 Mod 3 = %d\n", Modulus(8, 3));
	return 1;
}

float divide(float a, float b)
{
	if (b == 0)
		return 0.0;

	return (a / b);
}

int Modulus(int a, int b)
{
	if (b == 0)
		return 0;

	return (a % b);
}
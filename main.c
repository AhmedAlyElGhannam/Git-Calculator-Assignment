#include <stdio.h>
#include <stdlib.h>

float add(float a, float b);
float subtract(float a, float b);
double multiply(float a, float b);
float divide(float a, float b);

int main(void)
{
	float num1, num2;
	printf("please enter 2 numbers:");
    scanf(" %f", &num1);	
	scanf(" %f", &num2);
	printf("the sub of the 2 numbers is =%f", subtract(num1 , num2));
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


float subtract(float a, float b)
{
	return a-b ;
}

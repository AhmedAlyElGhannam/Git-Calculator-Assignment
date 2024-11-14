#include <stdio.h>
#include <stdlib.h>

float add(float a, float b);
float subtract(float a, float b);
double multiply(float a, float b);
float divide(float a, float b);

int main(void)
{
	float num1,num2;
	printf("Please enter number1 : \n");
	scanf(" %f",&num1);
	printf("Please enter number2 : \n");
	scanf(" %f",&num2);
	printf("Multiply : \n %0.2f * %0.2f = %0.2lf",num1,num2,multiply(num1,num2));
	return 1;
}

double multiply(float a, float b)
{
	return (a * b);
}
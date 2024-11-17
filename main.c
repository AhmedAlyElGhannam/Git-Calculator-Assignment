#include <stdio.h>
#include <stdlib.h>
#include "sum.h"


float subtract(float a, float b);
double multiply(float a, float b);
float divide(float a, float b);
int Modulus(int a, int b);

int main(void)
{
	int op ;
	int flag =0 ;
	float num1, num2;
	printf("*****welcome Group2 calculator*******\n");
	do
	{
	printf("please choose the disired operation code from the menu\n");
    printf("1 for addation '+'\n");
    printf("2 for subtract '-'\n");
    printf("3 for multiplication '*'\n");
    printf("4 for division '/'\n");	
	printf("5 for Modulus %% \n");
	printf("your choise: ");
	scanf(" %d", &op);
	printf("please enter the first operand :");
	scanf(" %f", &num1);
	printf("please enter the second operand :");
	scanf(" %f", &num2);
	switch(op)
	{
		case 1:
		           printf("Addation operation:\n");
		           printf("%0.2f + %0.2f = %0.2f\n",num1 , num2 , add(num1 , num2));
				   break;
		case 2:
		           printf("subtraction operation:\n");
		           printf("%0.2f - %0.2f = %0.2f\n",num1 , num2 , subtract(num1 , num2));
				   break;
		case 3:
		           printf("multiplication operation:\n");
		           printf("%0.2f x %0.2f = %0.2lf\n",num1 , num2 , multiply(num1 , num2));
				   break;
		case 4:
		           printf("division operation:\n");
		           printf("%0.2f / %0.2f = %0.2f\n",num1 , num2 , divide(num1 , num2));
				   break;
		case 5:
		           printf("Modulus operation:\n");
		           printf("%d %% %d = %d\n",(int)num1 , (int)num2 , Modulus((int)num1 , (int)num2));
				   break;
	    default :
		            printf("wrong choice !!!!!!!!!!!\n");
	}
	printf("thank you for using our calculator ;) \n");
	printf("if you want to make another operation please press 0 , and if not press any other key \n");
	printf("your choise: ");
	scanf(" %d", &flag);
}while(flag ==0);
    printf("\nGood BYE  !!!!!!!!!!:)\n");
	printf("Come again !!!!!!!!!!:)\n");
	
	return 1;
}

float divide(float a, float b)
{
	if (b == 0)
		return 0.0;

	return (a / b);
}


float subtract(float a, float b)
{
	
	return a-b ;
}

int Modulus(int a, int b)
{
	if (b == 0)
		return 0;

	return (a % b);
}

double multiply(float a, float b)
{
	return (a * b);
}
#include <stdio.h>
#include <stdlib.h>
#include "Mod.h"
#include "Sub_Feature.h"
#include "sum.h"
#include "Mul.h"
#include "div.h"

typedef enum
{
	ADD = 1,
	SUB = 2,
	MUL = 3,
	DIV = 4,
	MOD = 5
} OPERATIONS;

typedef enum
{
	true = 1,
	false = 0
} bool;

int main(void)
{
	int op;
	int flag = false;
	float num1, num2;
	
	printf("*******Welcome to Group 2's Simple Calculator App*******\n");
	
	do
	{
		printf("Please choose the desired operation code from the menu:\n");
    	printf("1. Addition '+'.\n");
    	printf("2. Subtraction '-'.\n");
    	printf("3. Multiplication '*'.\n");
    	printf("4. Division '/'.\n");	
		printf("5. Modulus %%.\n");
		printf("Please enter the number corresponding to the operation: ");
		scanf(" %d", &op);
		printf("Please enter the first operand: ");
		scanf(" %f", &num1);
		printf("Please enter the second operand: ");
		scanf(" %f", &num2);
		switch(op)
		{
			case ADD:
			    printf("Addition Operation:\n");
			    printf("%0.2f + %0.2f = %0.2f\n",num1 , num2 , add(num1 , num2));
			break;

			case SUB:
			    printf("Subtraction Operation:\n");
			    printf("%0.2f - %0.2f = %0.2f\n",num1 , num2 , subtract(num1 , num2));
			break;

			case MUL:
			    printf("Multiplication Operation:\n");
			    printf("%0.2f x %0.2f = %0.2lf\n",num1 , num2 , multiply(num1 , num2));
		    break;

			case DIV:
				printf("Division Operation:\n");
			    printf("%0.2f / %0.2f = %0.2f\n",num1 , num2 , divide(num1 , num2));
			break;

			case MOD:
			    printf("Modulus Operation:\n");
			    printf("%d %% %d = %d\n",(int)num1 , (int)num2 , Modulus((int)num1 , (int)num2));
		    break;

		    default:
			    printf("Wrong choice !!!!!!!!!!!\n");
		}

		printf("Thank you for using our Calculator ;) \n");
		printf("If you want to make another operation, Please press 0. and If you don't, enter any number apart from 0. \n");
		printf("Please enter your choice: ");
		scanf(" %d", &flag);
		
	} while (flag == false);

    printf("\nGood BYE  !!!!!!!!!! :)\n");
	printf("Come again !!!!!!!!!! :)\n");
	
	return 1;
}


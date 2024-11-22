#include <stdio.h>
#include <stdlib.h>
#include "Mod.h"
#include "Sub_Feature.h"
#include "sum.h"
#include "Mul.h"
#include "div.h"


int main(void)
{
	int op ;
	int flag =0 ;
	float num1, num2;
	printf("*****Welcome to Group2 Simple Calculator App*******\n");
	do
	{
	printf("Please choose the desired operation code from the menu:\n");
    printf("1. Addation '+'\n");
    printf("2. Subtarction '-'\n");
    printf("3. Multiplication '*'\n");
    printf("4. Division '/'\n");	
	printf("5 Modulus %% \n");
	printf("Please enter your choice: ");
	scanf(" %d", &op);
	printf("Please enter the first operand :");
	scanf(" %f", &num1);
	printf("Please enter the second operand :");
	scanf(" %f", &num2);
	switch(op)
	{
		#ifdef ADD
		case 1:
		           printf("Addation Operation:\n");
		           printf("%0.2f + %0.2f = %0.2f\n",num1 , num2 , add(num1 , num2));
				   break;
		#endif
		case 2:
		           printf("Subtraction Operation:\n");
		           printf("%0.2f - %0.2f = %0.2f\n",num1 , num2 , subtract(num1 , num2));
				   break;
		case 3:
		           printf("Multiplication Operation:\n");
		           printf("%0.2f x %0.2f = %0.2lf\n",num1 , num2 , multiply(num1 , num2));
				   break;
		case 4:
			#ifdef DIV           
				printf("Division Operation:\n");
		        printf("%0.2f / %0.2f = %0.2f\n",num1 , num2 , divide(num1 , num2));
				break;
			#else
				printf("Please Purchase Feature To Unlock!\n");
			#endif
		case 5:
		           printf("Modulus Operation:\n");
		           printf("%d %% %d = %d\n",(int)num1 , (int)num2 , Modulus((int)num1 , (int)num2));
				   break;
	    default :
		            printf("Wrong choice !!!!!!!!!!!\n");
	}
	printf("Thank you for using our Calculator ;) \n");
	printf("If you want to make another operation, Please press 0. and If you don't, press any other key \n");
	printf("Please enter your choice: ");
	scanf(" %d", &flag);
}while(flag ==0);
    printf("\nGood BYE  !!!!!!!!!!:)\n");
	printf("Come again !!!!!!!!!!:)\n");
	
	return 1;
}


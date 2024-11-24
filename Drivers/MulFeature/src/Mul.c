/*
 *  File   :  Mul.c
 *  Date   :  Nov 17, 2024
 *  Author :  Mariam Hossam
 */
 
#include "configuration.h"
 
#ifdef MUL
/***************    Function Implementation    ***************/
double multiply(float a, float b)
{
	return (a * b);
}
#else
double multiply(float a, float b)
{
	printf("Purchase Multiplication Feature to Unlock!\n");
	printf("Press CTRL + C to Exit The Program and Launch It Again\n");
	while(1);
}
#endif
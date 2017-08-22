#include<string.h>
#include<math.h>
#include<stdio.h>
#include"calculator.h" 
void func(char s[])
{
	double op2;
	if(!strcmp(s,"sin"))
	{
		push(sin(pop()));
	}
	else if(!strcmp(s,"exp"))
	{
		push(exp(pop()));
	}
	else if(!strcmp(s,"pow"))
	{
		op2 = pop();
		push(pow(pop(),op2));
	}
	else
		printf("error:unknown func name\n");
}

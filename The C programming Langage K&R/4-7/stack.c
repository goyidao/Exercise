#include"calculator.h"
#include<stdio.h>
#define MAX 100

double val[MAX];//操作数栈 
int sp = 0;//栈顶指针，指向下一个空位

void push(double operand)
{
	if(sp < MAX)
		val[sp++] = operand;
	else
		printf("error:stack full,can not push %g\n",operand);
}
double pop()
{
	if(sp > 0)
		return val[--sp];
	else
		printf("error:stack empty,can not pop\n");
}
void printtop()
{
	if(sp > 0)
		printf("%g\n",val[sp - 1]);
	else
		printf("error:stack empty,can not print top element\n");
}
double gettop()
{
	if(sp > 0)
		return val[sp - 1];
	else
		printf("error:stack empty,can not get top element\n");
}
void swaptop()
{
	double temp;
	if(sp > 1)
	{
		temp = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = temp;
	}
	else
		printf("error:stack can not swap\n");
}
void clearstack()
{
	while(sp > 0)
		val[--sp] = '\0';
}
int isempty()
{
	return sp > 0 ? 0:1;
}

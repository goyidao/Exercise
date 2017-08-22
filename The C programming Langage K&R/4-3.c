#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXOP 20
#define NUMBER 0
#define MAX 100

double val[MAX];//操作数栈 
int sp = 0;//栈顶指针，指向下一个空位
int buffer = -1;//存一个字符 

int getop(char s[]);//从输入取操作数或者操作符
void push(double operand);//压栈
double pop();//弹站 
int getch();//buffer不等于-1就从buffer取，否则getchar() 
void ungetch(int c);//向buffer里边存数 

main()
{
	char s[MAXOP];
	int type;
	double operand;
	
	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
				operand = atof(s);
				push(operand);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				operand = pop();
				push(pop() - operand);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				operand = pop();
				push(pop() - operand);
				break;
			case '\n':
				printf("\n%.6g\n",pop());
				break;
			default:
				printf("error:unknown command%s\n",s);
				break;
		}
	}
	return 0;
}
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
int getop(char s[])
{
	int c;
	int i = 0;
	
	while((c = getch()) == ' ' || c == '\t');
	if(isdigit(c) || c == '.')//说明是操作数
	{
		s[i++] = c;
		while(isdigit(c = getch()) || c == '.')
		{
			s[i++] = c;
		}
		s[i] = '\0'; 
		if(c != EOF)
			ungetch(c);
		return NUMBER;
	}
	else//说明是操作符或者非法字符 
	{
		s[0] = c;
		s[1] = '\0';
		return c;
	} 
}
int getch()
{
	int temp;
	if(buffer == -1)
		return getchar();
	else
	{
		temp = buffer;
		buffer = -1;
		return temp;
	}
}
void ungetch(int c)
{
	if(buffer != -1)
		printf("error:buffer full,can not ungetch%c\n",c);
	else
		buffer = c;
}

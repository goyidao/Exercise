#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXOP 20
#define NUMBER 0
#define MAX 100

double val[MAX];//������ջ 
int sp = 0;//ջ��ָ�룬ָ����һ����λ
int buffer = -1;//��һ���ַ� 

int getop(char s[]);//������ȡ���������߲�����
void push(double operand);//ѹջ
double pop();//��վ 
int getch();//buffer������-1�ʹ�bufferȡ������getchar() 
void ungetch(int c);//��buffer��ߴ��� 

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
	if(isdigit(c) || c == '.')//˵���ǲ�����
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
	else//˵���ǲ��������߷Ƿ��ַ� 
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

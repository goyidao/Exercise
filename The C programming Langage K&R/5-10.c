#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXBUF 100
int buf[MAXBUF];
int p = 0;
void push(int i);
int pop();
int main(int argc,char *argv[])
{
	while(--argc > 0)
	{
		char *t = *++argv;
		int op2;
		if(isdigit(t[0]) || (t[0] == '-' && isdigit(t[1])))
			push(atoi(t));
		else
		{
			switch(t[0])
			{
				case '+':
					push(pop() + pop());
					break;
				case '-':
					op2 = pop();
					push(pop() - op2);
					break;
				case '*':
					push(pop() * pop());
					break;
				case '/':
					op2 = pop();
					push(pop() / op2);
					break;
				default:
					printf("error:unknown command.\n");
					break;
			}
		}
	}
	printf("%d\n",pop());
	return 0;
}
void push(int i)
{
	if(p < 100)
		buf[p++] = i;
	else
		printf("error:stack full.\n");
}
int pop()
{
	if(p > 0)
		return buf[--p];
	else
		printf("error:stack empty.\n"); 
}

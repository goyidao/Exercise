#include<ctype.h>
#include<stdlib.h>
#include"calculator.h"
#include<stdio.h>
int comp(int op1,int op2);
int to_rpn(int op[],int lim)//返回操作数和操作符的总个数 
{
	SqStack stack;
	int type;
	char s[MAXWORD];
	int opnum;
	
	opnum = 0;
	InitStack(&stack);
	
	while((type = getop(s)) != EOF)
	{
		if(opnum < lim)
		{
			if(type == '\n')
			{
				while(!IsEmpty(stack))
				{
					pop(&stack,op+opnum);
					opnum++;
				}
				return opnum;
			}
			if(type == NUMBER)
			{
				op[opnum++] = atoi(s);
				//printf("op[opnum++] = atoi(s);...%d\n",op[opnum-1]);
			}
			else if(type == '(')
				push(&stack,'(');
			else if(type == ')')
			{
				int e;
				for(;GetTop(stack,&e) != ERROR && e != '(';opnum++)
					pop(&stack,op+opnum);
				pop(&stack,&e);//左括号弹栈 
			}
			else if(type == OPERATOR)
			{
				int e;
				for(;GetTop(stack,&e) != ERROR && comp(e,s[0]) >= 0;opnum++) 
					pop(&stack,op+opnum);
				push(&stack,s[0]);
			}
			else
				printf("error:unknown command.\n"); 
		}
		else
		{
			printf("error:MAXOP is %d\n",MAXOP);
			break;
		}
	}
}
int comp(int op1,int op2)
{
	switch(op1)
	{
		case '+':
		case '-':
			if(op2 == '(')
				return 1;
			else if(op2 == '-' || op2 == '+')
				return 0;
			else
				return -1;
		case '*':
		case '/':
			if(op2 == '(')
				return 1;
			else if(op2 == '*' || op2 == '/')
				return 0;
			else
				return 1;
		case '(':
			return -1;
	}
}

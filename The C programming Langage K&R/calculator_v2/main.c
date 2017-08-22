#include<stdio.h>
#include"calculator.h"
int main()
{
	SqStack stack;
	int op[MAXOP];
	int opnum,i;
	int op1,op2;
	int result;
	
	InitStack(&stack);
	while(1)
	{
		opnum = to_rpn(op,MAXOP);
		for(i = 0;i < opnum;++i)
		{
			if(op[i] == '+')
			{
				pop(&stack,&op2);
				pop(&stack,&op1);
				push(&stack,op1+op2);
			}
			else if(op[i] == '-')
			{
				pop(&stack,&op2);
				pop(&stack,&op1);
				push(&stack,op1-op2);
			}
			else if(op[i] == '*')
			{
				pop(&stack,&op2);
				pop(&stack,&op1);
				push(&stack,op1*op2);
			}
			else if(op[i] == '/')
			{
				pop(&stack,&op2);
				pop(&stack,&op1);
				push(&stack,op1/op2);
			}
			else//op[i]ÊÇÊý×Ö 
			{
				push(&stack,op[i]);
			}
		}
		pop(&stack,&result);
		printf("%d\n",result);
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h> //atof
#include<math.h> //fmod
#include"calculator.h"
#define MAXOP 20

int main()
{
	char s[MAXOP];
	int type;
	double operand;
	int varindex = -1;
	double vararr[26];
	
	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
				operand = atof(s);
				push(operand);
				break;
			case NAME:
				func(s);
				break;
			case '=':
				vararr[varindex] = pop();
				pop();
				push(vararr[varindex]);
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
			case '%':
				operand = pop();
				push(fmod(pop(),operand));
				break;
			case '\n':
				vararr['v'-'a'] = pop();
				printf("%.6g\n",vararr['v'-'a']);//变量v存放最近打印的值 
				break;
			default:
				if(type >= 'a' && type <= 'z')
				{
					varindex = type - 'a';
					push(vararr[varindex]);
				}
				else
					printf("error:unknown command%s\n",s);
				break;
		}
	}
	return 0;
}

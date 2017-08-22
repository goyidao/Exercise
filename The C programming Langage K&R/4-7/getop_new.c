#include<ctype.h> // isdigit 
#include"calculator.h"
#include<stdio.h>//EOF
#include<string.h>

#define MAXLINESIZE 100

char line[MAXLINESIZE];
int pos = 0;

int getop(char s[]) //从line[]中取操作数或者操作符放到s[]中 
{
	int c;
	int i;
	
	i = 0;
	if(line[pos] == '\0') //判断 line[]是否读完 
	{
		if(getline(line,MAXLINESIZE) == 0)
			return EOF;
		else
			pos = 0;
	}
	while((c = line[pos++]) == ' ' || c == '\t');
	if(isdigit(c) || c == '.' || c == '-')
	{
		s[i++] = c;
		if(c == '-')
		{
			if(!isdigit(c = line[pos]) && c != '.')//是减号 
			{
				s[i] = '\0';
				return '-';
			}
		}
		while(isdigit(c = line[pos++]) || c == '.')
		{
			s[i++] = c;
		}
		s[i] = '\0'; 
		pos--;
		return NUMBER;
	}
	else//说明是操作符或者函数名或者变量名或者非法字符 
	{
		s[0] = c;
		if(islower(c))
		{
			while(islower(c = line[pos++]))
				s[++i] = c; 
			pos--;
		}
		s[++i] = '\0'; 
		if(strlen(s) > 1)
			return NAME;
		else
			return s[0];
	} 
}

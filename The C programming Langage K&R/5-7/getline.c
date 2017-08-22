#include<stdio.h>
#include"linesort.h"
int getline(char *line,int lim)//返回值是输入字符串长度，不包含'\0' 
{
	int i,c;
	for(i = 0;i < lim - 1 && (c = getchar()) != EOF && c != '\n';++i)
		line[i] = c; 
	line[i] = '\0';
	return i;
}

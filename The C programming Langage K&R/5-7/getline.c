#include<stdio.h>
#include"linesort.h"
int getline(char *line,int lim)//����ֵ�������ַ������ȣ�������'\0' 
{
	int i,c;
	for(i = 0;i < lim - 1 && (c = getchar()) != EOF && c != '\n';++i)
		line[i] = c; 
	line[i] = '\0';
	return i;
}

#include"linesort.h"
#include<string.h> 
#include<stdio.h>
int readlines(char *lineptr[],char *linestor,int maxline)
{
	int len;
	char line[MAXLEN];
	int linenum = 0;
	char *p = linestor;
	while((len = getline(line,MAXLEN)) > 0)
	{
		if(linenum <= maxline)
		{
			if(p+len+1-1 <= linestor+AVAIL-1)
			{
				strcpy(p,line);
				lineptr[linenum++] = p;
				p += len + 1;
			}
			else
				return -2;
		}
		else
			return -1;
	}
	return linenum;
}
void writelines(char *lineptr[],int linenum)
{
	int i;
	for(i = 0;i < linenum; ++i)
		printf("%s\n",lineptr[i]);
}

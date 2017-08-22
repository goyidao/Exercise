#include<stdio.h>
#include"linesort.h"
int main()
{
	char linestor[AVAIL];
	char *lineptr[MAXLINES];
	int linenum;
	if((linenum = readlines(lineptr,linestor,MAXLINES)) > 0)
	{
		lineqsort(lineptr,0,linenum - 1);
	}
	writelines(lineptr,linenum);
	return 0;
}

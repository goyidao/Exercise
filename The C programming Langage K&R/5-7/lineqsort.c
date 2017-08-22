#include"linesort.h"
#include<string.h>
static int partation(char *lineptr[],int low,int high);
static void swap(char *lineptr[],int i,int j);
void lineqsort(char *lineptr[],int low,int high)
{
	if(low < high)
	{
		int pivot = partation(lineptr,low,high);
		lineqsort(lineptr,low,pivot-1);
		lineqsort(lineptr,pivot+1,high);
	}
}
static int partation(char *lineptr[],int low,int high)
{
	int i;
	int last = low;
	swap(lineptr,low,(low+high)/2);
	for(i = 1;i <= high;++i)
		if(strcmp(lineptr[i],lineptr[low]) < 0)
			swap(lineptr,++last,i);
	swap(lineptr,last,low);
	return last;
}
static void swap(char *lineptr[],int i,int j)
{
	char *temp;
	temp = lineptr[i];
	lineptr[i] = lineptr[j];
	lineptr[j] = temp;
}

#include<stdio.h>
#define MAXSIZE 10
#define TABINC 8
char line[MAXSIZE];
void printline(int i);
int tabexp(int i);
int findwhite(int i);
int rearrange(int i);
main()
{
	char c;
	int i = 0;
	while((c = getchar()) != EOF)
	{
		if(c == '\t')//碰到/t就尽可能多的把他转换为8个空格 
		{
			i = tabexp(i);
		}
		else if(c == '\n')//碰到/n就把它之前的都打印出来 
		{
			printline(i);
			i = 0;
		}
		else//碰到正常的就存进去 
		{
			if(i >= MAXSIZE - 1)//数组满了就往前找到第一个空格，从那里换行以保证单词完整
			{
				line[i] = c;
				i = findwhite(i);
				printline(i);
				i = rearrange(i);
			}
			else//数组没有存满就继续存 
			{
				line[i] = c;
				++i;
			} 
		}
	}
	return 0; 
}
int tabexp(int i)
{
	for(;i < MAXSIZE && i % TABINC != 0;++i)
		line[i] = ' ';
	if(i < MAXSIZE)
		return i;
	else
	{
		printline(i);
		return 0;
	}
}
void printline(int i)
{
	int pos;
	for(pos = 0;pos < i;++pos)
		putchar(line[pos]);
	putchar('\n');
}
int findwhite(int i)
{
	for(;i >= 0 && line[i] != ' ';--i);
	if(i < 0) //整个数组都不含空格 
		return MAXSIZE;
	else
		return i+1;
}
int rearrange(int i)
{
	int pos;
	for(pos = 0;i < MAXSIZE;++i)
		line[pos++] = line[i];
	return pos;
}

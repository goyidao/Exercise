#include<stdio.h>
#define BEGIN 0
#define END 1
#define IN -1 
#define OUT 1 
#define test0 "12/*34*/56"
#define test1 '*' /*78*/ 
main()
{
	char c;
	int flagc = END;/*注释标记起始位*/
	int flagq = OUT;/*引号标记起始位*/
	char temp = -1;/*上一个输入字符*/
	while((c = getchar()) != EOF)
	{
		if(c == '\'' || c == '\"')
		{
			flagq = -1 * flagq;	
		}
		if(c == '/' && flagq == OUT)/*test2*/
		{
			if(temp == '*')
				flagc = END;
			temp = c;
		}
			
		else if(c == '*' && flagq == OUT)
		{
			if(temp == '/')
				flagc = BEGIN;
			temp = c;
		}
		else
		{
			 
			if(flagc == BEGIN)
			{
			}
			else
			{
				putchar(c);
				temp = c;
			}
		}
	} 
}

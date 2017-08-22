#include<stdio.h>
#define MAXSIZE 10 
main()
{
	int c,pos,count;
	int temp[MAXSIZE];
	pos = 0;
	count = 0; 
	while((c = getchar()) != EOF)
	{
		if(c == '\t' || c == ' ')
		{
			temp[pos++] = c;
		}
		else
		{	
			if(c != '\n')
			{
				while(pos > 0)
				{
					putchar(temp[--pos]);
					++count;
				}
				putchar(c);
				++count;
			}
			else
			{
				pos = 0;
				if(count != 0)
				{
					putchar(c);
					count = 0;
				}
			}
		}
	}
	return 0;
}

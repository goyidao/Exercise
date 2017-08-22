#include<stdio.h>
#define MAXSIZE 10
#define IN 0
#define OUT 1
main()
{
	char temp[MAXSIZE];
	char c;
	int i = 0,state = IN;
	while((c = getchar()) != EOF)
	{
		if(c != ' ' && c != '\t')
		{
			if(c != '\n')
			{
				while(i>0)
					putchar(temp[--i]);
			}
			else
				i = 0; 
			putchar(c);
			state = IN;
		}
		else if(state == IN)
		{
			state = OUT;
		}
		if(state == OUT)
		{
			temp[i++] = c;
		}
	}
}

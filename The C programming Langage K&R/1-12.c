#include<stdio.h>
#define IN 1
#define OUT 0 
main()
{
	int c;
	int state = OUT;
	while((c = getchar()) != EOF)
	{
		if(c == '\t' || c == '\n' || c == ' ')
		{
			if(state == IN)/*find the ponit of change*/
			{
				putchar('\n');
			}
			state = OUT;
		}
		else
		{
			putchar(c);
			state = IN;
		}
	}
}

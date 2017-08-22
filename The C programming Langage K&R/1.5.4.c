#include<stdio.h>
#define IN  1
#define OUT  0
main()
{
	int flag = OUT;
	int c;
	double cn,wn;
	for(cn = 0,wn = 0;(c = getchar()) != EOF;++cn)
	{
		if(c == ' ' || c == '\t' || c == '\n')
			flag = OUT;
		else
		{
			if(flag == OUT)
			{
				++wn;
				flag = IN;
			}
		}
	}
	printf("cn=%.0f	wn=%.0f",cn,wn);
}

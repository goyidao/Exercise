#include<stdio.h>
main()
{
	double nn,tabn,spacen,c;
	for(nn = tabn = spacen = 0;(c = getchar()) != EOF;)
	{
		if(c == '\n')
			++nn;
		else if(c == '\t')
			++tabn;
		else if(c == ' ')
			++spacen;
	}
	printf("nn=%.0f	tabn=%.0f	spacen=%.0f",nn,tabn,spacen);
}

#include<stdio.h>
#define N 8
main()
{
	int i = 0;
	char c;
	int count;
	while((c = getchar()) != EOF)
	{
		++i;
		if(c == '\t')
		{
			count = ((N - i + 1) % N + N) % N;
			while(count > 0)
			{
				putchar(' ');
				--count;
				++i;
			}
		}
		else if(c == '\n')
		{
			putchar(c);
			i = 0;
		}
		else
		{
			putchar(c);
		}
	}
}

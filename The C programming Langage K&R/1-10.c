#include<stdio.h>
main()
{
	int c;
	while((c = getchar()) != EOF)
	{
		switch(c)
		{
			case '\\': printf("\\"); break;
			case '\t': printf("\\t"); break;
			case '\b': printf("\\b"); break;
			default: putchar(c); break;
		}
	}
}

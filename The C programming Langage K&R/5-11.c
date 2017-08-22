#include<stdio.h>
#include<ctype.h>
void detab(int n);
int main(int argc,char *argv[])
{
	int i;
	if(argc == 2)
	{
		i = atoi(*++argv);
		printf("tab=%d\n",i);
		detab(i);
	}
	else
		detab(8);
	return 0;
}
void detab(int n)
{
	int count;
	int temp;
	int c;
	
	count = 0;
	while((c = getchar()) != EOF)
	{
		if(c == '\n')
		{
			count = 0;
			putchar('\n');
		}
		else if(c == '\t')
			for(temp = n - count%n;temp > 0;--temp)
			{
				putchar(' ');
				count++;
			}
		else
		{
			putchar(c);
			count++;
		}
	}
}

#include<stdio.h>
#define COLNUM 8
/*'\t'的作用：在一行中单独计数，从输入位置开始到离它最近的8的整数倍为止，都是空白*/
main()
{
	int i = 0;
	char c;
	while((c = getchar()) != EOF)
	{
		if(c == '\t')
		{
			for(;i % COLNUM != 0;++i)
				putchar(' ');
		}
		else
		{
			if(c == '\n')
				i = 0;
			putchar(c);
		}
	}
	return 0;
}

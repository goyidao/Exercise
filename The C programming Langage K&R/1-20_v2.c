#include<stdio.h>
#define COLNUM 8
/*'\t'�����ã���һ���е���������������λ�ÿ�ʼ�����������8��������Ϊֹ�����ǿհ�*/
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

#include<stdio.h>
#define MAXSIZE 10
#define TABINC 8
char line[MAXSIZE];
void printline(int i);
int tabexp(int i);
int findwhite(int i);
int rearrange(int i);
main()
{
	char c;
	int i = 0;
	while((c = getchar()) != EOF)
	{
		if(c == '\t')//����/t�;����ܶ�İ���ת��Ϊ8���ո� 
		{
			i = tabexp(i);
		}
		else if(c == '\n')//����/n�Ͱ���֮ǰ�Ķ���ӡ���� 
		{
			printline(i);
			i = 0;
		}
		else//���������ľʹ��ȥ 
		{
			if(i >= MAXSIZE - 1)//�������˾���ǰ�ҵ���һ���ո񣬴����ﻻ���Ա�֤��������
			{
				line[i] = c;
				i = findwhite(i);
				printline(i);
				i = rearrange(i);
			}
			else//����û�д����ͼ����� 
			{
				line[i] = c;
				++i;
			} 
		}
	}
	return 0; 
}
int tabexp(int i)
{
	for(;i < MAXSIZE && i % TABINC != 0;++i)
		line[i] = ' ';
	if(i < MAXSIZE)
		return i;
	else
	{
		printline(i);
		return 0;
	}
}
void printline(int i)
{
	int pos;
	for(pos = 0;pos < i;++pos)
		putchar(line[pos]);
	putchar('\n');
}
int findwhite(int i)
{
	for(;i >= 0 && line[i] != ' ';--i);
	if(i < 0) //�������鶼�����ո� 
		return MAXSIZE;
	else
		return i+1;
}
int rearrange(int i)
{
	int pos;
	for(pos = 0;i < MAXSIZE;++i)
		line[pos++] = line[i];
	return pos;
}

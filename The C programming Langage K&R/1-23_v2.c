#include<stdio.h>
/*ȥ��ע��*/
void rmcomment(int c);
/*��ǰ��ע�ͽ�β��־*/ 
void close_comment();
/*ԭ����������ڵ����ݣ�����ת���ַ�' or "�����*/
void close_quote(int c);
main()
{
	int c;
	while((c = getchar()) != EOF)
	{
		rmcomment(c);
	}
	return 0;
}
void rmcomment(int c)
{
	int d;
	if(c == '/')
	{
		d = getchar();
		if(d == '*')
			close_comment();
		else if(d == '/')
		{
			putchar('/');
			rmcomment(d);
		}
		else
		{
			putchar('/');
			putchar(d); //
		}
	}
	else if(c == '\'' || c == '\"')
		close_quote(c);
	else
		putchar(c); //
}
void close_comment()
{
	int c,d;
	c = getchar();
	d = getchar();
	while(c != '*' || d != '/')
	{
		c = d;
		d = getchar();
	}
}
void close_quote(int c)
{
	int d;
	putchar(c);
	while((d = getchar()) != c)
	{
		putchar(d);
		if(d == '\\')
			putchar(getchar());//����ת���ַ�' or " 
	}
	putchar(c);
}

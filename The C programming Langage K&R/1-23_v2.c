#include<stdio.h>
/*去除注释*/
void rmcomment(int c);
/*向前找注释结尾标志*/ 
void close_comment();
/*原样输出引号内的内容，处理含转意字符' or "的情况*/
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
			putchar(getchar());//忽略转义字符' or " 
	}
	putchar(c);
}

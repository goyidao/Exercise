#include<stdio.h>
#include<string.h>
#include"calculator.h"
#define BUFFERSIZE 100

int buf[BUFFERSIZE];
int bufp = 0;//

int getline(char line[],int lim)
{
	int c,i;
	
	for(i = 0;i < lim -1 && (c = getchar()) != EOF && c != '\n';++i)
		line[i] = c;
	if(c == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return i;
}
void ungets(char s[])//�ַ�����ߵ��Ǻ��ó������� 
{
	void ungetch(int c);
	int len,i; 
	
	len = strlen(s);
	for(i = 0;i < len;++i)//����ó�����Ҫ���ѹջ 
		ungetch(s[i]);
}
void ungetch(int c)
{
	if(bufp >= BUFFERSIZE)
		printf("error:buffer is full\n");
	else
		buf[bufp++] = c;
}

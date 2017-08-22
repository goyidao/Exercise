#include<stdio.h>
#define ARGUMENT 10
#define MAXSIZE ARGUMENT + 1
#define ISEND 1
#define ISNTEND 0
int getline(char s[],int lim);
main()
{
	char line[MAXSIZE];
	int len,count,flag;
	count = 0;
	flag = ISEND;
	
	while((len = getline(line,MAXSIZE)) != 0)
	{
		if(flag == ISNTEND)//��һ��û����һ�� 
		{
			printf("%s",line);
			count = count + len;
			if(line[len - 1] == '\n')//��ζ�ȡ������һ�� 
			{
				flag = ISEND;
				printf("(%d)\n",count);
				count = 0;
			}
		}
		else//��һ�ζ���һ�� ����ζ����� 
		{
			if(line[len - 1] != '\n')
			{
				flag = ISNTEND;
				printf("%s",line);
				count = len;
			}
		}
	}
}
/*�����\n,len����\n,ֻ��û����һ�е�ʱ�����һ����Ч�ַ��Ų���\n*/
int getline(char s[],int lim)
{
	int i,c;
	for(i = 0;i < lim -1 && (c = getchar()) != EOF && c != '\n';++i)
		s[i] = c;
	if(c == '\n')
		s[i++] = '\n';
	else if(c == EOF && i > 0)
		s[i++] = '\n';
	s[i] = '\0';
	return i;
}

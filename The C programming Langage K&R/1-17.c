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
		if(flag == ISNTEND)//上一次没读完一行 
		{
			printf("%s",line);
			count = count + len;
			if(line[len - 1] == '\n')//这次读取了完整一行 
			{
				flag = ISEND;
				printf("(%d)\n",count);
				count = 0;
			}
		}
		else//上一次读完一行 ，这次读新行 
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
/*如果有\n,len包含\n,只有没读完一行的时候最后一个有效字符才不是\n*/
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

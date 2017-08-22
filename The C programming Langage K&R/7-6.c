#include<stdio.h>
#include<stdlib.h> 
int main(int argc,char *argv[])
{
	FILE *fp1,*fp2;
	char line1[100],line2[100];
	if(argc != 3)
		return 1;
	else
	{
		fp1 = fopen(*++argv,"r");
		fp2 = fopen(*++argv,"r");
		if(fp1 == NULL || fp2 == NULL)
		{
			printf("error.\n");
			return 1; 
		}
		while(fgets(line1,100,fp1) != NULL && fgets(line2,100,fp2) != NULL)
		{
			if(strcmp(line1,line2) != 0)
			{
				printf("line1 = %sline2 = %s\n",line1,line2);
				return 0;
			}
		}
		printf("the same.\n");
		return 0;
	}
}

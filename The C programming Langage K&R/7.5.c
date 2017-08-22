#include<stdio.h>
void filecopy(FILE *ifp,FILE *ofp);
int main(int argc,char *argv[])
{
	FILE *fp;
	if(argc == 1)
		filecopy(stdin,stdout);
	else
	{
		while(--argc > 0)
		{
			fp = fopen(*++argv,"r");
			if(fp == NULL)
			{
				printf("error:can not open file.\n");
				return 1;
			}
			else
			{
				filecopy(fp,stdout);
				fclose(fp);
			}
		}
	}
	return 0;
}
void filecopy(FILE *ifp,FILE *ofp)
{
	int c;
	while((c = getc(ifp)) != EOF)
		putc(c,ofp);
}

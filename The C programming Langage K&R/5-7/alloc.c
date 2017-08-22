#include"linesort.h"
static char allocbuf[AVAIL];
static char *p = allocbuf;
char *alloc(int n)
{
	char *temp;
	if(p + n - 1 > allocbuf + AVAIL - 1)
		return -1;
	else
	{
		temp = p;
		p = p + n;
		return temp;
	}
}
void afree(char *s)
{
	if(s>=allocbuf && s <= alloc + AVAIL)
		p = s;
}

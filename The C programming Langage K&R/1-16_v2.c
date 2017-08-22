#include<stdio.h>
#include<stdlib.h>
#define INITSIZE 5
#define INCREMENT 5
typedef struct Sqlist{
	char *elem;
	int length;
	int listsize;
} Sqlist;
int initList(Sqlist &L);
int fillLIst(Sqlist &L,int c);
int getLine(Sqlist &L);
void copy(Sqlist &to,Sqlist &from);
main()
{
	int len;
	Sqlist line,longest;
	initList(line);
	initList(longest);
	while((len = getLine(line)) != 0)
	{
		
		if(len > longest.length - 1)
		{
			copy(longest,line);
		}
		line.length = 0;
	}
	printf("%s %d",longest.elem,longest.length - 1);
	return 0;
}
void copy(Sqlist &to,Sqlist &from)
{
	char *newbase;
	int i;
	if(to.listsize < from.length)
	{
		while(!(newbase = (char *)malloc(sizeof(char)*from.length)));
		free(to.elem);
		to.elem = newbase;
		to.listsize = from.length;
		to.length = from.length;
	}
	for(i = 0;i < to.length;++i)
	{
		to.elem[i] = from.elem[i];
	}
}
int initList(Sqlist &L)
{
	L.elem = (char *)malloc(sizeof(char)*INITSIZE);
	if(!L.elem)
		return -1;
	L.listsize = INITSIZE;
	L.length = 0;
	return 0;
}
void fillList(Sqlist &L,char c)
{
	char *newbase;
	if(L.length < L.listsize)
	{
		L.elem[L.length] = c;
	}
	else
	{
		while(!(newbase = (char *)realloc(L.elem,sizeof(char)*(L.listsize+INCREMENT))));
		L.elem = newbase;
		L.elem[L.length] = c;
		L.listsize = L.listsize + INCREMENT;
	}
	++L.length;
}
int getLine(Sqlist &L)
{
	int c;
	while((c = getchar()) != '\n' && c != EOF)
	{
		fillList(L,c);
	}
	if(c == '\n')
	{
		fillList(L,c);
	}
	fillList(L,'\0');
	return L.length - 1;
}

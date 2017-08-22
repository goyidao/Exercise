#include<stdio.h>
#include<stdlib.h>
#define OUT 0
#define LIST_INIT_SIZE 10
typedef struct Sqlist{
	int *elem;
	int listsize;
} Sqlist;
int listInit(Sqlist &L)
{
	int i;
	L.elem = (int *)malloc(sizeof(int)*LIST_INIT_SIZE);
	if(!L.elem) return -1;
	for(i = 0;i < LIST_INIT_SIZE;++i)
	{
		L.elem[i] = 0;
	}
	L.listsize = LIST_INIT_SIZE;
	return 0;
}
int listFill(Sqlist &L,int n)
{
	int *newbase;
	int i;
	if(n > L.listsize - 1)
	{
		newbase = (int *)realloc(L.elem,sizeof(int)*(n+1));
		if(!newbase)
			return -1;
		L.elem = newbase;
		for(i = L.listsize;i < n + 1;++i)
		{
			L.elem[i] = 0;
		}
		L.listsize = n + 1;
	}
	++L.elem[n];
	return 0;
}
main()
{
	int i,j;
	int c;
	Sqlist L;
	listInit(L);
	int state = OUT;
	while((c = getchar()) != EOF)
	{
		if(c > 'a' && c < 'z' || c > 'A' && c < 'Z')
		{
			++state;
		}
		else if(state != OUT)
		{
			listFill(L,state);
			state = OUT;
		}
	}
	for(i = 1;i < L.listsize;++i)
	{
		printf("%3d|",i);
		for(j = 1;j <= L.elem[i];++j)
		{
			printf("*");
		}
		printf(" (%d)\n",L.elem[i]);
	}  
}

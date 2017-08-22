#include<stdio.h>
#include<stdlib.h>
#define OUT 0
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 2
typedef struct Sqlist{
	int *table;
	int listsize;
	int max;
} SqList;

/*init a SqList*/
int ListInit_Sq(SqList &L);
/*put the number n into the Sqlist L*/
int ListFill_Sq(SqList &L,int n);

main()
{
	int state = OUT;
	int c;
	SqList L;
	int i,j;
	ListInit_Sq(L);
	/*count the size of every word*/
	while((c = getchar()) != EOF)
	{
		if(c > 'a' && c < 'z' || c > 'A' && c < 'Z')
		{
			++state;	
		}
		else if(state != OUT)
		{
			/*save the state as the size of last word*/
			ListFill_Sq(L,state);
			state = OUT;
		}	
	}
	/*print the result*/
	/*ordinate*/
	printf("\t|\n");
	printf("\t|\n");
	for(j = L.max;j > 0;--j)
	{
		printf("%8d|\t",j);
		for(i = 1;i < L.listsize;++i)
		{
			if(j <= L.table[i])
				printf("*\t");
			else
				printf(" \t");
		}
		printf("\n");
	}
	/*abscissa*/
	printf("\t");
	for(i = 1;i < L.listsize;++i)
	{
		printf("--------");
	}
	printf("\n\t");
	for(i = 1;i < L.listsize;++i)
	{
		printf("\t%d",i);
	}
}

int ListInit_Sq(SqList &L)
{
	int i;
	L.table = (int *)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!L.table)
		return -1;
	for(i = 0;i < LIST_INIT_SIZE;++i)
		L.table[i] = 0;
	L.listsize = LIST_INIT_SIZE;
	L.max = 0;
	return 0;
}
int ListFill_Sq(SqList &L,int n)
{
	int i;
	int inc;
	int * newbase;
	if(n > 100)
		return -2;
	if(n > L.listsize - 1)
	{
		inc = n / LISTINCREMENT + 1;
		newbase = (int *)realloc(L.table,sizeof(int) * inc * LISTINCREMENT);
		if(!newbase)
			return -1;
		L.table = newbase;
		for(i = L.listsize;i < inc * LISTINCREMENT;++i)
		{
			L.table[i] = 0;
		}
		L.listsize = inc * LISTINCREMENT;
	}
	++L.table[n];
	L.max = L.table[n] > L.max ? L.table[n] : L.max;
	return 0;
}

#include<stdio.h>
#define MAXSIZE 100
typedef struct{
	int elem;
	int cur;
} Component,SLinkList[MAXSIZE];//头尾数据域空出 
void InitSList(SLinkList L);
void SListInsert(SLinkList L,int i,int e);
int SListDelete(SLinkList L,int i,int *e);
int GetLen(SLinkList L);
int MallocS(SLinkList L);
void FreeS(SLinkList L,int i);
void PrintSList(SLinkList L);
int main()
{
	SLinkList L;
	InitSList(L);
	SListInsert(L,1,90);
	SListInsert(L,1,91);
	SListInsert(L,1,92);
	PrintSList(L);
	return 0;
}
void InitSList(SLinkList L)
{
	int i;
	L[0].cur = 1;
	for(i = 1;i < MAXSIZE-2;++i)
	{
		L[i].cur = i + 1;	
	}
	L[i].cur = 0;
	L[MAXSIZE-1].cur = 0;
}
void PrintSList(SLinkList L)
{
	int i = MAXSIZE - 1;
	while(L[i].cur)
	{
		i = L[i].cur;
		printf("%d\t",L[i].elem);
	}
}
/*分配出去的节点如果是第一个节点
，L[MAX-1].cur就应该设置为这个节点的索引*/
void SListInsert(SLinkList L,int i,int e)
{
	int j = MAXSIZE - 1;
	int count;
	int p;
	for(count = 0;count < i-1;++count)
	{
		j = L[j].cur;
	}
	p = MallocS(L);
	L[p].elem = e;
	L[p].cur = L[j].cur;
	L[j].cur = p;
}
int SListDelete(SLinkList L,int i,int *e)
{
	if(i<1 || i>GetLen(L))
		return -1;
	FreeS(L,i);
	return 0;
}
int GetLen(SLinkList L)
{
	int i = MAXSIZE - 1;
	int len = 0;
	while(L[i].cur != 0)
	{
		i = L[i].cur;
		len++;
	}
	return len;
}

int MallocS(SLinkList L)
{
	int i;
	if(L[0].cur == 0)
		printf("error:list full.\n");
	i = L[0].cur;
	L[0].cur = L[i].cur;
	return i;
}
void FreeS(SLinkList L,int i)
{
	int count;
	int j = MAXSIZE - 1;
	int k;
	for(count = 0;count < i-1;++count)
	{
		j = L[j].cur;
	}
	k = L[j].cur;
	L[j].cur = L[k].cur;
	L[k].cur = L[0].cur;
	L[0].cur = k;
}

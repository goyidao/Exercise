#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
	int elem;
	struct Node *next;
} Node,*LinkList;
void CreateList_tail(LinkList *L,int len);
void CreateList_head(LinkList *L,int len);
int GetElem(LinkList L,int i,int *e);
int ListInsert(LinkList L,int i,int e);
void PrintList(LinkList L);
int main()
{
	LinkList L;
	CreateList_tail(&L,4);
	ListInsert(L,4,7);
	PrintList(L);
	return 0; 
}
void CreateList_head(LinkList *L,int len)
{
	int i;
	LinkList p,q;
	srand(time(0));
	*L = p = (LinkList)malloc(sizeof(Node));
	p->elem = len;
	p->next = NULL;
	for(i = 0;i < len -1;++i)
	{
		q = (LinkList)malloc(sizeof(Node));
		q->elem = rand() % 100;
		q->next = p->next;
		p->next = q;
	}
}
void CreateList_tail(LinkList *L,int len)
{
	LinkList p,q;
	int i;
	
	p = *L = (LinkList)malloc(sizeof(Node));
	p->elem = len;
	p->next = NULL;
	
	for(i = 1;i <= len;++i)
	{
		q = (LinkList)malloc(sizeof(Node));
		scanf("%d",&q->elem);
		p->next = q;
		p = p->next;
	}
	p->next = NULL;
}
int GetElem(LinkList L,int i,int *e)//找第i个节点 
{
	int j = 0;
	LinkList p = L;
	while(p && j < i)
	{
		p = p->next;
		j++;
	}
	if(!p || j > i)
		return -1;
	else
	{
		*e = p->elem;
		return *e;
	}
}
int ListInsert(LinkList L,int i,int e)//在第i个节点之前插入e 
{
	LinkList q;
	int j = 0;
	while(L && j < i -1)
	{
		L = L->next;
		j++;
	}
	q = (LinkList)malloc(sizeof(Node));
	q->elem = e;
	q->next = L->next;
	L->next = q;
	return 0;
}
int ListDelete(LinkList L,int i,int *e)//删除第i个节点，并返回elem 
{
	int j = 0;
	LinkList p,q;
	p = L;
	
	while(p && j < i-1)
	{
		p = p->next;
		j++;
	}
	if(!p || j > i)
		return -1;
	else
	{
		q = p->next;
		p->next = q->next;
		*e = q->elem;
		free(q);
		return *e;
	}
}
void ListDestory(LinkList L)//也释放头结点版 
{
	LinkList q,p;
	p = L;
	while(p)
	{
		q = p->next;
		free(p);
		q = p;
	}
}
void PrintList(LinkList L)
{
	L = L->next;
	while(L)
	{
		printf("%d%c",L->elem,L->next ? ',':'\n');
		L = L->next;
	}
}

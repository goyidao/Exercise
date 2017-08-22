#include<stdio.h>
#include<stdlib.h>
typedef enum PointerTag{Link,Thread} PointerTag;
typedef struct BiThrNode{
	char data;
	struct BiThrNode *left,*right;
	PointerTag LTag,RTag;
}BiThrNode,*BiThrTree;

BiThrTree Pre;

void CreateBiTree(BiThrTree *Thr)//°´ÕÕÏÈÐò½¨Ê÷ 
{
	int c;
	c = getchar();
	if(c == '#')
		*Thr = NULL;
	else
	{
		*Thr = (BiThrTree)malloc(sizeof(BiThrNode));
		(*Thr)->LTag = Link;
		(*Thr)->RTag = Link;
		(*Thr)->data = c;
		CreateBiTree(&(*Thr)->left);
		CreateBiTree(&(*Thr)->right);
	}
}
void InThreading(BiThrTree T)
{
	if(T)
	{
		InThreading(T->left);
		if(!T->left)
		{
			T->left = Pre;
			T->LTag = Thread;
		}
		if(!Pre->right)
		{
			Pre->right = T;
			Pre->RTag = Thread; 
		}
		Pre = T;
		InThreading(T->right);
	}
}
void InOrderThreading(BiThrTree *Thr,BiThrTree T)
{
	*Thr = (BiThrTree)malloc(sizeof(BiThrNode));
	(*Thr)->LTag = Link;
	(*Thr)->RTag = Thread;
	(*Thr)->right = *Thr;
	if(!T)
		(*Thr)->left = *Thr;
	else
	{
		(*Thr)->left = T;
		Pre = *Thr;
		InThreading(T);
		Pre->RTag = Thread;
		Pre->right = *Thr;
		(*Thr)->right = Pre;
	}
}
void InOrderTrav(BiThrTree Thr)
{
	BiThrTree p = Thr->left;
	while(p != Thr)
	{
		while(p->LTag == Link)
			p = p->left;
		printf("%c\t",p->data);
		while(p->RTag == Thread && p->right != Thr)
		{
			p = p->right;
			printf("%c\t",p->data);
		}
		p = p->right;
	}
}
int main()
{
	BiThrTree T,Thr;
	CreateBiTree(&T);
	//printf("atfer....CreateBiTree\n");
	InOrderThreading(&Thr,T);
	//printf("atfer....InOrderThreading\n");
	//printf("%d\n",Thr->left->RTag);
	InOrderTrav(Thr);
	return 0; 
}

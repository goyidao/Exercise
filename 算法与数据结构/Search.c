#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
	int data;
	struct BiTNode *left,*right;
}BiTNode,*BiTree;
int BiSearch(BiTree T,int key,BiTree f,BiTree *p)
{
	if(!T)
	{
		*p = f;
		return 0;
	}
	else if(T->data == key)
	{
		*p = T;
		return 1;
	}
	else if(T->data > key)
		BiSearch(T->left,key,T,p);
	else if(T->data < key)
		BiSearch(T->right,key,T,p);
}
int BiInsert(BiTree *T,int key)
{
	int i;
	BiTree t;
	BiTree p = (BiTree)malloc(sizeof(BiTNode));
	p->data = key;
	p->left = p->right = NULL;
	if(!(*T))
	{
		*T = p;
		return 1;
	}
	else
	{
		i = BiSearch(*T,key,NULL,&t);
		if(i)
			return 0;
		else
		{
			if(t->data > key)
				t->left = p;
			else
				t->right = p;
			return 1;
		}
	}
}
void CreateBST(BiTree *T,int a[],int len)
{
	int i;
	for(i = 0;i < len;++i)
		BiInsert(T,a[i]);
}
void InOrderTraverse(BiTree T)
{
	if(!T)
		return;
	else
	{
		InOrderTraverse(T->left);
		printf("%d",T->data);
		InOrderTraverse(T->right);
	}
}
void Delete(BiTree *T)
{
	BiTree p,s; 
	if(!(*T)->right)
	{
		p = *T;
		*T = (*T)->left;
		free(p);
	}
	else if(!(*T)->left)
	{
		p = *T;
		*T = (*T)->right;
		free(p);
	}
	else//左右子树都不空 
	{
		p = *T;
		s = (*T)->left;
		while(s->right)
		{
			p = s;
			s = s->right;
		}
		(*T)->data = s->data;
		if(p != (*T))
			p->right = s->left;
		else
			p->left = s->left;
	}
}
int DeleteBST(BiTree *T,int key)
{
	if(!*T)
		return 0;
	else
	{
		if((*T)->data == key)
			Delete(T);
		else if((*T)->data > key)
			DeleteBST(&((*T)->left),key);
		else if((*T)->data < key)
			DeleteBST(&((*T)->right),key); 
	}
}
int main()//结构体一定要初始化，不然在给另一个结构体赋值是会发生错误，比如实参传递给形参 
{
	BiTree T,p,f,NT;
	int i;
	int a[] = {1,2,3,4,5};
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = 62;
	p = (BiTree)malloc(sizeof(BiTNode));
	p->data = 58;
	p->left = p->right = NULL;
	T->left = p;
	p = (BiTree)malloc(sizeof(BiTNode));
	p->data = 88;
	p->left = p->right = NULL;
	T->right = p;
	p = NULL;
	f = NULL;
	BiInsert(&T,40);
	i = BiSearch(T,58,f,&p);
	if(i)
	{
		printf("%d\n",p->data);
		printf("%d\n",p->left->data);
	}
	else
		printf("插入失败\n");
	NT = NULL;
	CreateBST(&NT,a,5);
	InOrderTraverse(NT);
	DeleteBST(&NT,4);
	putchar('\n');
	InOrderTraverse(NT);
}

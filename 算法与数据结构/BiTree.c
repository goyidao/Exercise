#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct BiTNode{
	int elem;
	struct BiTNode *right,*left;
	int isfirst; //后序遍历时需要 
}BiTNode,*BiTree;

typedef struct SqStack{
	BiTNode *elem[MAXSIZE];
	int top;
} SqStack;

void CreateBiTree(BiTree *T);
void re_InOrderTrav(BiTree T);
void InOrderTrav(BiTree T);
void InOrderTrav_v2(BiTree T);
void PreOrderTrav(BiTree T);
void PostOrderTrav(BiTree T);//需要修改BiTNode，增加一个标志域 

void InitStack(SqStack *S);
int pop(SqStack *S,BiTree *e);
int isEmpty(SqStack S);
int GetTop(SqStack *S,BiTree *T);

/*----------------------全局栈S-----------------------------------*/
SqStack S;
/*-----------------------main-------------------------------------*/
int main()
{
	BiTree T;
	CreateBiTree(&T);
	printf("PreOrder:");
	PreOrderTrav(T);
	putchar('\n');
	printf("InOrder:");
	InOrderTrav_v2(T);
	printf("....\n");
	re_InOrderTrav(T);
	printf("....\n");
	putchar('\n');
	printf("PostOrder:");
	PostOrderTrav(T);
	putchar('\n');
	return 0;
}
/*----------------------BiTree------------------------------------*/
void CreateBiTree(BiTree *T)//按照先序建树 
{
	int e;
	scanf("%d",&e);
	if(e == 0)
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!(*T))
			return;
		(*T)->elem = e;
		CreateBiTree(&(*T)->left);
		CreateBiTree(&(*T)->right);
	}
}
void re_InOrderTrav(BiTree T)//递归中序遍历二叉树
{
	if(!T)
		return;
	else
	{
		re_InOrderTrav(T->left);
		printf("%d\n",T->elem);
		re_InOrderTrav(T->right);
	}
}
void InOrderTrav(BiTree T)//非递归中序遍历二叉树 
{
	BiTree P;
	P = T;
	if(!T)
		return;
	InitStack(&S);
	while(P || !isEmpty(S))
	{
		if(P)
		{
			push(&S,P);
			P = P->left;
		}
		else
		{
			pop(&S,&P);
			printf("%d\n",P->elem);
			P = P->right;
		}
	}
}
void InOrderTrav_v2(BiTree T)
{
	BiTree P = T;
	InitStack(&S);
	if(!P)
		return;
	else
		push(&S,P);
	while(!isEmpty(S))
	{
		while(GetTop(&S,&P) && P)
			push(&S,P->left);
		pop(&S,&P);
		if(!isEmpty(S))
		{
			pop(&S,&P);
			printf("%d\t",P->elem);
			push(&S,P->right);
		}
	}
}

void PreOrderTrav(BiTree T)
{
	BiTree P = T;
	InitStack(&S);
	if(!T)
		return;
	while(P || !isEmpty(S))
	{
		if(P)
		{
			push(&S,P);
			printf("%d\t",P->elem);
			P = P->left;
		}
		else
		{
			pop(&S,&P);
			P = P->right;
		}
	}
}
void PostOrderTrav(BiTree T)
{
	BiTree P = T;
	if(!T)
		return;
	InitStack(&S);
	while(P || !isEmpty(S))
	{
		while(P)
		{
			P->isfirst = 1;
			push(&S,P);
			P = P->left;
		}
		if(!isEmpty(S))
		{
			pop(&S,&P);
			if(P->isfirst == 1)
			{
				push(&S,P);
				P->isfirst = 0;
				P = P->right; 
			}
			else
			{
				printf("%d\t",P->elem);
				P = NULL;
			}
		}
	}
}

/*-----------------------stack--------------------------------*/
void InitStack(SqStack *S)
{
	S->top = -1;
}
int push(SqStack *S,BiTree e)
{
	if(S->top == MAXSIZE)
		return 0;
	else
		S->elem[++S->top] = e;
	//printf("S->top=%d\n",S->top);
	return 1;
}
int pop(SqStack *S,BiTree *e)
{
	if(S->top == -1)
		return 0;
	else
	{
		*e = S->elem[S->top--];
		//printf("S->top=%d\n",S->top);
		return 1;
	}
}
int isEmpty(SqStack S)
{
	if(S.top == -1)
		return 1;
	else
		return 0;
}
int GetTop(SqStack *S,BiTree *T)
{
	if(S->top == -1)
		return 0;
	else
	{
		*T = S->elem[S->top];
		return 1;
	}
}

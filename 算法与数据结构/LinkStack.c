#include<stdio.h>
#include<stdlib.h>
typedef struct StackNode{
	int elem;
	struct StackNode *next;
} StackNode,*LinkStackPtr;
typedef struct{
	LinkStackPtr top;
	int count;
} LinkStack;
void InitStack(LinkStack *S);
void push(LinkStack *S,int e);
int pop(LinkStack *S,int *e);

int main()
{
	int e;
	LinkStack S;
	InitStack(&S);
	push(&S,5);
	push(&S,6);
	push(&S,7);
	pop(&S,&e);
	printf("%d\t",e);
	pop(&S,&e);
	printf("%d\t",e);
	pop(&S,&e);
	printf("%d\t",e);
	printf("%d\n",pop(&S,&e));
}
void InitStack(LinkStack *S)
{
	S->count = 0;
	S->top = NULL;
}
void push(LinkStack *S,int e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->elem = e;
	p->next = S->top;
	S->top = p;
	S->count++;
}
int pop(LinkStack *S,int *e)
{
	LinkStackPtr p;
	if(!S->top)
		return -1;
	*e = S->top->elem;
	p = S->top;
	S->top = S->top->next;
	S->count--;
	free(p);
	return 0;
}

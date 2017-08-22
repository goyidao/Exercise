#include"stack.h"
Status InitStack(SqStack *S)
{
	S->top = -1;
}
int IsEmpty(SqStack S)
{
	if(S.top == -1)
		return 1;
	else
		return 0;
}
Status GetTop(SqStack S,ElemType *e)
{
	if(!IsEmpty(S))
	{
		*e = S.elem[S.top];
		return OK;
	}
	else
		return ERROR;
}
Status push(SqStack *S,ElemType e)
{
	if(S->top == STACKMAXSIZE-1)
		return ERROR;
	else
		S->elem[++S->top] = e;
	return OK;
}
Status pop(SqStack *S,ElemType *e)
{
	if(!IsEmpty(*S))
	{
		*e = S->elem[S->top--];
		return OK;
	}
	else
		return ERROR;
}

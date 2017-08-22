typedef int ElemType;
#define STACKMAXSIZE 100
#define ERROR -1
#define OK 1
typedef int Status;
typedef struct{
	ElemType elem[STACKMAXSIZE];
	int top;
}SqStack;
Status InitStack(SqStack *S);
Status GetTop(SqStack S,ElemType *e);
Status push(SqStack *S,ElemType e);
Status pop(SqStack *S,ElemType *e);
int IsEmpty(SqStack S);

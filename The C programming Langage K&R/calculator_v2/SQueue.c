#include<stdio.h>
#define MAXSIZE 100
typedef struct{
	int elem[MAXSIZE];
	int front;
	int rear;
} SQueue;
void InitSQueue(SQueue *Q)
{
	Q->front = Q->rear = 0;
}
int EnSQueue(SQueue *Q,int e)
{
	if(Q->front == (Q->rear + 1)%MAXSIZE)
		return -1;
	Q->elem[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 0;
}
int DeSQueue(SQueue *Q,int *e)
{
	if(Q->front == Q->rear)
		return -1;
	*e = Q->elem[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE; 
	return 0;
}
void SQueueTraverse(SQueue *Q)
{
	int tf = Q->front;
	while(tf != Q->rear)
	{
		printf("%d\t",Q->elem[tf]);
		tf = (tf + 1)%MAXSIZE;
	}
	printf("\n"); 
}
int main()
{
	SQueue Q;
	int e;
	InitSQueue(&Q);
	EnSQueue(&Q,2);
	EnSQueue(&Q,3);
	EnSQueue(&Q,4);
	EnSQueue(&Q,5);
	SQueueTraverse(&Q);
	DeSQueue(&Q,&e);
	SQueueTraverse(&Q);
	return 0;
}

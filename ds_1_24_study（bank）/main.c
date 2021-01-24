#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <process.h>
#include <limits.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int status;
typedef int Boolean;

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode,*QuePtr;
typedef struct Queue
{
    QuePtr front;
    QuePtr rear;
}Queue;
status InitQueue(Queue *Q)
{
    Q->front=Q->rear=(LNode*)malloc(sizeof(LNode));
    if(Q->front==NULL)
        exit(OVERFLOW);
    Q->front->next=NULL;
    return OK;
}
status EnQueue(Queue *Q,int x)
{
    LNode* S=malloc(sizeof(LNode));
    S->data=x;
    S->next=NULL;
    Q->rear->next=S;
    Q->rear=S;
    return OK;
}
status DeQueue(Queue*Q,int*e)
{
    if(Q->front==Q->rear)
        exit(OVERFLOW);
    QuePtr q=Q->front->next;
    *e=q->data;
    Q->front->next=q->next;
    if(Q->rear==q)
        Q->front=Q->rear;
    free(q);
    return OK;
}
status DestroyQue(Queue* Q)
{
    while(Q->front->next)
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    return OK;
}
void TraverQue(Queue Q)
{
    if(Q.front==Q.rear)
        return ERROR;
    QuePtr q=Q.front->next;
    while(q)
    {
        printf("%d ",q->data);
        q=q->next;
    }
}
status isEmpty(Queue Q)
{
    if(Q.front==Q.rear)
        return 1;
    else
        return 0;

}
int main()
{
    Queue Q1,Q2;
    InitQueue(&Q1);
    InitQueue(&Q2);
    int i,j,k,e0;
    int arr[19]={0};
    scanf("%d",&j);
    for(i=1;i<=j;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]%2!=0)
        {
            EnQueue(&Q1,arr[i]);
        }
        if(arr[i]%2==0)
        {
            EnQueue(&Q2,arr[i]);
        }
    }
    i=1;
	if(Q1.front->next&&Q2.front->next)
	{
	DeQueue(&Q1,&e0);
	printf("%d",e0);
	i++;
	}

	if(Q1.front->next&&!Q2.front->next)
	{
	DeQueue(&Q1,&e0);
	printf("%d",e0);
	i++;
	}

	if(!Q1.front->next&&Q2.front->next)
	{
	DeQueue(&Q2,&e0);
	printf("%d",e0);
	i++;
	}

	while(Q1.front->next&&Q2.front->next)
	{
		if(i%3!=0)
		{
		DeQueue(&Q1,&e0);
		printf(" %d",e0);
		i++;
		}
		else
		{
		DeQueue(&Q2,&e0);
		printf(" %d",e0);
		i++;
		}
	}
	while(Q1.front->next)
	{
		DeQueue(&Q1,&e0);
		printf(" %d",e0);
	}

	while(Q2.front->next)
	{
		DeQueue(&Q2,&e0);
		printf(" %d",e0);
	}


    return 0;
}

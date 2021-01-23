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

typedef struct QNode
{
    int data;
    struct QNode* next;
}QNode,*QueuePtr;
typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
status InitQueue(LinkQueue*Q)
{

    QueuePtr head=(QueuePtr)malloc(sizeof(QNode));
    if(head==NULL)
    {
        exit(OVERFLOW);
        return ERROR;
    }
    Q->front=Q->rear=head;
    Q->front->next=NULL;
    return OK;
}
status EnQueue(LinkQueue*Q,int a)
{
    QNode* Node=(QNode*)malloc(sizeof(QNode));
    if(Node==NULL)
        exit(OVERFLOW);
    Node->next=NULL;
    Node->data=a;
    Q->rear->next=Node;
    Q->rear=Node;
}
status QueueTraverse(LinkQueue Q,void(*vis)(int))
{
    QueuePtr p;
    p=Q.front->next;
    while(p)
    {
        vis((p->data));
        p=p->next;
    }
    printf("\n");
    return OK;
}
void visit(int a)
{
    printf("%d ",a);
}
status getHead(LinkQueue Q,int*e)
{
    if(Q.front==Q.rear)
        return ERROR;
    *e=Q.front->next->data;
    return OK;
}
int QueueLength(LinkQueue Q)
{
    int i=0;
    QueuePtr q=Q.front->next;
    while(q)
    {
        i++;
        q=q->next;
    }
    return i;
}

status ClearQueue(LinkQueue*Q)
{
    QueuePtr p,q;
    p=Q->front->next;
    Q->rear=Q->front;
    Q->front->next=NULL;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    return OK;
}
Boolean QueueEmpty(LinkQueue Q)
{
    if(Q.front==Q.rear)
    {
        return TRUE;
    }
    else
        return FALSE;
}
status Dequeue(LinkQueue*Q,int* e)
{
    if(Q->front==Q->rear)
        return ERROR;
    QueuePtr p;
    p=Q->front->next;
    *e=p->data;
    Q->front->next=p->next;
    if(Q->rear==p)
            Q->rear=Q->front;
    free(p);
    return OK;
}
status DestroyQue(LinkQueue*Q)
{
    while(Q->front)
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    return OK;
}
int main()
{
    LinkQueue Q;
    status i;
    int e;
    i=InitQueue(&Q);
    printf("status=%d\n",i);
    printf("front=%p   rear=%p\n",Q.front,Q.rear);
    for(i=1;i<=10;i++)
    {
        EnQueue(&Q,i);
    }
    getHead(Q,&e);
    printf("head=%d \n",e);
    QueueTraverse(Q,visit);
    printf("front=%p   rear=%p\n",Q.front,Q.rear);
    Dequeue(&Q,&e);
    printf("出队的是  %d \n",e);
    QueueTraverse(Q,visit);
    printf("front=%p   rear=%p\n",Q.front,Q.rear);
    getHead(Q,&e);
    printf("head=%d \n",e);
    QueueTraverse(Q,visit);
    printf("%d\n",QueueLength(Q));
    ClearQueue(&Q);
    printf("front=%p   rear=%p\n",Q.front,Q.rear);
    //QueueTraverse(Q,visit);
    printf("%d\n",QueueLength(Q));
    return 0;
}




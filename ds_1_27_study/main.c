

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

typedef struct BiTNode
{
    char data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode,*BiTree;

status InitBiTree(BiTree *T)
{
    *T=NULL;
    return OK;
}
void visit(char a)
{
    printf("%c ",a);
}
void PreOrderTraverse(BiTree T,void(*visit)(char))
{
    if(T)
    {
        visit(T->data);
        PreOrderTraverse(T->lchild,visit);
        PreOrderTraverse(T->rchild,visit);
    }
}
void InOrderTraverse(BiTree T,void(*visit)(char))
{
    if(T)
    {

        InOrderTraverse(T->lchild,visit);
        visit(T->data);
        InOrderTraverse(T->rchild,visit);
    }
}
void PostOrderTraverse(BiTree T,void(*visit)(char))
{
    if(T)
    {

        PostOrderTraverse(T->lchild,visit);
        PostOrderTraverse(T->rchild,visit);
        visit(T->data);
    }
}
void CreatBiTree(BiTree* T)
{
    char ch;
    scanf("%c",&ch);
    if(ch==' ')
        *T=NULL;
    else
    {
        *T=malloc(sizeof(BiTNode));
        if(!*T)
            exit(OVERFLOW);
        (*T)->data=ch;
        CreatBiTree(&(*T)->lchild);
        CreatBiTree(&(*T)->rchild);
    }
}
status BiTreeEmpty(BiTree T)
{
    if(T)
        return FALSE;
    else
        return TRUE;
}
void DestroyTree(BiTree *T)
{
    if(*T)
    {
        if((*T)->lchild)
        {
            DestroyTree(&((*T)->lchild));
        }
        if((*T)->rchild)
            DestroyTree(&((*T)->rchild));
        free(*T);
        *T=NULL;
    }
}
int GetTall(BiTree T)
{
    int i=0;
    if(T)
    {
        if(GetTall(T->lchild)>=GetTall(T->rchild))
            return GetTall(T->lchild)+1;
        else
            return GetTall(T->rchild)+1;
    }
    return 0;
}
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
status EnQueue(LinkQueue*Q,BiTree a)
{
    QNode* Node=(QNode*)malloc(sizeof(QNode));
    if(Node==NULL)
        exit(OVERFLOW);
    Node->next=NULL;
    Node->data=a;
    Q->rear->next=Node;
    Q->rear=Node;
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
status Dequeue(LinkQueue*Q,BiTree* e)
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
void LevelOrderTravrse(BiTree T,void(*visit)(char))
{
    LinkQueue q;
    BiTree a;
    if(T)
    {
        InitQueue(&q);
        EnQueue(&q,T);
        while(!QueueEmpty(q))
        {
            Dequeue(&q,&a);
            visit(a->data);
            if(a->lchild)
                EnQueue(&q,a->lchild);
            if(a->rchild)
                EnQueue(&q,a->rchild);
        }
        printf("\n");
    }
}
int main()
{
    BiTree T;
    int i=0;
    InitBiTree(&T);
    CreatBiTree(&T);
    PreOrderTraverse(T,visit);
    printf("\n");
    InOrderTraverse(T,visit);
    printf("\n");
    PostOrderTraverse(T,visit);
    printf("\n");
    LevelOrderTravrse(T,visit);
    i=BiTreeEmpty(T);
    printf("empty=%d\n",i);
    i=GetTall(T);
    printf("%d\n",i);
    return 0;
}

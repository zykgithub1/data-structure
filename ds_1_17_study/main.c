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
typedef int boolean;
typedef int ElemType;
typedef struct LNode* LinkList;
struct LNode
{
    ElemType data;
    LinkList* next;
};

status ListTraverse(LinkList L,void(*vi)(ElemType))
{
    LinkList p=L->next;
    while(p)
    {
        vi(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}
status InitList(LinkList *L)
{
    //*L=(struct LNode*)malloc(sizeof(struct LNode));
    *L=(LinkList)malloc(sizeof(struct LNode));
    if(!*L)
        exit(OVERFLOW);
    (*L)->next=NULL;
    return OK;
}
void visit(ElemType e)
{
    printf("%d ",e);
}
status ListInsert(LinkList L,int i,ElemType e)
{
    int j=0;
    LinkList p=L,s;

    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i-1)
    {
        return ERROR;
    }
    s=(LinkList)malloc(sizeof(struct LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

int main()
{
    LinkList L,p;
    status i;
    int j;

    i=InitList(&L);
    printf("i=%d\n",i);
    printf("%p\n",L);
    for(j=1;j<=5;j++)
    {
        ListInsert(L,j,j);
    }
   /*
    p=L->next;
    for(j=1;j<=5;j++)
    {
        printf("%d ",p->data);
        p=p->next;
    }*/

    ListTraverse(L,visit);

    return 0;
}

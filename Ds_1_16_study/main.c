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
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 2

typedef struct
{
    ElemType* elem;
    int length;
    int listsize;
}SqList;

status InitList(SqList *L)
{
    (*L).elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!(*L).elem)
        exit(OVERFLOW);
    (*L).length=0;
    (*L).listsize=LIST_INIT_SIZE;
    return OK;
}
status DestroyList(SqList *L)
{
    free((*L).elem);
    (*L).elem=NULL;
    (*L).length=0;
    (*L).listsize=0;
    return OK;
}
status ClearList(SqList*L)
{
    (*L).length=0;
    return OK;
}
status ListEmpty(SqList L)
{
    if(L.length==0)
        return TRUE;
    else
        return FALSE;
}
int ListLength(SqList L)
{
    return L.length;

}
status GetElem(SqList L,int i,ElemType*e)
{
    if(i<1||i>L.length)
        exit(ERROR);
    *e=*(L.elem+i-1);
    return OK;
}
int LocateElem(SqList L,ElemType e,status(*compare)(ElemType,ElemType))
{
    ElemType *p;
    int i=1;
    p=L.elem;
    while(i<L.length&&!compare(*p++,e))
    {
        i++;
    }
    if(i<=L.length)
        return i;
    else
        return 0;
}
status ListInsert(SqList *L,int i,ElemType e)
{
    ElemType* q;//²åÈëµÄµØÖ·
    ElemType* p,*newbase;
    if(i<1||i>L->length+1)
        return ERROR;
    if(L->length>=L->listsize)
    {
        newbase=(ElemType*)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)
            return ERROR;
        (*L).elem=newbase;
        (*L).listsize+=LISTINCREMENT;
    }
    q=(*L).elem+i-1;
    for(p=(*L).elem+(*L).length-1;p>=q;--p)
    {
        *(p+1)=*p;
    }
    *q=e;
    (*L).length++;
    return OK;
}
status comp(ElemType c1,ElemType c2)
{
    if(c1==c2*c2)
        return TRUE;
    else
        return FALSE;
}
status ListDelete(SqList *L,int i)
{
    ElemType *p,*q;
    if(i<1||i>(*L).length)
        return ERROR;
    p=(*L).elem+i;
    //*e=*p;
    q=(*L).elem+(*L).length;
    for(p;p<q;p++)
    {
        *(p-1)=*(p);
    }
    (*L).length--;
    return OK;
}
status ListTraverse(SqList *L,void(*vi)(ElemType*))
{
    ElemType* p;
    int i;
    p=(*L).elem;
    for(i=1;i<=(*L).length;i++)
    {
        vi(p++);
    }
    printf("\n");
    return OK;
}
void visit(ElemType* e)
{
    printf("%d ",*e);
}

int main()
{
    SqList L;
    status i;
    int j=0;
    int h=0;
    ElemType* e0;
    i=InitList(&L);
    printf("i=%d\n",i);
    printf("L.elem=%p  L.length=%d  L.listsize=%d\n",L.elem,L.length,L.listsize);
    for(j=1;j<=10;j++)
    {
        ListInsert(&L,j,j);
    }
     ListInsert(&L,j,11);
     ListInsert(&L,12,12);
     ListInsert(&L,13,13);
      printf("L.elem=%p  L.length=%d  L.listsize=%d\n",L.elem,L.length,L.listsize);
     ListTraverse(&L,visit);
     ListDelete(&L,3);
     ListTraverse(&L,visit);
     printf("L.elem=%p  L.length=%d  L.listsize=%d\n",L.elem,L.length,L.listsize);
     LocateElem(L,3,comp);
     printf("index=%d\n",LocateElem(L,3,comp));
     j=ListLength(L);
     printf("%d\n",j);
     j=ListEmpty(L);
     printf("%d\n",j);
     DestroyList(&L);
     printf("L.elem=%p  L.length=%d  L.listsize=%d\n",L.elem,L.length,L.listsize);

     /*
    for(j=1;j<=13 ;j++)
    {
        printf("%d ",*(L.elem+j-1));
    }
    printf("\n");*/
    //printf("L.elem=%p  L.length=%d  L.listsize=%d\n",L.elem,L.length,L.listsize);
    return 0;
}

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
int main()
{
    BiTree* T;
    InitBiTree(&T);
    CreatBiTree(&T);
    PreOrderTraverse(T,visit);
    printf("\n");
   InOrderTraverse(T,visit);
    printf("\n");
    PostOrderTraverse(T,visit);
    printf("\n");
    return 0;
}

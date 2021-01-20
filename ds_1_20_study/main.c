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
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 2
typedef struct
{
    int* base;
    int* top;
    int stacksize;
}SqStack;

typedef int status;
typedef int Boolean;
status InitStack(SqStack*S)
{
    S->base=(int*)malloc(STACK_INIT_SIZE*sizeof(int));
    if(S->base==NULL)
        return 0;
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE;
    return OK;
}
status Push(SqStack *S,int e)
{
    if(S->top-S->base>=S->stacksize)
    {
        S->base=(int*)realloc(S->base,(S->stacksize+STACKINCREMENT)*4);
        if(!S->base)
            exit(OVERFLOW);
        S->top=S->base+S->stacksize;
        S->stacksize+=STACKINCREMENT;
    }
    *S->top++=e;
    return OK;
}
void visit(int e)
{
    printf("%d ",e);

}
status Destory(SqStack* S)
{
    free(S->base);
    S->base=NULL;
    S->top=NULL;
    S->stacksize=0;
    return OK;
}
status ClearStack(SqStack *S)
{
    S->top=S->base;
    return OK;
}
status StackEmpty(SqStack S)
{
    if(S.top==S.base)
        return TRUE;
    else
        return FALSE;
}
status StackTraverse(SqStack S,void(*visit)(int))
{
    while(S.top>S.base)
    {
        visit(*(S.base++));
    }
    printf("\n");

    return OK;
}
status Pop(SqStack* S,int *e)
{
    if(S->base==S->top)
    {
        return ERROR;
    }
    *e=*--S->top;
    return OK;
}
status GetTop(SqStack S,int *e)
{
    if(S.top==S.base)
        return ERROR;
    *e=*(S.top-1);
    return OK;
}
int main()
{
    SqStack S;
	status i, j;
	int e0;
	i = InitStack(&S);
	printf("i=%d\n", i);
	printf("base=%p ,size=%d\n", S.base, S.stacksize);
	for (j = 1; j <= 10; j++)
	{
		Push(&S, j);
	}
	StackTraverse(S, visit);
	printf("base=%p ,size=%d\n", S.base, S.stacksize);
	Push(&S, 11);
	StackTraverse(S, visit);
	printf("base=%p ,size=%d\n", S.base, S.stacksize);
	GetTop(S,&e0);
	printf("top=%d\n",e0);
	StackTraverse(S, visit);
	Push(&S, 12);
	StackTraverse(S, visit);
	printf("\nbase=%p ,size=%d\n", S.base, S.stacksize);
	Push(&S, 13);
	StackTraverse(S, visit);
	printf("base=%p ,size=%d\n", S.base, S.stacksize);

	Pop(&S,&e0);
	printf("Pop=%d\n",e0);
	StackTraverse(S, visit);
	Pop(&S,&e0);
	printf("Pop=%d\n",e0);
	StackTraverse(S, visit);
	GetTop(S,&e0);
	printf("top=%d\n",e0);
	StackTraverse(S, visit);
	ClearStack(&S);
	StackTraverse(S, visit);
	printf("base=%p ,size=%d\n", S.base, S.stacksize);
	Destory(&S);
	printf("base=%p ,size=%d\n", S.base, S.stacksize);
	return 0;
}

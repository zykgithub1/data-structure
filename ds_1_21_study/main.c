#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <process.h>
#include <limits.h>
#include <string.h>

typedef int status;
typedef int boolean;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAX_SIZE 100

typedef struct
{
    char* data;
    int size;
    int top;
}SqStack;
status InitSqStack(SqStack* S)
{
    S->data=malloc(sizeof(char)*MAX_SIZE);
    if(S->data==NULL)
    {
        return ERROR;
    }
    S->top=-1;
    S->size=MAX_SIZE;
    return OK;
}
void DestroyStack(SqStack* S)
{
    free(S->data);
    S->data=NULL;
}
status Push(SqStack*S,char ch)
{
    if(S->top>=MAX_SIZE-1)
    {
        return ERROR;
    }
    S->data[++S->top]=ch;
    return OK;
}
char Pop(SqStack*S)
{
    if(S->top==-1)
    {
        return ERROR;
    }
    char ch;
    ch=S->data[S->top--];
    return ch;
}
void TraverStack(SqStack S)
{
    if(S.top==-1)
        return;
    int i=0;
    for(i=0;i<=S.top;i++)
    {
        printf("%c ",S.data[i]);
    }
    printf("\n");
}
boolean isEmpty(SqStack S)
{
    if(S.top==-1)
        return TRUE;
    else
        return FALSE;
}
boolean isFull(SqStack S)
{
    if(S.top==MAX_SIZE-1)
        return TRUE;
    else
        return FALSE;
}
char getTop(SqStack S)
{
    if(S.top==-1)
    {
        return;
    }
    char ch;
    ch=S.data[S.top];
    return ch;
}
void setNull(SqStack*S)
{
    S->top=-1;
}
void LineEdit()//行编辑程序
{
    SqStack S;
    char *p,ch,c;
    InitSqStack(&S);
    ch = getchar();
    while(ch!=EOF)
    {
        while(ch!=EOF&&ch!='\n')
        {
            switch(ch)
            {
                case '#': Pop(&S);break;
                case '@': setNull(&S);break;
                default:Push(&S,ch);break;
            }
            ch=getchar();
        }
        p=S.data;
        int i=0;
        for(i=0;i<=S.top;i++)
        {
            printf("%c",*(p+i));
        }
        setNull(&S);
        if(ch!=EOF)
            ch = getchar();
    }
}
int main()
{
    LineEdit();
    /*
    printf("%d    ",i);
    printf("地址=%p\n",S.data);
    char a;
    for(a='a';a<'f';a++)
    {
        Push(&S,a);
    }
    TraverStack(S);
    printf("当前TOP= %c \n",getTop(S));
    printf("%c \n",Pop(&S));
    TraverStack(S);
    printf("%c \n",Pop(&S));
    TraverStack(S);*/
    return 0;
}

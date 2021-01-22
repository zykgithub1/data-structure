#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <process.h>
#include <limits.h>
#include <string.h>
#define M 8
#define N 8
typedef int status;
typedef int bool;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAX_SIZE 40

int masz[10][10]= {{1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};
typedef struct Direction
{
    int incX,incY;
}Direction;
typedef struct Box
{
    int x;
    int y;
    int di;
}Box;
typedef struct
{
    Box* data;
    int top;
}SqStack;
status InitSqStack(SqStack* S)
{
    S->data=(Box*)malloc(sizeof(Box)*100);
    if(S->data==NULL)
    {
        return ERROR;
    }
    S->top=-1;
    return OK;
}
void DestroyStack(SqStack* S)
{
    free(S->data);
    S->data=NULL;
}
status Push(SqStack*S,Box b)
{
    if(S->top>=MAX_SIZE-1)
    {
        return ERROR;
    }
    ++S->top;
    S->data[S->top].x=b.x;
    S->data[S->top].y=b.y;
    S->data[S->top].di=b.di;
    return OK;
}
Box Pop(SqStack*S)
{
    if(S->top==-1)
    {
        return;
    }
    Box ch;
    ch.x=S->data[S->top].x;
    ch.y=S->data[S->top].y;
    ch.di=S->data[S->top].di;
    S->top--;
    return ch;
}
void TraverStack(SqStack S)
{
    if(S.top==-1)
        return;
    int i=0;
    for(i=0;i<=S.top;i++)
    {
        printf("(%d %d)",S.data[i].x,S.data[i].y);
    }
    printf("\n");
}
int isEmpty(SqStack* S)
{
    if(S->top==-1)
        return 1;
    else
        return 0;
}
bool isFull(SqStack S)
{
    if(S.top==MAX_SIZE-1)
        return TRUE;
    else
        return FALSE;
}
/*Box getTop(SqStack S)
{
    if(S.top==-1)
    {
        return;
    }
    char ch;
    ch=S.data[S.top];
    return ch;
}*/
void setNull(SqStack*S)
{
    S->top=-1;
}

bool findPath(int masz[M+2][N+2],Direction direct[])
{
    SqStack S;
    InitSqStack(&S);
    direct[0].incX=0;
    direct[0].incY=1;
    direct[1].incX=1;
    direct[1].incY=0;
    direct[2].incX=0;
    direct[2].incY=-1;
    direct[3].incX=-1;
    direct[3].incY=0;
    Box temp={1,1,-1};
    int x,y,di;
    int line,col;
    masz[1][1]=-1;
    Push(&S,temp);
    //TraverStack(S);
    while(!isEmpty(&S))
    {
        temp=Pop(&S);
        x=temp.x;y=temp.y;di=temp.di+1;
        while(di<4)
        {
            line=x+direct[di].incX;
            col=y+direct[di].incY;
            if(masz[line][col]==0)
            {
                Box temp={x,y,di};

                Push(&S,temp);
                x=line;y=col;masz[line][col]=-1;
                if(x==M&&y==N)
                {
                    int k=0;
                    printf("ÃÔ¹¬Â·¾¶ÈçÏÂ£º\n");
                    for(k=0; k<=S.top; k++)
                       {
                           printf("\t(%d,%d)",S.data[k].x,S.data[k].y);
                           if((k+1)%5==0)
                             printf("\n");
                       }
                    printf("\n");
                    return TRUE;
                }
                else
                    di=0;
            }
            else di++;
        }
    }
    return FALSE;

}
int main()
{
    Direction direct[4]={0};

    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("%2d ",masz[i][j]);
        }
        printf("\n");
    }
    i=findPath(masz,direct);
    printf("%d\n",i);
    j=0;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("%2d ",masz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

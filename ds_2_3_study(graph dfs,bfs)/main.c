#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//邻接矩阵
#define OK 1
#define ERROR 0

#define MAXNUM 10

typedef int status;
typedef char ElemType;
typedef struct
{
    int vexnum;
    int arcnum;
    char vex[20];
    int Matrix[MAXNUM][MAXNUM];
}MGraph;

int location(MGraph G,char a)
{
    int v;
    for(v=0;v<G.vexnum;v++)
    {
        if(a==G.vex[v])
            return v;
    }
    return -1;
}
void createGraph(MGraph *G,int vexnum,int arcnum,char v[],char a[])
{
    G->vexnum=vexnum;
    G->arcnum=arcnum;
    int i,j;
    for(i=0;i<G->vexnum;i++)
    {
        G->vex[i]=v[i];
    }
    for(i=0;i<G->vexnum;i++)
    {
        for(j=0;j<G->vexnum;j++)
        {
            G->Matrix[i][j]=0;
        }
    }
    int t=0;
    int p,q;
    for(i=0;i<G->arcnum;i++)
    {
        char m,n;
        m=a[t++];//t=1
        n=a[t++];//t=2
        t++;
        p=location(*G,m);
        q=location(*G,n);
        G->Matrix[p][q]=1;
        G->Matrix[q][p]=1;
    }
}
void print(MGraph G)
{
    int i,j;
    printf("邻接矩阵为：\n");
    for(i=0;i<G.vexnum;i++)
    {
        for(j=0;j<G.vexnum;j++)
        {
            printf("%d ",G.Matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int firstAdjvex(MGraph G,int n)
{
    if(n<0||n>G.vexnum)
        exit(0);
    int j;
    for(j=0;j<G.vexnum;j++)
    {
        if(G.Matrix[n][j]==1)
            return j;
    }
    return -1;
}
int nextAdj(MGraph G,int i,int j)
{
    int h;
    for(h=j+1;h<G.vexnum;h++)
    {
        if(G.Matrix[i][h]==1)
            return h;
    }
    return -1;
}
int visited[MAXNUM];
void DFS(MGraph G,int n);
void DFSTraverse(MGraph G)
{
    printf("深度优先序列为:\n");
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
            DFS(G,i);
    }
}
void DFS(MGraph G,int n)
{
    printf("%c ",G.vex[n]);
    visited[n]=1;
    int w=firstAdjvex(G,n);
    while(w!=-1)
    {
        if(visited[w]==0)
            DFS(G,w);
        w=nextAdj(G,n,w);
    }
}
typedef struct Node
{
    char data;
    struct Node* next;
}Node,*Queueptr;

typedef struct
{
    Queueptr front;
    Queueptr rear;
}LinkQue;

status initQueue(LinkQue *Q)
{
    Q->front=Q->rear=malloc(sizeof(Node));
    if(!Q->front)
    {
        exit(0);
    }
    Q->front->next=NULL;
    return OK;
}

status EnQueue(LinkQue*Q,char e)
{
    Queueptr node=malloc(sizeof(Node));
    if(!node) return ERROR;
    node->data=e;
    Q->rear->next=node;
    Q->rear=node;
    node->next=NULL;
    return OK;
}
status DeQueue(LinkQue *Q,char *a)
{
    if(Q->front==Q->rear)
        return ERROR;
    Queueptr p=Q->front->next;
    *a=p->data;
    Q->front->next=p->next;
    if(Q->rear==p)
        Q->front=Q->rear;
    free(p);
    return OK;
}
int isEmpty(LinkQue Q)
{
    if(Q.front==Q.rear)
        return 1;
    else
        return 0;
}
void BFS(MGraph G)
{
    printf("\n广度优先序列:\n");
    LinkQue Q;
    int i;
    initQueue(&Q);
    for(i=0;i<G.vexnum;i++)
        visited[i]=0;
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            printf("%c ",G.vex[i]);
            visited[i]=1;
            EnQueue(&Q,G.vex[i]);
        }
        while(!isEmpty(Q))
        {
            char z;
            DeQueue(&Q,&z);
            char y=z;
            int w=firstAdjvex(G,location(G,y));
            /*while(w!=-1)
            {
                if(visited[w]==0)
                {
                    printf("%c ",G.vex[w]);
                    visited[w]=1;
                    EnQueue(&Q,G.vex[w]);
                }
                w=nextAdj(G,location(G,y),w);
            }*/
            for(w=firstAdjvex(G,location(G,y));w!=-1;w=nextAdj(G,location(G,y),w))
            {
                if(!visited[w])
                {
                    EnQueue(&Q,G.vex[w]);
                    printf("%c ",G.vex[w]);
                    visited[w]=1;
                }
            }

        }
    }
}

int main()
{
    MGraph G;
    ElemType v[] = "abcdef";    //顶点数组
    ElemType a[] = "ab,ac,ad,be,ce,df";    //边数组
    createGraph(&G,6,6,v,a);
    print(G);
    DFSTraverse(G);
    BFS(G);
    return 0;
}

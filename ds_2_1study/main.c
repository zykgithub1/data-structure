#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int weight,parent,lchild,rchild;
}HTNode,HuffmanTree[100];
void select(HuffmanTree H,int n,int*s1,int*s2)
{
    int i;int tmp=0;
    int max=999;
    for(i=1;i<=n;i++)
    {
        if(H[i].parent==0 && max>H[i].weight)
        {
            max=H[i].weight;
            tmp=i;
        }
    }
    *s1=tmp;
    max=999;
    for(i=1;i<=n;i++)
    {
        if(H[i].parent==0 && max>H[i].weight&&*s1!=i)
        {
            max=H[i].weight;
            tmp=i;
        }
    }
    *s2=tmp;
}
void creatHuffTree(HuffmanTree H,int w[],int n)
{
    int i,m=2*n-1;int s1,s2;
    for(i=1;i<=n;i++)
    {
        H[i].weight=w[i];
        H[i].parent=H[i].lchild=H[i].rchild=0;
    }
    for(i=n+1;i<=m;i++)
    {
        H[i].weight=0;
        H[i].parent=H[i].lchild=H[i].rchild=0;
    }
    for(i=n+1;i<=m;i++)
    {
        select(H,i-1,&s1,&s2);
        H[i].weight=H[s1].weight+H[s2].weight;
        H[i].lchild=s1;H[i].rchild=s2;
        H[s1].parent=H[s2].parent=i;
    }
}
void print(HuffmanTree H,int n)
{
    int w[100];
    int i;
    for(i=1;i<=2*n-1;i++)
    {
        w[i]=i;
    }
    printf("num\tweight\tparent\tlchild\trchild\n");
    for(i=1;i<=2*n-1;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t\n",w[i],H[i].weight,H[i].parent,H[i].lchild,H[i].rchild);
    }
}
void HuffCode(HuffmanTree H,int n)
{
    char cd[50][50];
    int i,start;
    for(i=1;i<=n;i++)
    {
        cd[i][n-1]='\0';
        start=n-1;
        int c=i;int p=H[i].parent;
        while(p!=0)
        {
            --start;
            if(H[p].lchild==c)
                cd[i][start]='0';
            else
                cd[i][start]='1';
            c=p;
            p=H[p].parent;
        }
        int j=start;
        for(j=start;cd[i][j]!='\0';j++)
            printf("%c",cd[i][j]);
        printf("\n");
    }
}
int main()
{
    HuffmanTree H;
    int w[100];int j;
    int n,leaf;
    printf("ÇëÊäÈë¹þ·òÂüÊ÷µÄÒ¶×ÓÊýÄ¿:\n");
    scanf("%d",&n);
    printf("ÇëÊäÈëÈ¨ÖØ:\n");
    for(j=1;j<=n;j++)
    {
        scanf("%d",&leaf);
        w[j]=leaf;
    }
    creatHuffTree(H,w,n);
    print(H,n);
    printf("¹þ·òÂü±àÂëÎª:\n");
    HuffCode(H,n);
    return 0;
}

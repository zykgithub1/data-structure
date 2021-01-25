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
typedef struct
{
    char* ch;
    int length;
}HString;
status StrAssign(HString* T,char* chars)
{
    int i,j;
    char* c;
    if(T->ch)
        free(T->ch);
    for(i=0,c=chars;*c!='\0';++i,++c);
    if(!i)
    {
        T->ch=NULL;T->length=0;
    }
    else
    {
        T->ch=malloc(sizeof(char)*i);
        if(T->ch==NULL)
            exit(OVERFLOW);
        else
        {
            for(j=0;j<=i;j++)
            {
                T->ch[j]=chars[j];
            }
            T->length=i;
        }
         return OK;
    }
}
int StrLength(HString T)
{
    return T.length;

}
void StrPrint(HString *T)
{
    int i;
    for(i=0;i<T->length;i++)
    {
        printf("%c",T->ch[i]);
    }
    printf("\n");
}
status StrEmpty(HString T)
{
    if(T.ch==NULL && T.length==0)
        return TRUE;
    else
        return FALSE;
}
int StrCompare(HString T,HString S)
{
    int i=0;
    for(i=0;i<T.length&&i<S.length;i++)
    {
        if(T.ch[i]!=S.ch[i])
            return T.ch[i]-S.ch[i];
    }
    return T.length-S.length;
}
status StrCpy(HString *T,HString S)
{
    int i;
    if(T->ch)
        free(T->ch);
    T->ch=malloc(sizeof(char)*S.length);
    if(!T->ch)
        exit(OVERFLOW);
    for(i=0;i<S.length;i++)
    {
        T->ch[i]=S.ch[i];
    }
    T->length=S.length;
    return OK;
}
status ClearStr(HString* S)
{
    if(S->ch)
    {
        free(S->ch);
        S->ch=NULL;
        S->length=0;
    }
    return OK;
}
status SubString(HString *sub,HString S,int pos,int len)
{
    if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
        return ERROR;
    if(sub->ch)
        free(sub->ch);
    if(len==0){
        sub->ch=NULL;sub->length=0;
    }
    else
    {
        sub->ch=malloc(sizeof(char)*len);
    if(!sub->ch)
        exit(OVERFLOW);
    int i=0;
    for(i=0;i<=len-1;i++)
    {
        sub->ch[i]=S.ch[pos+i-1];
    }
    sub->length=len;
    return OK;
    }
}
status StrConcat(HString *T,HString S1,HString S2)
{
    if(T->ch)
        free(T->ch);
    T->ch=malloc(sizeof(char)*(S1.length+S2.length));
    if(!T->ch)
        exit(OVERFLOW);
    T->length=S1.length+S2.length;
    int i,j;
    for(i=0;i<S1.length;i++)
    {
        T->ch[i]=S1.ch[i];
    }
    for(i=S1.length,j=0;i<T->length,j<S2.length;i++,j++)
    {
        T->ch[i]=S2.ch[j];
    }
    return OK;
}
int index(HString S,HString T,int pos)
{
    if(T.length>S.length)
        return 0;
    int n,m,i;
    HString sub;
    InitStr(&sub);
    if(pos>0)
    {
        int i=S.length-T.length;
        int h=pos;
        while(h<i+1)
        {
           SubString(&sub,S,h,T.length);
           if((StrCompare(sub,T))==0)
              return h;
           else
              h++;
        }
    }
    return 0;
}
status InitStr(HString *Q)
{
    Q->ch=NULL;
    Q->length=0;
}
status RePlace(HString* S,HString T,HString V)
{
    int i=1;
    if(StrEmpty(T))
        return ERROR;
    do
    {
        i=index(*S,T,i);
        if(i)
        {
            StrDelete(S,i,StrLength(T));
            StrInsert(S,i,V);
            i+=StrLength(V);
        }
    }while(i);
    return OK;
}

status StrInsert(HString *S,int pos,HString T)
{
    if(pos<1||pos>S->length+1)
        return ERROR;
    int i=0;
    S->ch=realloc(S->ch,sizeof(char)*(S->length+T.length));
    if(!S->ch)
        exit(OVERFLOW);
    for(i=S->length-1;i>=pos-1;i--)
    {
        S->ch[i+T.length]=S->ch[i];
    }
    for(i=0;i<T.length;i++)
    {
        S->ch[pos+i-1]=T.ch[i];
    }
    S->length+=T.length;
    return OK;
}
status StrDelete(HString *S,int pos,int len)
{
    if(S->length<pos+len-1)
        return ERROR;
    int i=0;
    for(i=pos-1;i<=S->length-len;i++)
    {
        S->ch[i]=S->ch[i+len];
    }
    S->ch=realloc(S->ch,sizeof(char)*(S->length-len));
    if(!S->ch)
        exit(OVERFLOW);
    S->length-=len;
    return OK;
}
int main()
{
    HString Str,Str1,Str2,Sub;
    char* s="abcdefg";
    char* t="cde";
    int i=StrAssign(&Str,s);
    printf("i=%d\n",i);
    StrPrint(&Str);
    printf("length=%d\n",StrLength(Str));
    printf("ÊÇ·ñÎª¿Õ=%d\n",StrEmpty(Str));
    StrAssign(&Str1,"dataucture");
    StrAssign(&Str2,"str");
    StrInsert(&Str1,5,Str2);
    StrPrint(&Str1);
    StrDelete(&Str1,1,6);
    StrPrint(&Str1);
    StrAssign(&Str, "datastructrre");
	StrAssign(&Str1, "tr");
	StrAssign(&Str2, "zz");
	RePlace(&Str,Str1,Str2);
	StrPrint(&Str);
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
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

typedef struct Tr
{
	char* data;
	int size;
	int top;
}Tr;
typedef struct Num
{
	int* data;
	int size;
	int top;
}Num;
status InitSqStack(Tr* S)
{
	S->data = malloc(sizeof(char)*MAX_SIZE);
	if (S->data == NULL)
	{
		return ERROR;
	}
	S->top = -1;
	S->size = MAX_SIZE;
	Push(&S, '#');
	return OK;
}
void DestroyStack(Tr* S)
{
	free(S->data);
	S->data = NULL;
}
status Push(Tr*S, char ch)
{
	if (S->top >= MAX_SIZE - 1)
	{
		return ERROR;
	}
	S->data[++S->top] = ch;
	return OK;
}
char Pop(Tr*S)
{
	if (S->top == -1)
	{
		return ERROR;
	}
	char ch;
	ch = S->data[S->top--];
	return ch;
}
void TraverStack(Tr S)
{
	if (S.top == -1)
		return;
	int i = 0;
	for (i = 0; i <= S.top; i++)
	{
		printf("%c ", S.data[i]);
	}
	printf("\n");
}
boolean isEmpty(Tr S)
{
	if (S.top == -1)
		return TRUE;
	else
		return FALSE;
}
boolean isFull(Tr S)
{
	if (S.top == MAX_SIZE - 1)
		return TRUE;
	else
		return FALSE;
}
char getTop(Tr S)
{
	if (S.top == -1)
	{
		return;
	}
	char ch;
	ch = S.data[S.top];
	return ch;
}
status InitNum(Num* S)
{
	S->data = malloc(sizeof(char)*MAX_SIZE);
	if (S->data == NULL)
	{
		return ERROR;
	}
	S->top = -1;
	S->size = MAX_SIZE;
	return OK;
}
void DestroyNum(Num* S)
{
	free(S->data);
	S->data = NULL;
}
status PushNum(Num*S, char ch)
{
	if (S->top >= MAX_SIZE - 1)
	{
		return ERROR;
	}
	S->data[++S->top] = ch;
	return OK;
}
int PopNum(Num*S)
{
	if (S->top == -1)
	{
		return ERROR;
	}
	char ch;
	ch = S->data[S->top--];
	return ch;
}
void TraverStackNum(Num S)
{
	if (S.top == -1)
		return;
	int i = 0;
	for (i = 0; i <= S.top; i++)
	{
		printf("%c ", S.data[i]);
	}
	printf("\n");
}
boolean isEmptyNum(Num S)
{
	if (S.top == -1)
		return TRUE;
	else
		return FALSE;
}
boolean isFullNum(Num S)
{
	if (S.top == MAX_SIZE - 1)
		return TRUE;
	else
		return FALSE;
}
int getTopNum(Num S)
{
	if (S.top == -1)
	{
		return;
	}
	int ch;
	ch = S.data[S.top];
	return ch;
}
void setNull(Tr*S)
{
	S->top = -1;
}
void Test()
{
	char theta;
	int a, b;
	Tr T;
	Num N;
	int i = InitSqStack(&T);
	i = InitNum(&N);
	char ch;
	ch = getchar();
	do
	{
		if (isTr(ch))
		{
			switch (Precede_my(getTop(T), ch))
			{
			case '<':
				Push(&T, ch);
				ch = getchar();
				break;
			case '=':
				if (ch == ')')
				{
					Pop(&T);
					ch = getchar();
					break;
				}
			case'>':
				theta = Pop(&T);
				a = PopNum(&N);
				b = PopNum(&N);
				PushNum(&N, Operate_my(a, theta, b));
			}

		}
		else
		{
			PushNum(&N, ch);
			ch = getchar();
		}
	} while ((ch != '#') || (getTop(T)) != '#');
	return getTopNum(N);
}
int Operate_my(int a, char c, int b)
{
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	if (c == '*')
		return a*b;
	if (c == '/')
		return a / b;
}
char Precede_my(char a, char b)
{
	if (a == '+')
	{
		if ((b == "+") || (b == '-') || (b == ')') || (b == '#'))
			return '>';
		else return '<';
	}
	else if (a == '-')
	{
		if ((b == "+") || (b == '-') || (b == ')') || (b == '#'))
			return '>';
		else return '<';
	}
	else if (a == '*')
	{
		if (b == '(')
			return '<';
		else return '>';
	}
	else if (a == '/')
	{
		if (b == '(')
			return '<';
		else return '>';
	}
	else if (a == '(')
	{
		if (b == ')')
			return '=';
		else return '<';
	}
	else if (a == ')')
	{
		return '>';
	}
	else if (a == '#')
	{
		if (b == '#')
			return '=';
		else return '<';
	}
}
int isTr(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')' || a == '#')
		return 1;
	else
		return 0;
}
int main()
{
	Test();
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int vexnum;
	int arcnum;
	char vex[20];
	int Matrix[20][20];
}Mgraph;
int location(Mgraph M, char a)
{
	int i;
	for (i = 0; i < M.vexnum; i++)
	{
		if (a == M.vex[i])
			return i;
	}
	return -1;
}
void creategraph(Mgraph *M, int vexnum, int arcnum, char v[], char a1[], char a2[])
{
	M->vexnum = vexnum;
	M->arcnum = arcnum;
	int i, j;
	for (i = 0; i < M->vexnum; i++)
	{
		M->vex[i] = v[i];
	}
	for (i = 0; i < M->vexnum; i++)
	{
		for (j = 0; j < M->vexnum; j++)
		{
			M->Matrix[i][j] = 0;
		}
	}
	int t = 0,g=0;
	int p, q;
	for (i = 0; i < M->arcnum; i++)
	{
		char m, n;
		m = a1[t++];
		n = a2[g++];
		p = location(*M, m);
		q = location(*M, n);
		M->Matrix[p][q] = 1;
		M->Matrix[q][p] = 1;
	}
}
void print(Mgraph M)
{
	int i, j;
	for (i = 0; i < M.vexnum; i++)
	{
		for (j = 0; j < M.vexnum; j++)
		{
			printf("%d ", M.Matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	Mgraph M;
	int vex; int arc;
	char v[20]; char ch; char a1[20]; char a2[20];
	int i;
	scanf("%d %d", &vex, &arc);
	getchar();
	for (i = 0; i < vex; i++)
	{
		scanf("%c", &ch);
		v[i] = ch;
	}
	getchar();
	char b1,b2;
	for (i = 0; i < arc; i++)
	{
		scanf("%c%c", &b1, &b2);
		a1[i] = b1; a2[i] = b2;
		getchar();
	}
	creategraph(&M, vex,arc, v, a1,a2);
	print(M);
	int ret = 0; int k;
	for (i = 0; i < M.vexnum; i++)
	{
		ret = 0;
		for (k = 0; k < M.vexnum; k++)
		{
			ret += M.Matrix[i][k];
		}
		printf("%d ", ret);
	}
	return 0;
}

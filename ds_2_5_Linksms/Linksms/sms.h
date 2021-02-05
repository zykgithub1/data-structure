#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct student
{
	int Id;
	char Name[10];
}student;

typedef struct Node
{
	student st;
	struct Node* next;
	struct Node* pre;
}Node,*Link;

void Add(Link L);
void Show(Link L);
void Delet(Link L);
void Search(Link L);
void Modify(Link L);
void Count(Link L);
void Save(Link L);
void Load(Link L);
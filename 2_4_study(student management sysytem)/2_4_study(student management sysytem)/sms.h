#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#define NO_LENGTH  20
#define NAME_LENGTH 11
#include <stdio.h>

typedef struct student{
	char sno[NO_LENGTH];
	char sname[NAME_LENGTH];
}st;

/* ����ÿ����¼��ڵ�����ݽṹ */
typedef struct node
{
	struct student data; //������
	struct node *next; //ָ����
}Node, *Link;  //NodeΪnode���͵ı���,LinkΪnode���͵�ָ�����


void Insert(Link L);
void Show(Link L);
void Delet(Link L);
void Destroy(Link L);

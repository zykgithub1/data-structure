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

/* 定义每条记录或节点的数据结构 */
typedef struct node
{
	struct student data; //数据域
	struct node *next; //指针域
}Node, *Link;  //Node为node类型的别名,Link为node类型的指针别名


void Insert(Link L);
void Show(Link L);
void Delet(Link L);
void Destroy(Link L);

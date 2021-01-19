#include <string.h>
#include <stdio.h>
#include <malloc.h>
#define DEFAULT_SZ 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define _CRT_SECURE_NO_WARNINGS

enum Option
{
	exit,
	add,
	del,
	search,
	modify,
	show,
	sort
};
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;
typedef struct Contact
{
	struct PeoInfo* data;
	int size;
	int capacity;
}Contact;
void InitContact(struct Contact* con);
void AddContact(struct Contact* con);
void ShowContact(const struct Contact* con);
void DelContact(struct Contact* con);
void SearchContact(const struct Contact* con);
void modifyContact(struct Contact* con);
void SortContact(struct Contact* con);
void DestoryContact(struct Contact* con);
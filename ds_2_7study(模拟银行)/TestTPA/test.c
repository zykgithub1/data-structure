#include <stdio.h>  
#include <time.h>  
#include <stdlib.h>  

#define OK 1  
#define ERROR 0  
#define TRUE 1  
#define FALSE 0  

typedef int Status;
typedef struct Event
{
	int OccurTime;
	int Ntype;
	struct Event* next;
}Event,ElemType;

typedef struct
{
	ElemType* head;
	ElemType* tail;
	int len;
}LinkList;

typedef LinkList EventList;

typedef struct QElemType
{
	int ArriveTime;
	int Duration;
	struct QElemType* next;
}QElemType;

typedef struct
{
	QElemType* head;
	QElemType* tail;
}LinkQueue;
Event NewEvent(int occurT, int nType);
//根据OccurTime和NType值，创建新事件  
Status InitList(LinkList *L);
//初始化事件链表  
Status OrderInsert(LinkList *L, Event e);
//将事件e按发生时间顺序插入有序链表L中  
Status ListEmpty(LinkList *L);
//判断链表L是否为空，为空返回TRUE，否则返回FALSE  
Status DelFirst(LinkList *L, ElemType *e);
//链表L不为空，删除其首结点，用e返回，并返回OK；否则返回ERROR  
Status ListTraverse(LinkList *L);
//遍历链表  
Status InitQueue(LinkQueue *Q);
//初始化队列Q  
Status EmptyQueue(LinkQueue *Q);
//若队列Q为空，返回TRUE，否则返回FALSE  
Status DelQueue(LinkQueue *Q, QElemType *e);
//若队列Q不为空，首结点出队，用e返回，并返回OK；否则返回ERROR  
Status EnQueue(LinkQueue *Q, QElemType e);
//结点e入队Q  
int QueueLength(LinkQueue Q);
//返回队列Q的长度，即元素个数  
Status GetHead(LinkQueue *Q, QElemType *e);
//若队列Q不为空，用e返回其首结点，并返回OK,否则返回ERROR  
Status QueueTraverse(LinkQueue *Q);
//遍历队列Q  

//------------------//  
int Min(int a[], int n);
//返回长度为n的数组a第一个最小值的下标，从1开始  
int ShortestQueue();
//获取最短队列的编号  
void OpenForDay();
//初始化操作  
void CustomerArrived();
//顾客达到事件  
void CustomerDepature();
//顾客离开事件  
void Bank_Simulation();
//银行排队模拟  
void PrintEventList();
//输出事件队列  
void PrintQueue();
//打印当前队列  
//----全局变量-----//  
EventList ev;
Event en;
LinkQueue q[5];
QElemType customer;
int TotalTime, CustmoerNum;
int CloseTime = 200;

void OpenForDay()
{
	int i = 0;
	InitList(&ev);
	TotalTime = 0; CustmoerNum = 0;
	en.Ntype = 0;
	en.OccurTime = 0;
	OrderInsert(&ev, en);
	for (i=0; i < 5; i++)
	{
		InitQueue(&(q[i]));
	}
}

void CustomerArrived()
{
	int durtime, intertime, i, t;
	QElemType e;
	++CustmoerNum;
	intertime = rand() % 5 + 1;
	durtime = rand() % 30 + 1;
	t = en.OccurTime + intertime;
	if (en.OccurTime < CloseTime)
	{
		printf("A new customer arrived at:%d,his durTime=%d,the next intertime=%d|\n", en.OccurTime, durtime, intertime);
		OrderInsert(&ev, NewEvent(t, 0));
		e.ArriveTime = en.OccurTime;
		e.Duration = durtime;
		i = ShortestQueue();
		EnQueue(&q[i], e);
	}
	if (QueueLength(q[i]) == 1)
	{
		OrderInsert(&ev, NewEvent(en.OccurTime + durtime, i));
	}
	else{
		printf("maxinum exceed!stop,en.OccurTime=%d,intertime=%d\n", en.OccurTime, intertime);
	}
}

void CustomerDepature()
{
	int i = en.Ntype;
	DelQueue(&q[i], &customer);
	printf("A customer leaves at:%d\n", en.OccurTime);
	TotalTime += en.OccurTime - customer.ArriveTime;
	if (!EmptyQueue(&(q[i])))
	{
		GetHead(&q[i], &customer);
		OrderInsert(&ev, NewEvent(en.OccurTime + customer.Duration, i));
	}
}

void Bank_Simulation()
{
	OpenForDay();
	srand((unsigned)time(NULL));
	while (!ListEmpty(&ev))
	{
		DelFirst(&ev, &en);
		if (en.Ntype == 0)
		{
			CustomerArrived();
		}
		else
			CustomerDepature();
		PrintQueue();
		PrintEventList();
	}
	printf("\nTotal time is: %d min,average time is: %g min.\n", TotalTime, (float)TotalTime / CustmoerNum);
}
void PrintQueue(){
	//打印当前队列  
	int i;
	for (i = 1; i <= 4; i++){
		printf("Queue %d have %d customer(s):", i, QueueLength(q[i]));
		QueueTraverse(&q[i]);
	}
	printf("\n");
}

void PrintEventList(){
	//输出事件队列  
	printf("Current Eventlist is:\n");
	ListTraverse(&ev);
}
int Min(int a[], int n)
{
	int tmp, i, ind=0;
	tmp = a[0];
	for (i = 1; i < n; i++)
	{
		if (tmp>a[i])
		{
			tmp = a[i];
			ind = i;
		}
	}
	return ind;
}
int ShortestQueue()
{
	int i, a[4];
	for (i = 1; i <= 4; i++)
	{
		a[i-1]=QueueLength(q[i]);
	}
	return Min(a, 4) + 1;
}


Event NewEvent(int occurT, int nType)
{
	Event e;
	e.OccurTime = occurT;
	e.Ntype = nType;
	return e;
}
Status InitList(LinkList*L)
{
	L->head = L->tail = malloc(sizeof(LinkList));
	if (!L->head)
		return ERROR;
	L->head->next = NULL;
	return OK;
}
Status OrderInsert(LinkList *L, Event e)
{
	Event *p, *q, *newptr;
	newptr = malloc(sizeof(ElemType));
	if (!newptr)
		return ERROR;
	*newptr = e;
	if (L->head == L->tail)
	{
		L->head->next = newptr;
		L->tail = newptr;
		L->tail->next = NULL;
		return OK;
	}
	p = L->head;
	q = L->head->next;
	while (q)
	{
		if (q->OccurTime >= newptr->OccurTime)
		{
			break;
		}
		p = q;
		q = q->next;
	}
	p->next = newptr;
	newptr->next = q;
	if (!q)
	{
		L->tail->next = newptr;
		L->tail = newptr;
	}
	return OK;
}
Status ListEmpty(LinkList *L)
{
	if (L->head == L->tail)
		return TRUE;
	else
		return FALSE;
}
Status DelFirst(LinkList *L, ElemType *e)
{
	ElemType*p = L->head->next;
	if (!p)
		return ERROR;
	*e = *p;
	L->head->next =p->next;
	free(p);
	if (L->head->next == NULL)
		L->tail = L->head;
	return OK;

}
Status ListTraverse(LinkList *L)
{
	if (L->head == L->tail)
		return ERROR;
	else
	{
		ElemType* p = L->head->next;
		while (p)
		{
			printf("OccurTime:%d,Event Type:%d\n", p->OccurTime, p->Ntype);
			p = p->next;
		}
		printf("\n");
		return OK;
	}
}
Status InitQueue(LinkQueue *Q)
{
	Q->head = Q->tail = malloc(sizeof(QElemType));
	if (!Q->head)
		return ERROR;
	Q->head->next = NULL;
	return OK;
}
Status EmptyQueue(LinkQueue *Q)
{
	if (Q->head == Q->tail)
		return TRUE;
	else
		return FALSE;
}
Status DelQueue(LinkQueue *Q, QElemType *e)
{
	
	QElemType *p = Q->head->next;
	if (!p)
		return ERROR;
	Q->head->next = p->next;
	*e = *p;
	free(p);
	if (Q->head->next == NULL)
		Q->tail = Q->head;
	return OK;
}
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QElemType* p = malloc(sizeof(QElemType));
	if (!p)
		return ERROR;
	else
	{
		*p = e;
		if (Q->head == Q->tail)
		{
			Q->head->next = p;
			Q->tail = p;
		}
		else
		{
			Q->tail->next = p;
			Q->tail = p;
		}
	}
	return OK;
}
int QueueLength(LinkQueue Q)
{
	int count = 0;
	if (Q.head == Q.tail)
		return 0;
	else
	{
		QElemType *p = Q.head->next;
		while (p)
		{
			count++;
			p = p->next;
		}
		return count;
	}
}
Status GetHead(LinkQueue *Q, QElemType *e)
{
	QElemType*p = Q->head->next;
	if (Q->head == Q->tail||!p)
		return ERROR;
	else
	{
		*e = *p;
	}
	return OK;
}
Status QueueTraverse(LinkQueue *Q)
{
	QElemType*p = Q->head->next;
	if (!p)
		printf("---IS empty\n");
		return ERROR;
	while (p)
	{
		printf("(%d,%d)", p->ArriveTime, p->Duration);
		p = p->next;
	}
	printf("\n");
	return OK;
}


int main()
{
	Bank_Simulation();
	return 0;
}
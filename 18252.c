#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define Q_LEN 2000001

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
}Node;

typedef struct _q {
	Node* front;
	Node* rear;
	int numOfData;
}Queue;

void QInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->numOfData = 0;
}

int QisEmpty(Queue* pq)
{
	if (pq->front == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void QPush(Queue* pq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;
	
	if (QisEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
		(pq->numOfData)++;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
		(pq->numOfData)++;
	}
}

Data QPop(Queue* pq)
{
	Node* DelNode;
	Data rdata;
	
	if (QisEmpty(pq))
	{
		return -1;
	}
	
	DelNode = pq->front;
	rdata = DelNode->data;
	pq->front = pq->front->next;
	
	free(DelNode);
	(pq->numOfData)--;
	return rdata;
}

int QSize(Queue* pq)
{
	return pq->numOfData;
}

Data QFront(Queue* pq)
{
	if (QisEmpty(pq))
	{
		return -1;
	}
	return pq->front->data;
}

Data QBack(Queue* pq)
{
	if (QisEmpty(pq))
	{
		return -1;
	}
	return pq->rear->data;
}

int main(void)
{
	Queue q;
	QInit(&q);
	char str[15];
	int n, i, num;
	
	scanf("%d", &n);
	getc(stdin);
	
	for ( i = 0; i < n; i++ )
	{
		gets(str);
		
		if (strncmp(str, "push", 4) == 0)
		{
			num = atoi(str+5);
			QPush(&q, num);
		}
		else if (strcmp(str, "pop") == 0)
		{
			printf("%d\n", QPop(&q));
		}
		else if (strcmp(str, "size") == 0)
		{
			printf("%d\n", QSize(&q));
		}
		else if (strcmp(str, "empty") == 0)
		{
			printf("%d\n", QisEmpty(&q));
		}
		else if (strcmp(str, "front") == 0)
		{
			printf("%d\n", QFront(&q));
		}
		else if (strcmp(str, "back") == 0)
		{
			printf("%d\n", QBack(&q));
		}
	}
	
	return 0;
}

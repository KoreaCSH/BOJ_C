#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
	struct _node* prev;
}Node;

typedef struct _dq {
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
}Deque;

void DQInit(Deque* pdq)
{
	pdq->head = NULL;
	pdq->tail = NULL;
	pdq->cur = NULL;
	pdq->numOfData = 0;
}

int DQisEmpty(Deque* pdq)
{
	if (pdq->head == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void DQAddFirst(Deque* pdq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = pdq->head;
	
	if (DQisEmpty(pdq))
	{
		pdq->tail = newNode;
	}
	else
	{
		pdq->head->prev = newNode;
	}
	(pdq->numOfData)++;
	pdq->head = newNode;
}

void DQAddLast(Deque* pdq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = pdq->tail;
	
	if (DQisEmpty(pdq))
	{
		pdq->head = newNode;
	}
	else
	{
		pdq->tail->next = newNode;
	}
	(pdq->numOfData)++;
	pdq->tail = newNode;
}

Data DQRemoveFirst(Deque* pdq)
{
	Node* DelNode;
	Data rdata;
	
	if (DQisEmpty(pdq))
	{
		return -1;
	}
	
	DelNode = pdq->head;
	rdata = DelNode->data;
	
	pdq->head = pdq->head->next;
	free(DelNode);
	if (pdq->head == NULL)
	{
		pdq->tail = NULL;
	}
	else
	{
		pdq->head->prev = NULL;
	}
	(pdq->numOfData)--;
	return rdata;
}

Data DQRemoveLast(Deque* pdq)
{
	Node* DelNode;
	Data rdata;
	
	if (DQisEmpty(pdq))
	{
		return -1;
	}
	
	DelNode = pdq->tail;
	rdata = DelNode->data;
	
	pdq->tail = pdq->tail->prev;
	free(DelNode);
	
	if(pdq->tail == NULL)
	{
		pdq->head = NULL;
	}
	else
	{
		pdq->tail->next = NULL;
	}
	(pdq->numOfData)--;
	return rdata;
}

Data DQGetFirst(Deque* pdq)
{
	if (DQisEmpty(pdq))
	{
		return -1;
	}
	return pdq->head->data;
}

int DQIdx(Deque* pdq, int target)
{
	int idx = 1;
	pdq->cur = pdq->head;
	
	while (1)
	{
		if (pdq->cur->data == target)
		{
			break;
		}
		pdq->cur = pdq->cur->next;
		idx++;
	}
	return idx;
}

void Func2(Deque* pdq)
{
	int num;
	num = DQRemoveFirst(pdq);
	DQAddLast(pdq, num);
}

void Func3(Deque* pdq)
{
	int num;
	num = DQRemoveLast(pdq);
	DQAddFirst(pdq, num);
}

int DQSize(Deque* pdq)
{
	return pdq->numOfData;
}

int main(void)
{
	Deque dq;
	DQInit(&dq);
	int n, m, i, target, idx, size;
	int count = 0;
	scanf("%d", &n);
	
	for ( i = 0 ; i < n ; i++ )
	{
		DQAddLast(&dq, i+1);
	}
	
	scanf("%d", &m);
	
	for ( i = 0 ; i < m ; i++ )
	{
		scanf("%d", &target);
		idx = DQIdx(&dq, target);
		size = DQSize(&dq);
		
		while(target != DQGetFirst(&dq))
		{
			if (idx-1 > size-idx+1)
			{
				Func3(&dq);
			}
			else
			{
				Func2(&dq);
			}
			count++;
		}
		DQRemoveFirst(&dq);
	}
	
	printf("%d", count);
	
	return 0;
}

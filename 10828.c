#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define STACK_LEN 10001

typedef int Data;

typedef struct _stack {
	Data stackArr[STACK_LEN];
	int topIndex;
} Stack;

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;
}

int isEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void SPush(Stack* pstack, int data)
{
	(pstack->topIndex)++;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{
	int ridx;
	if (isEmpty(pstack))
	{
		return -1;
	}
	
	ridx = pstack->topIndex;
	(pstack->topIndex)--;
	
	return pstack->stackArr[ridx];
}

int SSize(Stack* pstack)
{
	return pstack->topIndex + 1;
}

Data STop(Stack* pstack)
{
	if (isEmpty(pstack))
	{
		return -1;
	}
	return pstack->stackArr[pstack->topIndex];
}

int main(void)
{
	Stack stack;
	StackInit(&stack);
	
	int n, i, num;
	char func_name[15];
	scanf("%d", &n);
	getc(stdin);
	
	for ( i = 0 ; i < n; i++ )
	{
		gets(func_name);
		
		if ( strncmp(func_name, "push", 4) == 0 )
		{
			num = atoi(func_name+5);
			SPush(&stack, num);
		}
		else if ( strcmp(func_name, "pop") == 0 )  
		{
			printf("%d\n", SPop(&stack));
		}
		else if ( strcmp(func_name, "size") == 0 )
		{
			printf("%d\n", SSize(&stack));
		}
		else if ( strcmp(func_name, "empty") == 0 )
		{
			printf("%d\n", isEmpty(&stack));
		}
		else if ( strcmp(func_name, "top") == 0 )
		{
			printf("%d\n", STop(&stack));
		}
	}
	
	return 0;
}

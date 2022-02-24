#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101
#define TRUE 1
#define FALSE 0

typedef double Data;

typedef struct _stack {
	Data data[MAX];
	int topIndex;
}Stack;

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;
}

int isEmpty(Stack* pstack)
{
	if ( pstack->topIndex == -1 )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void SPush(Stack* pstack, Data data)
{
	(pstack->topIndex)++;
	pstack->data[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{
	int ridx;
	double rdata;
	
	if (pstack->topIndex == -1)
	{
		exit(-1);
	}
	
	ridx = pstack->topIndex;
	rdata = pstack->data[ridx];
	
	(pstack->topIndex)--;
	return rdata;
}

Data SPeek(Stack* pstack)
{
	if (pstack->topIndex == -1)
	{
		exit(-1);
	}
	return pstack->data[pstack->topIndex];
}

int isDigit(char tok)
{
	if ( tok >= 65 && tok <= 90 )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

double CalRPN(char exp[], double input[])
{
	Stack stack;
	StackInit(&stack);
	int explen = strlen(exp);
	int i;
	char tok, op1, op2;
	double num1, num2;
	
	for ( i = 0 ; i < explen ; i++ )
	{
		tok = exp[i];
		if ( isDigit(tok) )
		{
			SPush(&stack, input[tok-65]);
		}
		else
		{
			num2 = SPop(&stack);
			num1 = SPop(&stack);
			switch(tok)
			{
			case '+':
				SPush(&stack, num1+num2);
				break;
			case '-':
				SPush(&stack, num1-num2);
				break;
			case '*':
				SPush(&stack, num1*num2);
				break;
			case '/':
				SPush(&stack, num1/num2);
				break;
			}
		}
	}
	return SPop(&stack);	
}

int main(void)
{
	char exp[MAX];
	int n, i;
	double input[27];
	double result;
	
	scanf("%d", &n);
	
	scanf("%s", exp);
	
	for ( i = 0 ; i < n ; i++ )
	{
		scanf("%lf", &input[i]);
	}
	
	result = CalRPN(exp, input);
	
	printf("%.2f", result);
	
	return 0;
}

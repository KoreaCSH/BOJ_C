#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101
#define TRUE 1
#define FALSE 0

typedef int Data;

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
	if (pstack->topIndex == -1)
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
	pstack->topIndex += 1;
	pstack->data[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{
	int ridx;
	char rdata;
	
	if (isEmpty(pstack))
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
	if (isEmpty(pstack))
	{
		exit(-1);
	}
	return pstack->data[pstack->topIndex];
}

int GetOpPrec(char op)
{
	switch(op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	case ')':
		return 0;	
	}
	
	return -1;  // 등록되지 않은 연산자가 이 함수에 들어왔을 때 -1 반환. 
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);
	
	if ( op1Prec > op2Prec )
	{
		return 1;
	}
	else if ( op1Prec < op2Prec )
	{
		return -1;
	}
	else
	{
		return 0;  // 우선순위가 같다면 0 반환. 
	}
}

int isDigit(char num)
{
	if (GetOpPrec(num) == -1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void ConvToRPN(char exp[])
{
	Stack stack;
	int explen = strlen(exp);
	char* convExp = (char*)malloc(explen+1);
	
	int i, idx = 0;
	char tok, popOp;
	
	memset(convExp, 0, sizeof(char)*explen + 1);
	StackInit(&stack);
	
	for ( i = 0; i < explen; i++ )
	{
		tok = exp[i];
		
		if(isDigit(tok))
		{
			convExp[idx++] = tok;
		}
		else
		{
			switch(tok)
			{
			case '(':
				SPush(&stack, tok);
				break;
			case ')':
				while(1)
				{
					popOp = SPop(&stack);
					if (popOp == '(')
					{
						break;
					}
					convExp[idx++] = popOp;
				}
				break;
			case '*':
			case '/':
			case '+':
			case '-':
				while(isEmpty(&stack) != 1 && WhoPrecOp(SPeek(&stack), tok) >= 0)
				{
					popOp = SPop(&stack);
					convExp[idx++] = popOp;
				}
				SPush(&stack, tok);
				break;	
			}
		}
	}
	
	// stack에 남아있는 모든 연산자를 convExp로 옮긴다.
	while (!isEmpty(&stack))
	{
		convExp[idx++] = SPop(&stack);
	}
	
	strcpy(exp, convExp);
	free(convExp);
} 

int main(void)
{
	char exp[MAX];
	scanf("%s", exp);
	
	ConvToRPN(exp);
	
	printf("%s", exp);
	
	return 0;
}

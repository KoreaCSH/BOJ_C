#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	char data;
	struct _node* left;
	struct _node* right;
}Node;

Node* MakeTree(void)
{
	Node* nd = (Node*)malloc(sizeof(Node));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

Node* SearchNode(Node* bt, char data)
{
	if ( bt != NULL )
	{
		if ( bt->data == data )
		{
			return bt;
		}
		else
		{
			Node* btt = SearchNode(bt->left, data);
			if ( btt != NULL )
			{
				return btt;
			}
			return SearchNode(bt->right, data);
		}
	}
	return NULL;	
}

void SetData(Node* bt, char A, char B, char C)
{
	bt->data = A;
	
	if ( B != '.' )
	{
		Node* left_node = MakeTree();
		left_node->data = B;
		bt->left = left_node;
	}
	
	if ( C != '.' )
	{
		Node* right_node = MakeTree();
		right_node->data = C;
		bt->right = right_node;
	}
}

void PreorderTraverse(Node* bt)
{
	if ( bt == NULL )
	{
		return;
	}
	
	printf("%c", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void InorderTraverse(Node* bt)
{
	if ( bt == NULL )
	{
		return;
	}
	
	InorderTraverse(bt->left);
	printf("%c", bt->data);
	InorderTraverse(bt->right);	
}

void PostorderTraverse(Node* bt)
{
	if ( bt == NULL )
	{
		return;
	}
	
	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%c", bt->data);
}

int main(void)
{
	Node* bt = MakeTree();
	Node* temp;
	int N, i;
	char A, B, C;
	scanf("%d", &N);
	getchar();

	for ( i = 0 ; i < N ; i++ )
	{
		scanf("%c %c %c", &A, &B, &C);
		getchar();
		
		temp = SearchNode(bt, A);
		if ( temp != NULL )
		{
			SetData(temp, A, B, C);
		}
		else
		{
			SetData(bt, A, B, C);
		}
	}
	
	PreorderTraverse(bt);
	printf("\n");
	InorderTraverse(bt);
	printf("\n");
	PostorderTraverse(bt);
	
	return 0;
}

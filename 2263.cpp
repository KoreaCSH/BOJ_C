#include <iostream>

using namespace std;

int arr_in[100001];
int arr_post[100001];
int n;

void getPre(int inBegin, int inEnd, int postBegin, int postEnd)
{
	if(inBegin > inEnd || postBegin > postEnd)
	{
		return;
	}
	
	int r = arr_post[postEnd];
	int k;
	for(int i = inBegin; i <= inEnd; i++)
	{
		if(arr_in[i] == r)
		{
			k = i;
		}
	}
	
	int leftsize = k - inBegin;
	
	printf("%d ", r);
	
	getPre(inBegin, k-1, postBegin, postBegin + leftsize - 1);
	getPre(k+1, inEnd, postBegin + leftsize, postEnd-1);
}

int main(void)
{
	int i, j;
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr_in[i]);
	}
	
	for(j = 0; j < n; j++)
	{
		scanf("%d", &arr_post[j]);
	}
	
	getPre(0, n-1, 0, n-1);
	
	return 0;
}

#include <stdio.h>

#define MAX 1001

int max(int a, int b)
{
	if ( a > b )
	{
		return a;
	}
	else 
	{
		return b;
	}
}

int main(void)
{
	int n, i, j;
	int input[MAX];
	int dp[MAX];
	
	scanf("%d", &n);
	
	for ( i = 0 ; i < n ; i++ )
	{
		scanf("%d", &input[i]);
	}
	
	for ( i = 0 ; i < n ; i++ )
	{
		dp[i] = 1;  // �ڱ� �ڽŸ� �����ϴ� �κм����� ���̴� 1 
		for ( j = 0 ; j < i ; j++ )
		{
			if ( input[j] < input[i] ) //input[i] �� �� Ŭ ���� �κм����� �߰��� �� �����Ƿ� 
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		} 
	}
	
	int m = 0;
	
	// dp[n-1]�� return �� ��, ���� input[n-1]�� input[n-2] < input[n-1] �� ������� ���ߴٸ�, dp[n-1]�� 1�� �ȴ�.
	// �׷��Ƿ� dp[MAX] �߿� ���� ū ���� return �ؾ� �Ѵ�. 
	 
	for ( i = 0 ; i < n ; i++ )
	{
		if ( m < dp[i] ) 
		{
			m = dp[i];
		}
	}
		
	printf("%d", m);
		
	return 0;
}

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
		dp[i] = 1;  // 자기 자신만 포함하는 부분수열의 길이는 1 
		for ( j = 0 ; j < i ; j++ )
		{
			if ( input[j] < input[i] ) //input[i] 가 더 클 때만 부분수열에 추가할 수 있으므로 
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		} 
	}
	
	int m = 0;
	
	// dp[n-1]을 return 할 때, 만약 input[n-1]이 input[n-2] < input[n-1] 을 통과하지 못했다면, dp[n-1]은 1이 된다.
	// 그러므로 dp[MAX] 중에 가장 큰 수를 return 해야 한다. 
	 
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

#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main(void)
{
	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;
	
	int n, x;
	scanf("%d", &n);
	
	for ( int i = 0 ; i < n ; i++ )
	{
		scanf("%d", &x);
		if ( max_pq.size() == min_pq.size() )
		{
			max_pq.push(x);
		}
		else
		{
			min_pq.push(x);
		}
		
		if ( min_pq.size() == 0 )
		{
			printf("%d\n", max_pq.top());
			continue;
		}
		
		if ( max_pq.top() > min_pq.top() )
		{
			int temp1 = max_pq.top();
			int temp2 = min_pq.top();
			max_pq.pop();
			min_pq.pop();
			max_pq.push(temp2);
			min_pq.push(temp1);
		}
		
		printf("%d\n", max_pq.top());
	}
	
	return 0;
}

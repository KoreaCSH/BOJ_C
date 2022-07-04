#include <iostream>
#include <vector>

using namespace std;

int parent[100001];
vector<int> v[100001];
bool visited[100001];

void dfs(int r)
{
	visited[r] = true;
	for(int i = 0; i < v[r].size(); i++ )
	{
		int child = v[r][i];
		if ( !visited[child] )
		{
			parent[child] = r;
			dfs(child);
		}
	}
}

int main(void)
{
	int n, i, a, b;
	scanf("%d", &n);
	
	for ( i = 0; i < n-1; i++ )
	{
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	dfs(1);
	
	for( i = 2; i <= n; i++ )
	{
		printf("%d\n", parent[i]);
	}
	
	return 0;
}

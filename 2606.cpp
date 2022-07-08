#include <iostream>
#include <vector>

using namespace std;

vector<int> v[101];
bool visited[101];
int cnt = 0;

void bfs(int s)
{
	visited[s] = true;
	for(int i = 0; i < v[s].size(); i++)
	{
		int next = v[s][i];
		if( !visited[next] )
		{
			cnt++;
			bfs(next);
		}
	}
}

int main(void)
{
	int n, m, i, a, b;
	scanf("%d", &n);
	scanf("%d", &m);
	
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	bfs(1);
	
	printf("%d", cnt);
	
	return 0;
}

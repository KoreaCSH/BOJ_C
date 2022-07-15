#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
vector<int> v[100001];
int dist_ntok[100001];
bool visited[100001];

void make_adjlist()
{
	v[0].push_back(1);
	v[1].push_back(0);
	v[1].push_back(2);
	for(int i = 2; i < 100000; i++)
	{
		v[i].push_back(i-1);
		v[i].push_back(i+1);
		if(i <= 50000)
		{
			v[i].push_back(i*2);	
		}
	}
	v[100000].push_back(99999);
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start];
	dist_ntok[start] = 0;
	while(!q.empty())
	{
		start = q.front();
		q.pop(); 
		for(int i = 0; i < v[start].size(); i++)
		{
			int next = v[start][i];
			if(!visited[next])
			{
				q.push(next);
				visited[next] = true;
				dist_ntok[next] = dist_ntok[start] + 1;
			}
			if(dist_ntok[k] != 0)
			{
				return;
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &k);

	make_adjlist();
	
	bfs(n);
	
	if(n == k)
	{
		printf("%d", 0);
	}
	else
	{
		printf("%d", dist_ntok[k]);
	}
	
	return 0;
}

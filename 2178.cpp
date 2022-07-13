#include <iostream>
#include <queue>

using namespace std;

int n, m;
int graph[101][101] = {0, };
int s_distance[101][101] = {0, };
bool visited[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({y, x});
	s_distance[y][x] = 1;
	visited[y][x] = true;
	while(!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if( ny >= 0 && nx >= 0 && ny < n && nx < m && !visited[ny][nx] && graph[ny][nx] )
			{
				q.push({ny, nx});
				visited[ny][nx] = true;
				s_distance[ny][nx] = s_distance[y][x] + 1;
			}
		}
	}
}

int main(void)
{
	int i, j;
	cin >> n >> m;
	
	string k;
	for(i = 0; i < n; i++)
	{
		cin >> k;
		for(j = 0; j < m; j++)
		{
			graph[i][j] = k[j] - '0';
		}
	}
	
	bfs(0, 0);
	
	cout << s_distance[n-1][m-1];
	
	return 0;
}

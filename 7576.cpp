#include <iostream>
#include <queue>

using namespace std;

int m, n;
int arr[1001][1001] = {0, };
int tomato_date[1001][1001] = {0, };
bool visited[1001][1001];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;

void bfs(void)
{
	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny >= 0 && nx >= 0 && ny < n && nx < m && arr[ny][nx] == 0 && !visited[ny][nx])
			{
				q.push({ny, nx});
				visited[ny][nx] = true;
				tomato_date[ny][nx] = tomato_date[y][x] + 1;
			}
		}
	}
}

int main(void)
{
	int i, j, p;
	int max = 0;
	scanf("%d %d", &m, &n);
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			scanf("%d", &p);
			arr[i][j] = p;
			tomato_date[i][j] = p;
			if(arr[i][j] == 1)
			{
				q.push({i, j});
				visited[i][j] = true;
			}
		}
	}
	
	bfs();
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(tomato_date[i][j] == 0)
			{
				printf("%d", -1);
				return 0;
			}
			if(max < tomato_date[i][j])
			{
				max = tomato_date[i][j];
			}
		}
	}
	
	printf("%d", max-1);
	
	return 0;
}

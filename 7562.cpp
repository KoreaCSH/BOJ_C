#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int l, y, x, dy, dx;
bool visited[301][301];
int Nightmove[301][301];
int my[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int mx[8] = {-1, -2, 2, 1, 1, 2, -2, -1};

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({y, x});
	visited[y][x] = true;
	Nightmove[y][x] = 0;
	while(!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for(int i = 0; i < 8; i++)
		{
			int ny = y + my[i];
			int nx = x + mx[i];
			if(nx >= 0 && ny >= 0 && nx < l && ny < l && !visited[ny][nx])
			{
				q.push({ny, nx});
				visited[ny][nx] = true;
				Nightmove[ny][nx] = Nightmove[y][x] + 1;
			}
			if(Nightmove[dy][dx] != 0)
			{
				return;
			}
		}
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	
	for(int i = 0; i < t; i++)
	{
		scanf("%d", &l);
		scanf("%d %d", &y, &x);
		scanf("%d %d", &dy, &dx);
		
		if(y == dy && x == dx)
		{
			printf("%d\n", 0);
		}
		else
		{
			bfs(y, x);
			printf("%d\n", Nightmove[dy][dx]);
			memset(visited, false, sizeof(visited));
			memset(Nightmove, 0, sizeof(Nightmove));
		}
	}
	
	
	return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

int m, n;
int arr[51][51] = {0, };
bool visited[51][51];

void dfs(int r, int c)
{
	if(r < 0 || c < 0 || r >= m || c >= n || visited[r][c] || !arr[r][c])
	{
		return;
	}
	
	visited[r][c] = true;
	
	dfs(r-1, c);
	dfs(r, c+1);
	dfs(r+1, c);
	dfs(r, c-1);
}

int main(void)
{
	int t, k, i, j, r, c, x, y;
	int count = 0;
	
	scanf("%d", &t);
	
	for(i = 0; i < t; i++)
	{
		scanf("%d %d %d", &m, &n, &k);
		
		for(j = 0; j < k; j++)
		{
			scanf("%d %d", &x, &y);
			arr[x][y] = 1;
		}
		
		for(r = 0; r < m; r++)
		{
			for(c = 0; c < n; c++)
			{
				if(arr[r][c] == 1 && !visited[r][c])
				{
					dfs(r, c);
					count++;
				}
			}
		}
		
		printf("%d\n", count);
		count = 0;
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
	}
	
	return 0;
}

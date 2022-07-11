#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int g[26][26];
bool visited[26][26];
int n;

void dfs(int r, int c, int& k)
{
	if( r<0 || c<0 || visited[r][c] || !g[r][c] || r>=n || c>=n )
	{
		return;
	}
	
	visited[r][c] = true;
	k++;
	
	dfs(r-1, c, k);
	dfs(r, c+1, k);
	dfs(r+1, c, k);
	dfs(r, c-1, k);
	
}

int main(void)
{
	int i, j;
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		string x;
		cin >> x;
		for(j = 0; j < n; j++)
		{
			g[i][j] = x[j] - '0';
		}
	}
	
	int k = 0;
	vector<int> v;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			dfs(i, j, k);
			if(k != 0)
			{
				v.push_back(k);
			}
			k = 0;
		}
	}
	
	sort(v.begin(), v.end());
	
	cout << v.size() << endl;
	
	for(auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	
	return 0;
}

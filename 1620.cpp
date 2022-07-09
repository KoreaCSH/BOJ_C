#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

// string 비교는 <string>에 있는 compare 함수로. 같을 때 0 반환
// isdigit[char] 은 <cctype>에, stoi는 <string>에 내장되어 있다. 
// "시간초과"를 주의해야 하는 문제 

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	map<string, int> dict;
	string* pkm_name;
	int n, m, i;
	string k, t;
	
	cin >> n >> m;
	
	pkm_name = new string[n];
	
	for(i = 0; i < n; i++)
	{
		cin >> k;
		dict[k] = i+1;
		pkm_name[i] = k;
	}
	
	for(i = 0; i < m; i++)
	{
		cin >> t;
		if( isdigit(t[0]) )
		{
			cout << pkm_name[stoi(t)-1] << '\n';
		}
		else
		{
			auto it = dict.find(t);
			cout << it->second << '\n';
		}
	}
	
	return 0;
}

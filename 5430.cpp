#include <iostream>
#include <string>
#include <deque>

using namespace std;

// case 1
int count_D(string& p)
{
	int n = 0;
	for ( int i = 0; i < p.length(); i++ )
	{
		if ( p[i] == 'D')
		{
			n++;
		}
	}
	return n;
}

int main(void)
{
	int T, n_D, n;
	cin >> T;
	
	for ( int i = 0; i < T; i++ )
	{
		string p, x;
		cin >> p;
		n_D = count_D(p);
		deque<int> dq;
		
		cin >> n;
		
		string s = "";
		cin >> x;
		for ( int j = 0 ; j < x.length() ; j++ )
		{
			if ( isdigit(x[j]) )
			{
				s += x[j];
			}
			else
			{
				if ( !s.empty() )
				{
					dq.push_back(stoi(s));
					s = "";
				} 
			}
		}
		
		if ( n_D > n )
		{
			cout << "error" << endl;
			while ( !dq.empty() )
			{
				dq.pop_front();
			}
			continue;
		}
		
		bool R = false;
		
		for ( int z = 0 ; z < p.length(); z++ )
		{
			if ( p[z] == 'R' )
			{
				R = !R;
			}
			else if ( p[z] == 'D' )
			{
				if ( R )
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}
		
		cout << "[";
		if ( !R && !dq.empty() )
		{
			for ( deque<int>::iterator it = dq.begin(); it != dq.end(); it++ )
			{
				if ( it == dq.end()-1 )
				{
					cout << *it;
				}
				else
				{
					cout << *it << ",";
				}
			}
		}
		else if ( R && !dq.empty() )
		{
			for ( deque<int>::reverse_iterator it = dq.rbegin(); it != dq.rend(); it++ )
			{
				if ( it == dq.rend()-1 )
				{
					cout << *it;
				}
				else
				{
					cout << *it << ",";
				}
			}
		}
		cout << "]" << endl;
		
	}
	
	return 0;
}

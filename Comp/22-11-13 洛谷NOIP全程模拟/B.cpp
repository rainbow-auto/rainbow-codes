#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;
string s; 

namespace Sub1{
	const int maxn = 105;	

	string ans;
	int chosen[maxn];
	void dfs (int now)
	{
		if (now > k)
		{
			string ansnow = s;
			for (int i = 1; i <= k; i++)
			{
				swap (ansnow[chosen[i]], ansnow[chosen[i] + 1]);
			}
//			cout << ansnow << endl;
			ans = min (ans, ansnow);
			return;
		}
		
		for (int i = 0; i < n - 1; i++)
		{
			chosen[now] = i;
			dfs (now + 1);
			chosen[now] = 0;
		}
	}
	
	void solve ()
	{
		ans = s;
		memset (chosen, 0, sizeof (chosen)); 
		dfs (1);
		cout << ans << endl;
	}
} 

int c[27];
 
namespace Sub2{
	void solve ()
	{
		int cnt = 0;
		bool flag = false;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'a') continue;
			for (int j = i; j < s.size() - 1; j++)
			{
				if (s[j] == 'a')
				{
					for (int r = j; r > i; r--)
					{
						swap (s[r], s[r - 1]);
						cnt ++;
						if (cnt >= k)
						{
							flag = true;
							break;
						}
					}
					break;
				}
				if (flag == true) break;
			}
			if (flag == true) break;
		}
		
		cout << s << endl;
	}
} 
 
namespace Sub{
	void solve ()
	{
		int cnt = 0;
		while (true)
		{	
			bool flag = false;		
			for (int i = 0; i < s.size() - 1; i++)
			{
				if (s[i] > s[i + 1])
				{
					swap (s[i], s[i + 1]);
					cnt ++;
					flag = true;
					if (cnt >= k)
					{
						flag = false;
						break;
					}
				}
			}
			if (not flag)
			{
				break;
			}	
		}
		
		cout << s << endl;
	}
}


int main ()
{
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		c[s[i] - 'a'] ++; 
	}
	
//	for (int i = 'a' - 'a'; i <= 'z' - 'a'; i++)
//	{
//		cout << c[i] << endl;
//	}
	
	if (c[0] + c[1] == n)
	{
//		cout << "sub2" << endl;
		Sub2::solve ();
	}	
	else if (k <= 10 and k != 0)
	{
		Sub1::solve ();	
	}	
	else if (k == 0) 
	{
		cout << s << endl;	
	} 
	else
	{
		sort (s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}

/*
10 3
bababababa
*/


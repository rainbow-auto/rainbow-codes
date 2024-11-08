#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxn = 1005;

int n, k;
int T;

char myop[maxn];
char op[maxn][maxn];
bool t[maxn];

int main ()
{
	ios::sync_with_stdio (false);
	
	cin >> T;
	
	while (T--)
	{
		memset (t, 0, sizeof(t));
				
		cin >> n >> k;
		
		string ms;
		cin >> ms;
		for (int j = 1; j <= k; j++)
		{
			myop[j] = ms[j - 1];
		}		
		
		for (int i = 2; i <= n; i++)
		{
			string s;
			cin >> s;
			for (int j = 1; j <= k; j++)
			{
				if (s[j - 1] != myop[j])
				{
					t[i] = true;
				}
			}
		}
		
		int r = 0;
		for (int i = 1; i <= n; i++)
		{
			if (not t[i]) r++;
		}
		cout << r << endl;
	}
			
	return 0;
}


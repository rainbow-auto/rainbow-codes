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

const int maxx = 40000005;
const int maxn = 200005;

int t;
bool a[maxx];
int nxt[maxx];

int query[maxn];

inline bool check (int now)
{
	while (now)
	{
		if (now % 10 == 7) return false;
		now /= 10;		
	}
	return true;
} 

int n;
void pre ()
{
	memset (a, true, sizeof (a));
	int last = 0;
	for (int i = 1; i <= maxx; i++)
	{
		if (not a[i]) 
		{
			continue; 
		}
		if (not check (i)) 
		{
			for (int j = 1; i * j <= maxx; j++)
			{
				a[i * j] = false;
			}
		}
		else
		{
			nxt[last] = i;
			last = i;
		}
	}
}

void solve (int x)
{
	
	if (not a[x])
	{
		cout << -1 << endl;
	}
	else
	{
		cout << nxt[x] << endl;
	}
}

int main ()
{
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> query[i];
		n = max (n, query[i]);
	}
	
	pre ();
	for (int i = 1; i <= t; i++)
	{
		solve (query[i]);
	}
	
	return 0;
}


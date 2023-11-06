const int l = 6001;
const int r = 7000;

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

const int maxn = 1000005;
const int mod = 998244353;

typedef long long ll;

ll gcd (ll a, ll b)
{
	if (b == 0) return a;
	else return gcd (b, a % b);
}

ll n;

namespace Subtask1{
	inline ll cal (int n)
	{
		ll res = 0;
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= n; j++)
			{
				for (ll k = 1; k <= n; k++)
				{
					if (i + j + k != n) continue;
					(res += i * gcd (j, k) / gcd (i, gcd (j, k))) %= mod;
				}
			}
		}
		return res;
	}
	
	void solve (int n)
	{
		ofstream table ("E7.table");
		
		for (int i = l; i <= r; i++)
		{
			table << cal (i)  << ","; 
			if (i % 100 == 0) cout << "ok100" << endl;
		}
	}	
}

int main ()
{
	Subtask1::solve(1005);
		
	return 0;
}


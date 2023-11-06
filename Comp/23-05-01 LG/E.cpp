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
				if (i + j < n)
				{
					ll k = n - i - j;
					(res += i * gcd (j, k) / gcd (i, gcd (j, k))) %= mod;
				}
			}
		}
		return res;
	}
	
	void solve (int n)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << cal (i)  << " "; 
		}	
		cout << endl;
	}	
}

int main ()
{
	cin >> n;
	
	Subtask1::solve(n);
	
	return 0;
}


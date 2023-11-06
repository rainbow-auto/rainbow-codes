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

int n, k;
typedef unsigned long long ll; 

namespace Sub1{
	inline ll C (ll a, ll b)
	{
		ll ans = 1;
		for (ll i = 1; i <= b; i++)
		{
			ans *= (a - i + 1) % ll(1e9 + 7);
		}
		for (ll i = 1; i <= b; i++)
		{
			ans /= i;
		}
		if (b == 0) return 0;
		return ans % ll(1e9 + 7);
	}
	
	const int maxn = 10005;
	ll res[maxn * maxn];
	int cnt;
	
	inline bool cmp (ll x, ll y)
	{
		return x > y;
	}
	
	void solve ()
	{
		for (ll a = 0; a <= n; a++)
		{
			for (ll b = 0; b <= a; b++)
			{
				res[++cnt] = C(a, b);
//				cout << "C " << a << " " << b << " = " << C(a, b) << endl;
			}
		}
		sort (res + 1, res + cnt + 1, cmp);
		ll ans = 0;
		for (int i = 1; i <= k; i++)
		{
			ans += res[i];
			ans %= ll(1e9 + 7);
		}
		cout << ans << endl;
	}
}

int main ()
{
	cin >> n >> k;
//	if (n <= 10)
//	{
		Sub1::solve ();
//	}
	return 0;
}


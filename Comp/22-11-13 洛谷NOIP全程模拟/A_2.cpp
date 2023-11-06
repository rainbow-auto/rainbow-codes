#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

ll n, k;
ll ans = 0;

inline ll ceil (ll a, ll b)
{
	if (a % b == 0) return a / b;
	else return (a / b) + 1;
}

namespace Sub1{
	ll ans = 0;
	void solve (int now, int m)
	{
		ans ++;
		now -= k;
		if (now <= 0)
		{
			return;
		}
		if (now <= m / 2)
		{
			solve (now, now);
			solve (now, now);
		}
		else
		{
			solve (now, m);
		}
	}
	void abc ()
	{
		solve (n, n);
		cout << ans << endl;
	}
}

int main ()
{
	cin >> n >> k;
	
//	if (n <= 1000000)
//	{
//		Sub1::abc ();
//		return 0;
//	}
	
	ll s = ceil(n , k); 
	
	ll now = n;
	ans += s;
	now -= ceil(s , 2) * k;
	
	for (ll i = 1; ; i <<= 1)
	{
		ll add = ceil(now , k);
		ans += i * add;
		if (now == n / s)
		{
			break;
		}
		now -= ceil(add , 2) * k;
	}
	
	cout << ans << endl;
	
	return 0;
}


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 100005;

typedef long long ll;

int n, q;
ll a[maxn];
ll p, k;

ll mi[maxn];
ll ksm (ll x)
{
	if (mi[x]) return mi[x];
	ll base = k;
	ll ans = 1;
	while (x)
	{
		if (x & 1)
		{
			ans *= base;
			ans %= p;
		}
		base *= base;
		base %= p;
		x >>= 1;
	}
	mi[x] = ans;
	return ans;
}

int main ()
{
	fastread
	
	cin >> n >> q >> p >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	while (q--)
	{
		int opt, l, r;
		cin >> opt >> l >> r;
		if (opt == 1)
		{
			ll res = 0;
			for (int i = l; i <= r; i++)
			{
				res += a[i];
				res %= p;
			}
			cout << res << endl;
		}	
		else if (opt == 2)
		{
			for (int i = l; i <= r; i++)
			{
				a[i] = ksm (a[i]);
			}
		}
	}	
	
	return 0;
}

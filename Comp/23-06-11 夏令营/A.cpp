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

typedef long long ll;

const int maxn = 100005;
const ll mod = 1e9 + 7;

ll ksm (ll a, ll b)
{
	ll base = a;
	ll res = 1;
	while (b)
	{
		if (b & 1)
		{
			(res *= base) %= mod;
		}	
		(base *= base) %= mod;
		b >>= 1;
	}	
	return res;
}

int n;
ll a[maxn], x;

ll prefix[maxn];
ll suffix[maxn];
ll mul;

int ans = 0;
void solve (int L, int R)
{
	if (L > R)
	{
		return;
	}
	
	mul = 1;
	for (int i = L; i <= R; i++)
	{
		(mul *= a[i]) %= mod;
	}
	
	prefix[L - 1] = 1;
	for (int i = L; i <= R; i++)
	{
		prefix[i] = prefix[i - 1];
		(prefix[i] *= a[i]) %= mod;
	}
	
	suffix[R + 1] = 1;
	for (int i = R; i >= L; i--)
	{
		suffix[i] = suffix[i + 1];
		(suffix[i] *= a[i]) %= mod;
	}
	
	for (int i = L; i <= R; i++)
	{
		prefix[i] = ksm (prefix[i], mod - 2);
		suffix[i] = ksm (suffix[i], mod - 2);
	}
	
	for (int l = L; l <= R; l++)
	{
		for (int r = l; r <= R; r++)
		{
//			ll now = ksm(prefix[l - 1], mod - 2) * ksm(suffix[r + 1], mod - 2) * mul;
			ll now = mul;
			(now *= prefix[l - 1]) %= mod;
			(now *= suffix[r + 1]) %= mod;
			
			if (now == x) 
			{
				ans ++;
			}
		}
	}
}

int main ()
{
	cin >> n >> x;
	x %= mod;
	
	if (x == 0)
	{
		ll sum[maxn];
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] == 0) sum[i] = 1;
			else sum[i] = 0;
		}
		
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			sum[i] += sum[i - 1];
		}
		
		for (int len = 1; len <= n; len++)
		{
			for (int l = 1; l + len - 1 <= n; l++)
			{
				int r = l + len - 1;
				
				if (sum[r] - sum[l - 1] > 0)
				{
					ans ++;
				}
			}
		}
	}
	else
	{
		int last = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] == 0)
			{
				solve (last + 1, i - 1);
				last = i;
			}
		}
		
		if (last == 0)
		{
			solve (1, n);	
		}
	}
	
	cout << ans << endl;
	return 0;
}


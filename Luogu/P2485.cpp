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
#define endl "\n"

using namespace std;

typedef long long ll;

ll ksm (ll a, ll b, ll p)
{
	ll res = 1;
	ll base = a;
	while (b)
	{
		if (b & 1) (res *= base) %= p;	
		(base *= base) %= p;
		b >>= 1;
	} 
	return res;
}

ll exgcd (ll a, ll b, ll& x, ll& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	
	ll g = exgcd (b, a % b, y, x);
	y -= (a / b) * x;
	return g;	
}

ll bsgs (ll a, ll b, ll p)
{
	if (a == 0 and b == 0) return 1; // 注意特判a为p的倍数的情况
	if (a == 0 and b != 0) return -1;
	
	map<ll, ll> hash; hash.clear();
	ll m = ceil(sqrt(p));
	ll curr = 1;	
	for (ll i = 1; i <= m; i++)
	{
		(curr *= a) %= p;
		hash[curr * b % p] = i;  
	}
	
	ll now = curr;
	for (ll i = 1; i <= m; i++)
	{
		if (hash.count(now) and i * m - hash[now] > 0)
		{
			return i * m - hash[now]; 
		}
		(now *= curr) %= p; 
	}
	return -1;
}

int main ()
{
	fastread
	
	int T, k;
	cin >> T >> k;

	if (k == 1)
	{
		while (T--)
		{
			ll y, z, p;
			cin >> y >> z >> p;
			cout << ksm (y, z, p) << endl;			
		}
	}
	else if (k == 2)
	{
		while (T--)
		{
			ll a, b, p;
			cin >> a >> b >> p;
			
			ll x, y;
			ll g = exgcd (a, p, x, y);
			
			if (b % g != 0)
			{
				cout << "Orz, I cannot find x!" << endl;
				continue;	
			}  
			
			// 目标：ax+by = p 
			
			// ax + by = gcd (a, b)
			// (p/gcd(a,b)) * ax + (p/gcd(a,b)) * by = (p/gcd(a,b)) * gcd (a, b)
			// (p/gcd(a,b)) * ax + (p/gcd(a,b)) * by = p
						
			ll temp = p / g;
			while (x < 0) x += temp;
			ll res = ((x * b / g) % temp + temp) % temp;
			cout << res << endl;						
		}
	}
	if (k == 3)
	{
		while (T--)
		{
			ll y, z, p;
			cin >> y >> z >> p;
			y %= p;
			z %= p;
			
			ll res = bsgs (y, z, p);
			if (res == -1) cout << "Orz, I cannot find x!" << endl;
			else cout << res << endl;
		}
	}
		
	return 0;
}

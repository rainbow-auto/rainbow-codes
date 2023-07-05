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

using namespace std;

namespace Reader
{
	long long read ()
	{
		char c = getchar ();
		long long x = 0, flag = 1;
		while (not isdigit (c))
		{
			if (c == '-') flag = -1;
			c = getchar();
		}
		while (isdigit (c))
		{
			x = x * 10 + c - '0';
			c = getchar();
		}
		return x * flag;
	}
}

typedef __int128 ll;
const int maxn = 100005;
int n;

struct Equation{
	ll m, r;
	bool ok;
};

Equation eq[maxn];

namespace exCRT{
	ll gcd (ll a, ll b)
	{
		if (not b) return a;
		else return gcd (b, a % b);
	}	
	
	ll lcm (ll a, ll b)
	{
		return a * b / gcd (a, b);
	}
	
	ll exgcd (ll a, ll b, ll& x, ll& y)
	{
		if (not b)
		{
			x = 1, y = 0;
			return a;
		}
		ll res = exgcd (b, a % b, y, x);
		y -= a / b * x;
		return res;
	}
	
	Equation merge (Equation e1, Equation e2)
	{
		ll r1 = e1.r, m1 = e1.m;
		ll r2 = e2.r, m2 = e2.m;
		
		ll x, y;
		ll d = exgcd (m1, m2, x, y);
		
		if ((r2 - r1) % d != 0) return Equation{0, 0, false}; // 无解
		
		ll t0 = (r2 - r1) / d * x % (m2 / d);
		if (t0 < 0) t0 += (m2 / d);
		
		ll em = lcm (m1, m2);
		ll er = (t0 * m1 + r1) % em;
		if (er < 0) er += em;
		
		return Equation{em, er, true};
	}
	
	ll exCRT ()
	{
		Equation curr = eq[1];
		for (int i = 2; i <= n; i++)
		{
			curr = merge (curr, eq[i]);
			if (not curr.ok) return -1;
		}
		return curr.r % curr.m;
	}
}

int main ()
{
	n = Reader::read ();
	
	for (int i = 1; i <= n; i++)
	{
		eq[i].m = Reader::read();
		eq[i].r = Reader::read();
	}
	cout << (long long)exCRT::exCRT() << endl;
	
	return 0;
}
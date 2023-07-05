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
#include <cassert>

using namespace std;

namespace Reader{
	long long read ()
    {
        char c = getchar (); 
        long long x = 0, flag = 1;
        while (not isdigit (c)) { if (c == '-') flag = -1; c = getchar(); }
        while (isdigit (c)) { x = x * 10 + c - '0'; c = getchar(); }
        return x * flag;
    }
}

typedef __int128 ll;
const int maxn = 100005;

int n;

ll a[maxn], b[maxn];

namespace exCRT {
	
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
	
	ll gcd (ll a, ll b)
	{
	    if (not b) return a;
	    else return gcd (b, a % b);
	}
	
	ll lcm (ll a, ll b)
	{
		return a / gcd (a, b) * b;
	}
	
	ll a, b, A, B;
	ll x, y;
	void merge ()
	{
		ll g = exgcd (a, A, x, y);
		ll c = B - b;	

		if (c % g != 0) return;		
		
		x = x * c / g % (A / g);
		if (x < 0) x += A / g; 
		
		ll mod = lcm (a, A);
		b = (a * x + b) % mod;
		if (b < 0) b += mod; 
				
		a = mod;
	} 
	
	ll excrt ()
	{
		for (int i = 1; i <= n; i++)
		{
			A = ::a[i];
			B = ::b[i];
			if (i > 1)
			{
				merge ();
			}
			else
			{
				a = A;
				b = B;	
			}
		}
		return b % a;
	}
}

int main ()
{
    n = Reader::read();
    
    for (int i = 1; i <= n; i++)
    {
        a[i] = Reader::read();
        b[i] = Reader::read();
    }

    cout << (long long) exCRT::excrt () << endl;

    return 0;
}
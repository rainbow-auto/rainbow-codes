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

typedef __int128 ll;

ll get_128 ()
{
	ll res = 0;
	int flag = 1;
	char ch = getchar ();
	while (not isdigit(ch))
	{
		if (ch == '-')
		{
			flag = -1;
		}
		ch = getchar();
	}	
	while (isdigit(ch))
	{
		res = (res * 10) + ch - '0';
		ch = getchar();
	}
	return res * flag;
}

void print (ll val)
{
	if (val == 0) return;
	print (val / 10);
	cout << int(val % 10);
}

ll bsgs (ll a, ll b, ll p)
{
	a %= p; b %= p;
	if (a == 0 and b == 0) return 0;
	if (a == 0) return -1;
	
	ll t = ceil (sqrt((long long)p));
	ll now = 1ll;
	
	map <ll, ll> hash;
	for (int i = 1; i <= t; i++)
	{
		(now *= a) %= p;
		hash[now * b % p] = i;
	}	
	
	ll curr = now;
	
	for (int i = 1; i <= t; i++)
	{
		if (hash.count(curr))
		{
			return i * t - hash[curr];
		}
		(curr *= now) %= p;
	}
	
	return -1;
}


int main ()
{
	fastread

	ll k, m;
	k = get_128(); m = get_128();
	k *= 9; k += 1;
	
	print(bsgs (10, k, m));
	
	return 0;
}

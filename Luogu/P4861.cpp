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

ll gcd (ll a, ll b)
{
	if (b == 0) return a;
	else return gcd (b, a % b);
}

ll bsgs (ll a, ll b, ll p)
{
	map <ll, ll> hash;
	hash.clear();
	
	ll curr = 1;
	ll m = ceil(sqrt(p));
	for (ll i = 1; i <= m; i++)
	{
		(curr *= a) %= p;
		hash[curr * b % p] = i;
	}
	
	ll now = curr;
	for (ll i = 1; i <= m; i++)
	{
		map <ll, ll>::iterator it = hash.find(now);
		if (it != hash.end() and m * i - it->second > 0) return m * i - it->second; 
		(now *= curr) %= p;
	}
	return -1;
}

int main ()
{
	fastread
	
	ll K, M;
	cin >> M >> K;
	ll res = bsgs (K, 1, M);	
	if (gcd (K, M) != 1 or res == -1) cout << "Let's go Blue Jays!" << endl;
	else cout << res << endl; 
		
	return 0;
}

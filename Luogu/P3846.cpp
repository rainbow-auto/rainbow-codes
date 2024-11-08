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

ll BSGS (ll a, ll b, ll p) // ���Ϲ��� qwq
{
	map<ll, ll> hash; // hash ��
	hash.clear();
	ll curr = 1;
	ll m = sqrt (p) + 1; // ����p
	
	// a ^ x \equiv b (\bmod p)
	// a ^ {m * i} \equiv b * a ^ j (\bmod p)
	for (ll j = 1; j <= m; j++) // ����ұ� 
	{
		(curr *= a) %= p;
		hash[curr * b % p] = j;		
	}
	
	// curr��ʱ������a ^ m
	ll now = curr; // ll now = a ^ m
	for (ll i = 1; i <= m; i++) // i : 1 ~ P/m m = sqrt(P) 
	{
		map<ll, ll>::iterator it = hash.find(now);
		if (it != hash.end()) return i * m - it -> second;
		(now *= curr) %= p; // now = a ^ {m * i} = (a ^ m) ^ i = curr ^ i
	}
	
	return -1;
} 

int main ()
{
	fastread
	
	ll a, b, p;
	cin >> p >> a >> b;
	
	ll res = BSGS (a, b, p);
	
	if (res == -1)
	{
		cout << "no solution" << endl;	
	}	
	else 
	{
		cout << res << endl;
	}
	
	return 0;
}

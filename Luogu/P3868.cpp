// 大数翻倍法

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
const int maxn = 25; 

ll p, a;

ll gcd (ll a, ll b)
{
	if (b == 0)
	{
		return a;	
	}	
	return gcd (b, a % b);
} 

void merge (ll p1, ll a1, ll p2, ll a2, ll& p, ll& a) // 合并两个同余方程 
{
	if (p1 < p2) swap (p1, p2), swap (a1, a2);
	p = p1 / gcd (p1, p2) * p2;
	
	while (a1 <= p and a1 % p2 != a2)
	{
		a1 += p1;
	}
	
	if (a1 > p) // 无解 从a1 <= p 跳出的循环 
	{
		a = -1;
		p = -1;
	}
	else
	{
		a = a1;
	}
}

int n;
ll A[maxn], B[maxn];	

int main ()
{
	fastread
	
	cin >> n;	
	
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> B[i];
		A[i] = (A[i] % B[i] + B[i]) % B[i];
	}
	
	p = B[1];
	a = A[1];
		
	for (int i = 2; i <= n; i++)
	{
		// p     a
		merge (p, a, B[i], A[i], p, a);
		if (p == -1 and a == -1) return 0;
	}
	
	cout << a << endl;	
	
	return 0;
}

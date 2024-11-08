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

#define int long long

const int maxn = 5;
const int mod = 1e9 + 7;

struct Matrix{
	int n, m;
	int a[maxn][maxn];
	
	Matrix (int _n, int _m)
	{
		n = _n;
		m = _m;
		memset (a, 0, sizeof (a)); 
	}
	
	inline void indently()
	{
		for (int i = 1; i <= n; i++)
		{
			a[i][i] = 1;
		}
	}
	
	inline int* operator [] (int i)
	{
		return a[i];	
	} 
	
}; 

inline Matrix operator * (Matrix a, Matrix b)
{
	Matrix c(a.n, b.m);
	
	for (int i = 1; i <= c.n; i++)
	{
		for (int j = 1; j <= c.m; j++)
		{
			for (int k = 1; k <= a.m; k++) // a.m == b.n
			{
				(c[i][j] += a[i][k] * b[k][j]) %= mod;
			}
		}
	}
	return c;
} 

inline Matrix operator ^ (Matrix a, int b)
{
	Matrix base = a;
	Matrix res(a.n, a.m); res.indently();

	while (b)
	{
		if (b & 1) res = res * base;
		base = base * base;
		b >>= 1;	
	}	
	return res;
}

signed main ()
{
	int n;
	cin >> n;
	
	if (n <= 2)
	{
		cout << 1 << endl;	
	}	
	else
	{
		Matrix a(1, 2);
		Matrix b(2, 2);
	
		a[1][1] = 1; a[1][2] = 1; // f[1] = f[2] = 1
		
		b[1][1] = 1; b[1][2] = 1;
		b[2][1] = 1; b[2][2] = 0;
		
		Matrix res = a * (b ^ (n - 2));
		cout << res[1][1] << endl;		
	}
		
	return 0;
}

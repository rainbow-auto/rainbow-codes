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

const int maxn = 10;
const int mod = 1000;

struct Matrix{
	int n, m;
	int a[maxn][maxn];
	
	Matrix (int _n, int _m)
	{
		n = _n;
		m = _m;
		memset (a, 0, sizeof (a));
	}
	
	int* operator[] (int i)
	{
		return a[i];	
	} 
	
	void identity ()
	{
		for (int i = 1; i <= n; i++)
		{
			a[i][i] = 1;
		}	
	}	
};

Matrix g(8, 8);

Matrix operator * (Matrix a, Matrix b)
{
	Matrix c(a.n, b.m);
	for (int i = 1; i <= c.n; i++)
	{
		for (int k = 1; k <= a.m; k++) // a.m == b.n
		{
			for (int j = 1; j <= c.m; j++) // faster
			{
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
			}
		}
	}
	
	return c;
}

Matrix operator ^ (const Matrix& a, int b)
{
	Matrix res(a.n, a.m); res.identity();
	Matrix base = a;
	
	while (b)
	{
		if (b & 1) res = res * base;
		b >>= 1;
		base = base * base;
		
	}
	return res;
}

void make_graph ()
{
	for (int i = 1; i <= 8; i++)
	{
		g.a[i + 1][i] = g.a[i][i + 1] = 1;
	}
	g.a[1][8] = g.a[8][1] = 1; 
	
	// 到E以后不会再换车
	for (int j = 1; j <= 8; j++)
	{
		g.a[5][j] = 0; // 使g没有出边 
	}
}

int main ()
{
	fastread
	
	make_graph ();

	int n;
	cin >> n;
	g = g ^ n;
	
	cout << g.a[1][5] << endl;
		
	return 0;
}

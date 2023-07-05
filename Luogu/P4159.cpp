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

const int maxn = 105; // n * 10
const int mod = 2009;

struct Matrix{
	int a[maxn][maxn];
	int n, m;
	
	Matrix ()
	{
		memset (a, 0, sizeof (a));
		n = m = 0;
	}
	
	Matrix (int _n, int _m) // 单位元 
	{
		n = _n;
		m = _m;
		
		memset (a, 0, sizeof (a)); 
		for (int i = 1; i <= n; i++)
		{
			a[i][i] = 1;
		}
	}
};

Matrix g;

Matrix operator * (const Matrix& a, const Matrix& b)
{
	Matrix c;
	c.n = a.n;
	c.m = b.m; 
	for (int i = 1; i <= c.n; i++)
	{
		for (int k = 1; k <= a.m; k++) // a.m == b.n
		{
			for (int j = 1; j <= c.m; j++) // faster
			{
				c.a[i][j] += a.a[i][k] * b.a[k][j];
			}	
		}
	}
	
	for (int i = 1; i <= c.n; i++)
	{
		for (int j = 1; j <= c.m; j++)
		{
			c.a[i][j] %= mod;
		}
	}
	
	return c;
}

Matrix operator ^ (const Matrix& a, int b)
{
	Matrix base = a;
	Matrix res (a.n, a.m); // 单位元 
	while (b)
	{
		if (b & 1)
		{
			res = res * base;
		}	
		base = base * base;
		b >>= 1;
	}	
	return res;
}

namespace Solution {
	
	int n, t;
	inline int id (int u, int j)
	{
		return u + j * n;
	}
	
	void solve ()
	{
		cin >> n >> t;
		
		int m = n * 9;
		g.n = m;
		g.m = m;
		
		for (int i = 1; i <= n; i ++)
		{
			char s[maxn];
			cin >> s + 1;
			
			for (int j = 1; j <= n; j++)
			{
				char now = s[j];
				if (now != '0')
				{
					g.a[i][id(j, now - '0' - 1)] = 1;					
				}
				
			}
			
			for (int j = 1; j <= 8; j++)
			{
				g.a[id(i, j)][id(i, j - 1)] = 1;
			}
		}
		
		g = g ^ t;
		
		cout << g.a[1][n] << endl;	
	}	
		
}

int main ()
{
	fastread
	
	Solution::solve();
	
	return 0;
}

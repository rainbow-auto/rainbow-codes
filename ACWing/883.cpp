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

const double eps = 1e-6;
const int maxn = 105;

int n;
double a[maxn][maxn];

int gauss ()
{
	int r = 0;
	for (int c = 0; c < n; c ++)
	{
		int t = r;
		for (int i = r; i < n; i++)
		{
			if (fabs (a[i][c]) > fabs (a[t][c]))
			{
				t = i;
			}
		}
		
		if (fabs (a[t][c]) < eps) continue;
		
		for (int i = c; i < n + 1; i++) swap (a[t][i], a[r][i]);
		for (int i = n; i >= c; i--) a[r][i] /= a[r][c];
		for (int i = r + 1; i < n; i++)
		{
			if (fabs (a[i][c]) > eps)
			{
				for (int j = n; j >= c; j--)
				{
					a[i][j] -= a[r][j] * a[i][c];
				}
			}
		}
		
		r++;
	}
	
	if (r < n)
	{
		for (int i = r; i < n; i++)
		{
			if (fabs (a[i][n]) > eps)
			{
				return 1; // No solution
			}
		}
		return 2; // Infinite group solutions
	}
	
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			a[i][n] -= a[j][n] * a[i][j];
		}
	}
		
	return 3;
}

int main ()
{
    cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cin >> a[i][j];
		}
	}
	
	int flag = gauss();
	
	if (flag == 1)
	{
		cout << "No solution" << endl;
	}
	else if (flag == 2)
	{
		cout << "Infinite group solutions" << endl;
	}
	else if (flag == 3)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i][n] < eps and a[i][n] > -eps) printf ("0.00\n");  
			else printf ("%.2lf\n", a[i][n]);
		}
	}
	
	return 0;
}
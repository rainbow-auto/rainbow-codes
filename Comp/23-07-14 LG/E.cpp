#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxn = 3005;

#define int long long

int n, m, k;
int a[maxn][maxn];
int sum[maxn][maxn]; 
int check (int x)
{
	memset (sum, 0, sizeof (sum));	
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j] - x;
		}
	}
	
	int k_now = 0; 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] - x >= sum[i][m] - sum[i - 1][m] + sum[n][j] - sum[n][j - 1])
			{ 
				k_now ++;
			}
		}	
	}	
	
	return k_now;
}

signed main ()
{
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	
	int l = 0, r = 1e11; 
	//cout<<l<<" "<<r<<'\n';
	int ans = 0;	
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check (mid)>=k)
		{
			ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;	
		}
	}
	
	cout << ans << endl;
	
	return 0;
}


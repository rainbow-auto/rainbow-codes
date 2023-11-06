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

#define int long long

const int maxn = 500005; 

int n;
int a[maxn], b[maxn];

bool check (int k)
{
	int max_dis = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		max_dis = max (max_dis, a[i] + b[i] + k);
		if (max_dis < a[i + 1]) return false;
	}
	return true;
}

signed main ()
{
	cin >> n;
	
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		r = max (r, a[i]);
	}
	
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check (mid))
		{
			r = mid - 1;
			ans = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << ans << endl;	
		
	return 0;
}


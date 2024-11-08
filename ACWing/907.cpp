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

const int maxn = 100005;
int n;

struct Range{
	int l, r;
	friend bool operator < (Range a, Range b)
	{
		return a.l < b.l;
	}
};
Range ranges[maxn];

int st, ed;

int main ()
{
	fastread
	
	cin >> st >> ed;
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> ranges[i].l >> ranges[i].r;
	
	sort (ranges + 1, ranges + n + 1);	

	bool success = false;
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int t = i;
		int r = -2e9;
		while (t <= n and ranges[t].l <= st)
		{
			r = max (r, ranges[t].r);
			t ++;
		}
		
		if (r < st)
		{
			res = -1;
			break;	
		}
		
		res ++;
		if (r >= ed) 
		{
			success = true;
			break;
		}
		
		st = r;
		i = t - 1;
	}
	if (not success) cout << -1 << endl;
	else cout << res << endl;
	
	return 0;
}
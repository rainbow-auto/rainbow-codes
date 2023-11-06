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

using namespace std;

const int maxn = 200005;
int n;
int a[maxn];
int c;

int main ()
{
	fastread
	
	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sort (a + 1, a + n + 1);
	
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += upper_bound (a + 1, a + n + 1, a[i] - c) - lower_bound (a + 1, a + n + 1, a[i] - c);
	}
	cout << res << endl;
	
	return 0;	
}
	
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

#define file(fn) freopen( #fn".in", "r", stdin); freopen ( #fn".out", "w", stdout);
#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 100005;

int n;
int a[maxn];

int main ()
{
	fastread
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sort (a + 1, a + n + 1);
	int x = a[n / 2 + 1];
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += abs (x - a[i]);
	}
	
	cout << ans << endl;
		
	return 0;
}
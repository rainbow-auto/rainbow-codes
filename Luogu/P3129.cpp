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
int a[maxn];
bool vis[maxn];

set <int> s_min; // 小的在前
set <int> s_max; // 大的在前

int f[maxn], g[maxn];

int main () {
	fastread

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		vis[a[i]] = true;
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (vis[i]) { continue; }
		s_min.insert (i);
		s_max.insert (-i);
	}

	// 正序, 计算f
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		
		auto now = s_min.lower_bound (a[i]);
		if (now != s_min.end ()) { s_min.erase (now); f[i]++; }
	}

	// 倒序, 计算g
	for (int i = n; i >= 1; i--) {
		g[i] = g[i + 1];

		auto now = s_max.lower_bound (-a[i]); 
		if (now != s_max.end ()) { s_max.erase (now); g[i]++; }
	}

	int ans = g[1]; // 以第一个点作为开始
	for (int i = 1; i <= n; i++) {
		ans = max (ans, f[i] + g[i + 1]);
	}

	cout << ans << endl;

	return 0;
}

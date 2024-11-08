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

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 105;

const int dx[] = { 0, 1, -1, 0 };
const int dy[] = { 1, 0, 0, -1 };

int n, m;

int a[maxn][maxn];
bool vis[maxn][maxn];

void dfs (int x, int y) {
	vis[x][y] = true;

	for (int i = 0; i < 4; i++) {
		if (vis[x + dx[i]][y + dy[i]]) { continue; }
		if (not a[x + dx[i]][y + dy[i]]) { continue; }
		dfs (x + dx[i], y + dy[i]);
	}
} 

int main () {
	fastread

	std::cin >> n >> m;

	memset (vis, 1, sizeof (vis));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char x; std::cin >> x;
			a[i][j] = x - '0';
			vis[i][j] = false;
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (not vis[i][j] and a[i][j] > 0) { ans ++; dfs (i, j); }
		}
	}

	std::cout << ans << "\n";

	return 0;
}

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

const int dx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, -1, -1, 1 };

int n, m;
char a[maxn][maxn];

bool vis[maxn][maxn];

void dfs (int x, int y) {
	if (vis[x][y]) { return; }
	vis[x][y] = true;
	if (a[x][y] == '.') { return; }

	for (int i = 0; i < 8; i++) {
		int px = x + dx[i];
		int py = y + dy[i];

		dfs (px, py);
	}
}

int main () {
	fastread
	
	std::cin >> n >> m;

	memset (vis, 1, sizeof (vis));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
			vis[i][j] = false;
		}
	}

	int tot = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (not vis[i][j] and a[i][j] == 'W') { tot ++; dfs (i, j); }
		}
	}

	std::cout << tot << "\n";

	return 0;
}

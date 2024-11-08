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

const int maxn = 205;

int n, m;

int a[maxn][maxn];

struct Node {
	int l, r;
	int white, black;
	int fa_l[maxn], fa_r[maxn];
} tr[maxn << 2];

int fa[maxn * maxn];

inline int getID (int i, int j) {
	return (i - 1) * n + j;
}

int find (int x) {
	if (fa[x] == x) { return fa[x]; }
	return fa[x] = find (fa[x]);
}

inline void merge (int x, int y) {
	if (rand () & 1) { fa[x] = y; }
	else { fa[y] = x; }
}

inline void pushUp (int now) {
	tr[now].l = tr[now << 1].l; tr[now].r = tr[now << 1 | 1].r;

	for (int i = 1; i <= n; i++) { 
		tr[now].fa_l[i] = tr[now << 1].fa_l[i]; 
		tr[now].fa_r[i] = tr[now << 1 | 1].fa_r[i];
	}

	// 并查集重新初始化
	for (int i = 1; i <= n; i++) {
		fa[tr[now << 1].fa_l[i]] = tr[now << 1].fa_l[i];
		fa[tr[now << 1].fa_r[i]] = tr[now << 1].fa_r[i];
		fa[tr[now << 1 | 1].fa_l[i]] = tr[now << 1 | 1].fa_l[i];
		fa[tr[now << 1 | 1].fa_r[i]] = tr[now << 1 | 1].fa_r[i];
	}

	tr[now].black = tr[now << 1].black + tr[now << 1 | 1].black;
	tr[now].white = tr[now << 1].white + tr[now << 1 | 1].white;

	int mid = (tr[now].l + tr[now].r) >> 1; // 交界处

	for (int i = 1; i <= n; i++) {
		if (a[mid][i] != a[mid + 1][i]) { continue; }

		int x = find (tr[now << 1].fa_r[i]);
		int y = find (tr[now << 1 | 1].fa_l[i]);

		if (x == y) { continue; }

		merge (x, y);

		if (a[mid][i] == 0) { tr[now].white --; }
		if (a[mid][i] == 1) { tr[now].black --; }
	}

	for (int i = 1; i <= n; i++) {
		tr[now].fa_l[i] = find (tr[now].fa_l[i]);
		tr[now].fa_r[i] = find (tr[now].fa_r[i]);
	}
}

// 重新暴力计算第x行的连通块
inline void calc (int now, int i) { // i 表示行
	for (int j = 1; j <= n; j++) { tr[now].fa_l[j] = tr[now].fa_r[j] = fa[getID (i, j)] = getID (i, j); } // 并查集初始化

	tr[now].white = tr[now].black = 0;
	a[i][0] = -1; // 使得 a[i][1] 不可能等于 a[i][0]
	for (int j = 1; j <= n; j++) { // 统计连通块
		if (a[i][j] == a[i][j - 1]) { 
			tr[now].fa_l[j] = tr[now].fa_r[j] = fa[getID (i, j)] = fa[getID (i, j - 1)];
		} else {
			if (a[i][j] == 0) { tr[now].white ++; }
			if (a[i][j] == 1) { tr[now].black ++; }
		}
	}
}

void build (int now, int l, int r) {
	tr[now].l = l; tr[now].r = r;

	if (l == r) { calc (now, l); return; }

	int mid = (l + r) >> 1;

	build (now << 1, l, mid);
	build (now << 1 | 1, mid + 1, r);

	pushUp (now);
}

void modify (int now, int i) {
	if (tr[now].l == tr[now].r) { calc (now, i); return; }

	int mid = (tr[now].l + tr[now].r) >> 1;
	
	if (i <= mid) { modify (now << 1, i); }
	if (i > mid) { modify (now << 1 | 1, i); }

	pushUp (now);
}

int main () {
	fastread
	
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> a[i][j];
		}
	}

	build (1, 1, n);

	std::cin >> m;

	for (int i = 1; i <= m; i++) {
		int x, y; std::cin >> x >> y;

		a[x][y] = !a[x][y];

		modify (1, x);

		std::cout << tr[1].black << " " << tr[1].white << "\n";
	}

	return 0;
}

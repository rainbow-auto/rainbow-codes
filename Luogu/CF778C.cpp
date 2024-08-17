#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

const int maxn = 600005;

int n;
int ch[maxn][26], tot;

int merge (int x, int y) {
	if (not x or not y) { return x | y; }

	int now = ++tot; // 新建节点
	rep (i, 0, 25) { ch[now][i] = merge (ch[x][i], ch[y][i]); }
	return now;
}

int siz[maxn];

void dfs (int now, int dep) {
	int root = ++tot;
	rep (i, 0, 25) { if (ch[now][i]) { root = merge (root, ch[now][i]); } }

	siz[dep] += (tot - 1) - n; // tot - 1 : 去除 root
	tot = n; // 清空合并过程中新建的所有节点

	rep (i, 0, 25) { if (ch[now][i]) { dfs (ch[now][i], dep + 1); } }
}

int main () {
	fastread

	std::cin >> n;
	rep (i, 1, n) {
		int u, v; std::cin >> u >> v;
		char c; std::cin >> c;

		ch[u][c - 'a'] = v;
	}

	tot = n;

	dfs (1, 1);

	int ans = 0;
	int ansp = 0;
	rep (i, 1, n) {
		if (ans < siz[i]) { ans = siz[i]; ansp = i; }
	}

	std::cout << n - ans << "\n";
	std::cout << ansp << "\n";

	return 0;
}

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

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxm = 100005;
const int maxn = 20005;

int n, m;

struct Edge {
	int u, v;
	int pre;

	int w;

	bool exist;
} es[maxm << 1];
int last[maxn], cnt;

inline void addEdge (int u, int v, int w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

int col[maxn];
bool dfs (int now) {
	for (int i = last[now]; i; i = es[i].pre) {
		if (not es[i].exist) { continue; }
		
		int t = es[i].v;
		if (col[t]) {
			if (col[t] == col[now]) { return false; }
		} else {
			col[t] = -col[now];
			if (not dfs (t)) { return false; }
		}
	}

	return true;
}

inline bool check (int lim) {
	for (int i = 1; i <= cnt; i++) { es[i].exist = (es[i].w > lim); }
	
	for (int i = 1; i <= n; i++) { col[i] = 0; }
	
	bool res = true;
	for (int i = 1; i <= n; i++) {
		if (not col[i]) { col[i] = 1; res &= dfs (i); }
	}

	return res;
}

int main () {
	fastread

	std::cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int u, v, w; std::cin >> u >> v >> w;
		addEdge (u, v, w);
		addEdge (v, u, w);
	}

	int l = 0, r = 1e9;
	int ans = 1e9;

	while (l <= r) {
		int mid = (l + r) >> 1;

		if (check (mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	std::cout << ans << "\n";

	return 0;
}

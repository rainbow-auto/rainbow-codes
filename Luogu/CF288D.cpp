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

// #define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << ": " << (x) << "\n";
#else
#define db(x) void (0);
#endif

const int maxn = 80005;

i64 n;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

i64 cntA[maxn];
i64 cntB[maxn];

i64 siz[maxn];

void dfs (int now, int fa) {
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }

		dfs (t, now);
		siz[now] += siz[t];
	}

	cntB[now] = siz[now] * (siz[now] - 1) / 2ll; 

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }
		cntB[now] -= siz[t] * (siz[t] - 1) / 2ll;		
	}

	cntA[now] = siz[now] * (n - siz[now]); // now 向下不需要特判, 因为这实际上属于 B 型路径
}

int main () {
	fastread

	std::cin >> n;

	for (int i = 1; i <= n - 1; i++) {
		int u, v; std::cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
	}

	dfs (1, 0);

	i64 ans = ((n * (n - 1)) / 2ll) * ((n * (n - 1)) / 2ll); // 随意枚举无序点对

	for (int u = 1; u <= n; u++) {
		ans -= 2ll * cntA[u] * cntB[u] + cntB[u] * cntB[u];
	}

	std::cout << ans << "\n";

	return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
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

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

const int maxn = 200005;

int n;

struct Edge {
	int u, v;
	i64 w;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v, i64 w) {
	es[++cnt] = Edge { u, v, w, last[u] };
	last[u] = cnt;
}

int rt;
i64 dis[maxn];
void dfs (int now, int fa) {
	if (dis[now] > dis[rt]) { rt = now; }

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }
		dis[t] = dis[now] + es[i].w;
		dfs (t, now);
	}
}

inline i64 getd () {
	rt = 0; dfs (1, 0);
	dis[rt] = 0; dfs (rt, 0);
	return dis[rt]; 
}

bool MemED;
int main () {
	fastread
	// lookMem	

	i64 sum = 0;

	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		i64 w; std::cin >> w;
		addEdge (u, v, w); addEdge (v, u, w);
		sum += w;
	}

	i64 ans = sum * 2ll - getd ();

	std::cout << ans << "\n";

	return 0;
}

#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 200005;

int n;
bool st[maxn];
bool vis[maxn];

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];
int last[maxn], cnt;

inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

void dfs(int now) {
	if (vis[now]) return;
	vis[now] = true;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		dfs(t);
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		int a, b; std::cin >> a >> b;
		if (a == 0 and b == 0) st[i] = true;
		else addEdge(a, i), addEdge(b, i);
	}

	rep (i, 1, n) {
		if (st[i]) dfs(i);
	}

	int ans = 0;
	rep (i, 1, n) ans += vis[i];
	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}

#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

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

const int maxn = 500005;

int n, s;

struct Edge {
	int u, v;
	int pre;
	i64 w;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v, i64 w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

i64 ans;
i64 dfs(int now, int fa) {
	i64 mx = 0;
	std::vector<i64> ts;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		i64 x = dfs(t, now) + es[i].w;
		ts.push_back(x);
		mx = std::max(mx, x);
	}

	for (auto x : ts) ans += mx - x;
	return mx;
}

void solve() {
	std::cin >> n >> s;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		i64 w; std::cin >> w;
		addEdge(u, v, w); addEdge(v, u, w);
	}

	ans = 0;
	dfs(s, -1);
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

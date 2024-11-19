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

const int maxn = 600005;

int n, m;

struct Edge {
	int u, v;
	int pre;
	int w;
} es[maxn << 1];

int last[maxn], cnt = 1;

inline void addEdge(int u, int v, int w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

int dfn[maxn], dpos;
int low[maxn];

int bel[maxn], tot;

std::stack<int> stk; 
void tarjan(int now, int in) {
	dfn[now] = ++dpos;
	low[now] = dfn[now];
	stk.push(now);
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (not dfn[t]) {
			tarjan(t, i);
			low[now] = std::min(low[now], low[t]);
		} else if (i != (in ^ 1)) low[now] = std::min(low[now], dfn[t]);
	}

	if (low[now] == dfn[now]) {
		tot++;
		int x;
		do {
			x = stk.top(); stk.pop();
			bel[x] = tot;
		} while (x != now);
	}
} 

int val[maxn];

struct DisjointSet {
	int fa[maxn];
	int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

	inline void mrg(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return;
		fa[v] = u;
	}

	inline void init(int siz) {
		rep (i, 1, siz) fa[i] = i;
	}
} s;

void solve() {
	std::cin >> n >> m;
	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		int w; std::cin >> w;
		addEdge(u, v, w);
		addEdge(v, u, w);
	}

	tarjan(1, -1);

	s.init(tot);

	rep (i, 2, cnt) {
		auto e = es[i];
		if (bel[e.u] == bel[e.v]) val[bel[e.u]] += e.w;
	}

	rep (i, 2, cnt) {
		if (es[i].w) continue;
		int u = bel[es[i].u];
		int v = bel[es[i].v];
		if (u == v) continue;
		if (val[u] or val[v]) continue;
		s.mrg(u, v);
	}

	int q; std::cin >> q;
	while (q--) {
		int u, v; std::cin >> u >> v;
		if (bel[u] == bel[v]) {
			std::cout << (val[bel[u]] ? "YES" : "NO") << "\n";
		} else {
			std::cout << ((s.find(bel[u]) != s.find(bel[v])) ? "YES" : "NO") << "\n";
		}
	}
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

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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 1000005;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int son[maxn], siz[maxn], fa[maxn], dep[maxn];
void dfs1(int now) {
	son[now] = -1;
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa[now]) continue;
		dep[t] = dep[now] + 1;
		fa[t] = now;
		dfs1(t);
		siz[now] += siz[t];
		if (not ~son[now] or siz[t] > siz[son[now]]) son[now] = t;
	}
}

int top[maxn], dfn[maxn], dpos;
void dfs2(int now, int topnow) {
	top[now] = topnow;
	dfn[now] = ++dpos;
	if (not ~son[now]) return;
	dfs2(son[now], topnow);

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa[now]) continue;
		if (t == son[now]) continue;
		dfs2(t, t);
	}
}

inline void tree_decomp() {
	fa[0] = -1;
	dfs1(0);
	dfs2(0, 0);
}

inline int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			u = fa[top[u]];
		} else {
			v = fa[top[v]];
		}
	}
	if (dep[u] < dep[v]) return u;
	else return v;
}

std::vector<int> get_pi(std::string s) {
	std::vector<int> pi(s.length());
	rep (i, 2, s.length() - 1) {
		int j = pi[i - 1];
		while (j and s[j + 1] != s[i]) j = pi[j];
		pi[i] = j + int (s[j + 1] == s[i]);
	}
	return pi;
}

int n, q;

void solve() {
	std::string s; std::cin >> s;
	n = s.length();
	s = " " + s;

	auto pi = get_pi(s);
	rep (i, 1, n) addEdge(pi[i], i);

	tree_decomp();

	std::cin >> q;
	while (q--) {
		int u, v; std::cin >> u >> v;
		std::cout << lca(pi[u], pi[v]) << "\n";
	}
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

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

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

const int maxn = 500005;

int n;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int fa[maxn], siz[maxn], son[maxn], dep[maxn];
void build_tree (int now) {
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa[now]) { continue; }
		fa[t] = now;
		dep[t] = dep[now] + 1;
		build_tree (t);
		siz[now] += siz[t];
		if (siz[t] > siz[son[now]]) { son[now] = t; }
	}
}

int top[maxn], dfn[maxn], dpos, rnk[maxn];
void tree_decomp (int now, int topnow) {
	dfn[now] = ++dpos;
	rnk[dfn[now]] = now;
	top[now] = topnow;

	if (not son[now]) { return; }
	tree_decomp (son[now], topnow);

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa[now]) { continue; }
		if (t == son[now]) { continue; }

		tree_decomp (t, t);
	}
}

inline int lca (int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			u = fa[top[u]];
		} else {
			v = fa[top[v]];
		}
	}
	return dep[u] < dep[v] ? u : v;
}

int main () {
	fastread

	int m, S;
	std::cin >> n >> m >> S;
	for (int i = 1; i <= n - 1; i++) {
		int u, v; std::cin >> u >> v;
		addEdge (u, v); addEdge (v, u); 
	}

	build_tree (S);
	tree_decomp (S, S);

	while (m--) {
		int u, v; std::cin >> u >> v;
		std::cout << lca (u, v) << "\n";
	}

	return 0;
}

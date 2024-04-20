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

const int maxn = 2020005;

int n, m;

namespace Tree {
	
	struct Edge {
		int u, v;
		int pre;
	} es[maxn << 1];
	int last[maxn], cnt; // 边

	inline void addEdge (int u, int v) {
		es[++cnt] = Edge { u, v, last[u] };
		last[u] = cnt;
	}

	int val[maxn], tot; // 点权

	int siz[maxn], son[maxn], fa[maxn], dep[maxn];
	void tree_build (int now, int father) {
		fa[now] = father;
		dep[now] = dep[fa[now]] + 1;
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (t == fa[now]) { continue; }

			tree_build (t, now);

			siz[now] += siz[t];
			if (siz[t] > siz[son[now]]) { son[now] = t; }
		}
	}

	int top[maxn], dfn[maxn], dpos;
	void tree_decomp (int now, int topnow) {
		dfn[now] = ++dpos;
		top[now] = topnow;

		if (not son[now]) { return; }

		tree_decomp (son[now], topnow);		

		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (t == fa[now] or t == son[now]) { continue; }

			tree_decomp (t, t);
		}
	}	

	inline void init () {
		for (int i = 1; i <= tot; i++) { 
			if (not dfn[i]) { tree_build (i, 0); tree_decomp (i, i); }
		}
	}

	inline int lca (int u, int v) {
		while (top[u] != top[v]) {
			if (dep[u] > dep[v]) { u = fa[top[u]]; }
			else { v = fa[top[v]]; }
		}

		return dep[u] < dep[v] ? u : v;
	}
}

namespace Kruskal {

	struct Edge {
		int u, v;
		int w;
		friend bool operator < (Edge a, Edge b) {
			return a.w > b.w;
		}
	};

	std::vector <Edge> es;

	int fa[maxn]; // union-find set
	int find (int x) {
		if (fa[x] == x) { return fa[x]; }
		return fa[x] = find (fa[x]);
	}

	inline void ufs_init (int tot) {
		for (int i = 1; i <= tot; i ++) { fa[i] = i; }
	}

	inline void kruskal () {
		ufs_init (n + m + 1);

		std::sort (es.begin (), es.end ());

		Tree::tot = n;

		for (auto e : es) {
			int u = find (e.u);
			int v = find (e.v);

			if (u == v) { continue; }

			int e_node = ++Tree::tot;
			Tree::val[e_node] = e.w;

			Tree::addEdge (e_node, u); Tree::addEdge (e_node, v);

			fa[u] = fa[v] = fa[e_node] = e_node;
		}
	}

}

namespace Solution {

	inline void solve () {
		Kruskal::kruskal ();
		Tree::init ();

		Tree::val[0] = -1; // 处理不连通的情况

		int q; std::cin >> q;

		for (int i = 1; i <= q; i++) {
			int u, v; std::cin >> u >> v;

			std::cout << Tree::val[ Tree::lca (u, v) ] << "\n";
		}
	}

}

int main () {
	fastread

	std::cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int u, v, w; std::cin >> u >> v >> w;
		Kruskal::es.push_back (Kruskal::Edge { u, v, w });
	}

	Solution::solve ();

	return 0;
}

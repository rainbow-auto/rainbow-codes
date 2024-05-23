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

const int maxn = 200005;

int n, m;

int a[maxn];

struct Trie {
	int tr[maxn << 6][2];
	int tot;
	int siz[maxn << 6];

	int rt[maxn];

	inline void clear () {
		for (int i = 1; i <= tot; i++) { tr[i][0] = tr[i][1] = 0; siz[i] = 0; } 
		tot = 0; 
	}

	inline void insert (int now, int old, int val) {
		for (int i = 31; i >= 0; i--) {
			bool x = ((val >> i) & 1);	
			
			tr[now][x] = ++tot; tr[now][x ^ 1] = tr[old][x ^ 1];  // clone
			
			now = tr[now][x]; old = tr[old][x];
			
			siz[now] = siz[old] + 1;
		}
	}

	inline int query (int now, int old, int val) {
		int ans = 0;
		for (int i = 31; i >= 0; i--) {
			bool x = ((val >> i) & 1);
			
			if (siz[tr[now][x ^ 1]] - siz[tr[old][x ^ 1]] > 0) {
				ans |= (1 << i);
				now = tr[now][x ^ 1]; old = tr[old][x ^ 1];
			} else {
				now = tr[now][x]; old = tr[old][x];
			}
		}

		return ans;
	}
} trie;

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

void tree_build (int now, int father) {
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;

		if (t == father) { continue; }

		fa[t] = now;
		dep[t] = dep[now] + 1;
		tree_build (t, now);
		siz[now] += siz[t];
		if (siz[t] > siz[son[now]]) { son[now] = t; }
	}
}

int top[maxn], dfn[maxn], dpos, bottom[maxn], id[maxn];

void tree_decomp (int now, int topnow) {
	top[now] = topnow;
	dfn[now] = ++dpos;
	id[dfn[now]] = now;
	bottom[now] = dfn[now];

	if (not son[now]) { return; }

	tree_decomp (son[now], topnow);
	bottom[now] = std::max (bottom[now], bottom[son[now]]);

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa[now]) { continue; }
		if (t == son[now]) { continue; }

		tree_decomp (t, t);
		bottom[now] = std::max (bottom[now], bottom[t]);
	}
}

inline void init () {
	dep[1] = 1;
	tree_build (1, 0);
	tree_decomp (1, 1);

	trie.rt[0] = ++trie.tot;
	for (int i = 1; i <= dpos; i++) {
		trie.rt[i] = ++trie.tot;
		trie.insert (trie.rt[i], trie.rt[i - 1], a[id[i]]);
	}
}

inline int querySubtree (int u, int val) {
	return trie.query (trie.rt[bottom[u]], trie.rt[dfn[u] - 1], val);
}

inline int queryChain (int u, int v, int val) {
	int res = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			res = std::max (res, trie.query (trie.rt[dfn[u]], trie.rt[dfn[top[u]] - 1], val));
			u = fa[top[u]];
		} else {
			res = std::max (res, trie.query (trie.rt[dfn[v]], trie.rt[dfn[top[v]] - 1], val));
			v = fa[top[v]];
		}
	}
	
	if (dep[u] < dep[v]) { std::swap (u, v); } // make dep[u] > dep[v]
	res = std::max (res, trie.query (trie.rt[dfn[u]], trie.rt[dfn[v] - 1], val));
	
	return res;
}

int main () {
	fastread
	
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

	for (int i = 1; i <= n - 1; i++) { 
		int u, v; std::cin >> u >> v; 
		addEdge (u, v); addEdge (v, u); 
	}

	init ();

	for (int i = 1; i <= m; i++) {
		int op; std::cin >> op;
		if (op == 1) { 
			int x, z; std::cin >> x >> z; 
			std::cout << querySubtree (x, z) << '\n';
		} else if (op == 2) {
			int x, y, z; std::cin >> x >> y >> z;
			std::cout << queryChain (x, y, z) << '\n';
		}
	}

	return 0;
}

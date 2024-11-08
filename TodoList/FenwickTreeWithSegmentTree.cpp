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

const int maxn = 50005;

int n;

struct Tree {
	struct Node {
		int ls, rs;
		int sum;
	} tr[maxn << 7];

	int rat[maxn], tot;

	void modify (int& now, int old, int l, int r, int pos, int val) {
		now = ++tot; tr[now] = tr[old];
		tr[now].sum += val;

		if (l == r) { return; }

		int mid = (l + r) >> 1;
		if (pos <= mid) { modify (tr[now].ls, tr[old].ls, l, mid, pos, val); }
		if (pos > mid) { modify (tr[now].rs, tr[old].rs, mid + 1, r, pos, val); }
	}

	int query (int add, int sub, int l, int r, int L, int R) {
		if (l == r) { return l; }
		
		int cnt = tr[tr[add].ls].sum - tr[tr[sub].ls].sum;
		if (k <= cnt) { return query (tr[add].ls, tr[sub].ls, l, mid, k); }
		else { return query (tr[add].rs, tr[add].rs, mid + 1, r, k - cnt); }
	}

	inline int query (int l, int r, int L, int R) {
		return query (rt[r], rt[l - 1], 0, (1ll << 31) - 1ll, L, R);
	}

} tr;

int val[maxn];

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

void tree_build (int now) {
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;

		if (t == fa[now]) { continue; }

		fa[t] = now;
		dep[t] = dep[now] + 1;

		tree_build (t);

		siz[now] += siz[t];
		if (siz[t] > siz[son[now]]) { son[now] = t; }
	}
}

int top[maxn], dfn[maxn], dpos, rnk[maxn];

int tree_decomp (int now, int topnow) {
	dfn[now] = ++dpos;
	rnk[dpos] = now;
	top[now] = topnow;

	if (not son[now]) { return; }
	tree_decomp (son[now], topnow);

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;

		if (t == fa[now] or t == son[now]) { continue; }

		tree_decomp (t, t);	
	}
}


inline void tree_init () {
	dep[1] = 1;
	tree_build (1);
	tree_decomp (1, 1);

	tr.rt[0] = ++ tr.tot;
	for (int i = 1; i <= dpos; i++) {
		tr.modify (tr.rt[i], tr.rt[i - 1], 0, (1ll << 31) - 1ll, val[rnk[i]], 1);
	}
}

inline int queryChainSum (int u, int v, int L, int R) {
	int res = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) { 
			res += tr.query (top[u], tr.rt[dfn[u] - 1], 0, (1ll << 31) - 1ll, L, R);
			u = fa[top[u]];
		} else {
			res += tr.query (tr.rt[top[v]], tr.rt[v] - 1, 0, (1ll << 31) - 1ll, L, R);
			v = fa[top[v]];
		}
	}
	return res;
}	

inline int queryChainKth (int u, int v, int k) {
	int l = 0, r = (1ll << 31) - 1ll;

	int res = -1;

	while (l <= r) {
		int mid = (l + r) >> 1;

		if (queryChainSum (u, v, 1, mid) == k) {
			return mid;
		} else if (queryChainSum (u, v, 1, mid) < k) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	return -1;
}	

int main () {
	fastread

	return 0;
}

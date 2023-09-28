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

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 2e5 + 5;

int n, m;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt, val[maxn];

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int fa[maxn], siz[maxn], son[maxn], dep[maxn];
int top[maxn], dfn[maxn], dpos, rnk[maxn];

void treeBuild (int now, int f) { // dfs1
	siz[now] = 1;
	dep[now] = dep[f] + 1;
	fa[now] = f;

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == f) { continue; }

		treeBuild (t, now);
		siz[now] += siz[t];

		if (siz[t] > siz[son[now]]) {
			son[now] = t;
		}
	}
}

void treeDecomp (int now, int topnow) { // dfs2
	top[now] = topnow;
	dfn[now] = ++dpos;
	rnk[dpos] = now;

	if (not son[now]) { return; }

	treeDecomp (son[now], topnow);

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;

		if (t == son[now]) { continue; }
		if (t == fa[now]) { continue; }

		treeDecomp (t, t);
	}
}

namespace SegmentTree {
	
	struct Node {
		int sum;
		int tag; bool cov;
		int maxSum, maxL, maxR;

		Node () { sum = maxSum = maxL = maxR = 0; tag = 0; cov = false; }

	} tr[maxn << 4];

	inline Node merge (Node a, Node b) {
		Node res;

		res.sum = a.sum + b.sum;

		res.maxL = max (a.maxL, a.sum + b.maxL);
		res.maxR = max (b.maxR, b.sum + a.maxR);

		res.maxSum = max ( max (a.maxSum, b.maxSum) , a.maxR + b.maxL );

		res.cov = false; res.tag = 0;

		return res;
	}

	void build (int now, int l, int r) {
		if (l == r) {
			tr[now].sum = tr[now].maxL = tr[now].maxR = tr[now].maxSum = ::val[::rnk[l]];
			tr[now].tag = 0; tr[now].cov = false;

			return;
		}

		int mid = (l + r) >> 1;
		build (now << 1, l, mid);
		build (now << 1 | 1, mid + 1, r);

		tr[now] = merge (tr[now << 1], tr[now << 1 | 1]);
	}

	inline void update (int now, int l, int r, int val) {
		tr[now].sum = (r - l + 1) * val;
		tr[now].maxL = tr[now].maxR = tr[now].maxSum = max (0, tr[now].sum);
		tr[now].tag = val; tr[now].cov = true;
	}
	
	inline void pushDown (int now, int l, int r) {
		if (not tr[now].cov) { return; }

		int mid = (l + r) >> 1;
		update (now << 1, l, mid, tr[now].tag);
		update (now << 1 | 1, mid + 1, r, tr[now].tag);
		tr[now].tag = 0; tr[now].cov = false;
	}


	void modify (int now, int l, int r, int L, int R, int val) {
		if (L <= l and r <= R) {
			update (now, l, r, val);
			return;
		}

		pushDown (now, l, r);

		int mid = (l + r) >> 1;

		if (L <= mid) { modify (now << 1, l, mid, L, R, val); }
		if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val); }

		tr[now] = merge (tr[now << 1], tr[now << 1 | 1]);
	}

	Node query (int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) { return tr[now]; }

		pushDown (now, l, r);

		int mid = (l + r) >> 1;
		
		Node lNode, rNode;
		
		if (L <= mid) { lNode = query (now << 1, l, mid, L, R); }
		if (R > mid) { rNode = query (now << 1 | 1, mid + 1, r, L, R); }

		return merge ( lNode, rNode );
	} 
}

inline void chainModify (int u, int v, int c) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			SegmentTree::modify (1, 1, n, dfn[top[u]], dfn[u], c);
			u = fa[top[u]];
		} else {
			SegmentTree::modify (1, 1, n, dfn[top[v]], dfn[v], c);
			v = fa[top[v]];
		}
	}

	if (dep[u] > dep[v]) { swap (u, v); }
	SegmentTree::modify (1, 1, n, dfn[u], dfn[v], c);
}

inline SegmentTree::Node chainQuery (int u, int v) {
	SegmentTree::Node L, R;

	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			R = SegmentTree::merge (SegmentTree::query (1, 1, n, dfn[top[v]], dfn[v]), R);
			v = fa[top[v]];
		} else {
			L = SegmentTree::merge (SegmentTree::query (1, 1, n, dfn[top[u]], dfn[u]), L);
			u = fa[top[u]];
		}
	}

	if (dep[u] > dep[v]) {
		L = SegmentTree::merge (SegmentTree::query (1, 1, n, dfn[v], dfn[u]), L);
	} else {
		R = SegmentTree::merge (SegmentTree::query (1, 1, n, dfn[u], dfn[v]), R);
	}

	swap (L.maxL, L.maxR);
	return SegmentTree::merge (L, R);
}

inline void clear () {
	memset (fa, 0, sizeof (fa));
	memset (dep, 0, sizeof (dep));
	memset (siz, 0, sizeof (siz));
	memset (son, 0, sizeof (son));
	memset (dfn, 0, sizeof (dfn)); dpos = 0;
	memset (rnk, 0, sizeof (rnk));
	memset (top, 0, sizeof (top));

	cnt = 0;
	memset (last, 0, sizeof (last));
}

int main () {
	fastread

	clear ();

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}

	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
	}
	
	treeBuild (1, 0);
	treeDecomp (1, 1);
	SegmentTree::build (1, 1, n);

	cin >> m;

	while (m--) {
		int op; cin >> op;

		if (op == 1) {
			int a, b; cin >> a >> b;
			cout << chainQuery (a, b).maxSum << endl;
		} else if (op == 2) {
			int a, b, c; cin >> a >> b >> c;
			chainModify (a, b, c);
		}
	}

	return 0;
}

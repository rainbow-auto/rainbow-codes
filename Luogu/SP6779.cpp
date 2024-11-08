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

const int maxn = 200005;

int n, q;

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
int top[maxn], rnk[maxn], dfn[maxn], dpos;

void treeBuild (int now, int f) {
	fa[now] = f;
	son[now] = 0;
	siz[now] = 1;
	dep[now] = dep[f] + 1;

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

void treeDecomp (int now, int topnow) {
	top[now] = topnow;
	dfn[now] = ++dpos;
	rnk[dpos] = now;

	if (not son[now]) { return; }

	treeDecomp (son[now], topnow);

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;

		if (t == fa[now]) { continue; }
		if (t == son[now]) { continue; }

		treeDecomp (t, t);
	}
}

struct Node {
	int sum;
	int tag; bool cov;

	int maxL, maxR, maxSum;

	Node () { sum = maxL = maxR = maxSum = 0; tag = 0; cov = false; }

} tr[maxn << 3];

inline Node merge (Node a, Node b) {
	Node res;

	res.sum = a.sum + b.sum;

	res.maxL = max (a.maxL, a.sum + b.maxL);
	res.maxR = max (b.maxR, b.sum + a.maxR);

	res.maxSum = max ( max (a.maxSum, b.maxSum), a.maxR + b.maxL );

	return res;
}

inline void update (int now, int l, int r, int k) {
	tr[now].sum = (r - l + 1) * k;
	tr[now].maxL = tr[now].maxR = tr[now].maxSum = max (0, tr[now].sum);
	tr[now].tag = k; tr[now].cov = true;
}

inline void pushDown (int now, int l, int r) {
	if (not tr[now].cov) { return; }

	int mid = (l + r) >> 1;
	update (now << 1, l, mid, tr[now].tag);
	update (now << 1 | 1, mid + 1, r, tr[now].tag);

	tr[now].tag = 0; tr[now].cov = false;
}

void build (int now, int l, int r) {
	if (l == r) {
		tr[now].sum = tr[now].maxL = tr[now].maxR = tr[now].maxSum = val[rnk[l]];
		return;
	}

	int mid = (l + r) >> 1;

	build (now << 1, l, mid);
	build (now << 1 | 1, mid + 1, r);

	tr[now] = merge (tr[now << 1], tr[now << 1 | 1]);
}

void modify (int now, int l, int r, int L, int R, int k) {
	if (L <= l and r <= R) {
		update (now, l, r, k);
		return;
	}

	pushDown (now, l, r);

	int mid = (l + r) >> 1;

	if (L <= mid) { modify (now << 1, l, mid, L, R, k); }
	if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, k); }

	tr[now] = merge (tr[now << 1], tr[now << 1 | 1]);
}

Node query (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) {
		return tr[now];	
	}

	pushDown (now, l, r);

	int mid = (l + r) >> 1;
	
	Node lNode, rNode;
	if (L <= mid) { lNode = query (now << 1, l, mid, L, R); }
	if (R > mid) { rNode = query (now << 1 | 1, mid + 1, r, L, R); }

	return merge (lNode, rNode);
}

void chainModify (int a, int b, int c) {
	while (top[a] != top[b]) {
		if (dep[top[a]] > dep[top[b]]) {
			modify (1, 1, n, dfn[top[a]], dfn[a], c);
			a = fa[top[a]];
		} else {
			modify (1, 1, n, dfn[top[b]], dfn[b], c);
			b = fa[top[b]];
		}
	}

	if (dep[a] > dep[b]) { swap (a, b); }
	modify (1, 1, n, dfn[a], dfn[b], c);
}

Node chainQuery (int a, int b) {
	Node L, R;

	while (top[a] != top[b]) {
		if (dep[top[a]] > dep[top[b]]) {
			L = merge ( query (1, 1, n, dfn[top[a]], dfn[a]), L );
			a = fa[top[a]];
		} else {
			R = merge ( query (1, 1, n, dfn[top[b]], dfn[b]), R );
			b = fa[top[b]];	
		}
	}

	if (dep[a] > dep[b]) { L = merge ( query (1, 1, n, dfn[b], dfn[a]), L ); }
	else { R = merge ( query (1, 1, n, dfn[a], dfn[b]), R ); }
	
	swap (L.maxL, L.maxR);

	return merge (L, R);
}

int main () {
	fastread
	
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
	build (1, 1, n);

	cin >> q;

	while (q --) {
		int op;
		cin >> op;

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

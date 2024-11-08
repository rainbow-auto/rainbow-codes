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

const int maxn = 100005;

int n, m;
long long val[maxn];

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

// tree-decompisition

int siz[maxn], son[maxn], fa[maxn], dep[maxn];
int dfn[maxn], dpos, top[maxn], rnk[maxn], buttom[maxn];

void treeBuild (int now, int f) {
	fa[now] = f;
	dep[now] = dep[f] + 1;
	siz[now] = 1;
	son[now] = 0;

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == f) { continue; }

		treeBuild (t, now);
		siz[now] += siz[t];

		if (siz[t] > siz[son[now]]) { son[now] = t; }	
	}
}

void treeDecomp (int now, int topnow) { // 剖
	dfn[now] = ++dpos;
	rnk[dfn[now]] = now;
	top[now] = topnow;
	buttom[now] = dfn[now];

	if (not son[now]) { return; }
	treeDecomp (son[now], topnow);
	buttom[now] = max (buttom[now], buttom[son[now]]);

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;

		if (t == fa[now]) { continue; }
		if (t == son[now]) { continue; }

		treeDecomp (t, t);
		buttom[now] = max (buttom[now], buttom[t]);
	}
}

// segment-tree

struct Node {
	long long sum;
	long long tag; bool cov;
} tr[maxn << 3];

inline void pushUp (int now) {
	tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
}

inline void update (int now, int l, int r, long long val) {
	tr[now].sum += (long long) (r - l + 1) * val;
	tr[now].cov = true; tr[now].tag += val;
}

inline void pushDown (int now, int l, int r) {
	if (not tr[now].cov) { return; }

	int mid = (l + r) >> 1;
	update (now << 1, l, mid, tr[now].tag);
	update (now << 1 | 1, mid + 1, r, tr[now].tag);

	tr[now].cov = false; tr[now].tag = 0;
}

void build (int now, int l, int r) {
	if (l == r) {
		tr[now].sum = val[rnk[l]];
		tr[now].cov = false; tr[now].tag = 0;
		return;	
	}

	int mid = (l + r) >> 1;

	build (now << 1, l, mid);
	build (now << 1 | 1, mid + 1, r);

	pushUp (now);
}

void modify (int now, int l, int r, int L, int R, long long val) {
	if (L <= l and r <= R) {
		update (now, l, r, val);
		return;
	}

	pushDown (now, l, r);

	int mid = (l + r) >> 1;
	if (L <= mid) { modify (now << 1, l, mid, L, R, val); }
	if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val); }

	pushUp (now);	
}

long long query (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) {
		return tr[now].sum;
	}

	pushDown (now, l, r);

	int mid = (l + r) >> 1;
	long long res = 0;
	if (L <= mid) { res += query (now << 1, l, mid, L, R); }
	if (R > mid) { res += query (now << 1 | 1, mid + 1, r, L, R); }

	return res;
}

inline void init () {
	treeBuild (1, 0);
	treeDecomp (1, 1);

	build (1, 1, n);
}

void nodeModify (int x, long long val) {
	modify (1, 1, n, dfn[x], dfn[x], val);
}

void subtreeModify (int x, long long val) {
	modify (1, 1, n, dfn[x], buttom[x], val);
}

long long chainQuery (int now) {
	long long res = 0;
	while (now) {
		res += query (1, 1, n, dfn[top[now]], dfn[now]);
		now = fa[top[now]];
	}
	return res;
}

int main () {
	fastread

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}

	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
	}

	init ();

	while (m--) {
		int op; cin >> op;
		
		if (op == 1) {
			long long x, a; cin >> x >> a;
			nodeModify (x, a);
		} else if (op == 2) {
			long long x, a; cin >> x >> a;
			subtreeModify (x, a);
		} else if (op == 3) {
			long long x; cin >> x;
			cout << chainQuery (x) << endl;
		}
	}

	return 0;
}

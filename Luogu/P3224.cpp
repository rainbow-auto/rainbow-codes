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

#include <chrono>
#include <random>

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 100005;

int n, m, q;
int w[maxn];

std::mt19937 rnd (std::chrono::steady_clock::now ().time_since_epoch ().count ());

struct Node {
	int val;
	int siz;
	int ls, rs;

	unsigned long long key;
} tr[maxn];

int root[maxn], tot;
inline int newNode (int val) {
	tr[++tot] = Node { val, 1, 0, 0, rnd () };
	return tot;
}

inline void pushUp (int now) { tr[now].siz = tr[tr[now].ls].siz + tr[tr[now].rs].siz + 1; }

void split (int now, int val, int& x, int& y) {
	if (not now) { x = y = 0; return; }

	if (tr[now].val <= val) {
		x = now; split (tr[now].rs, val, tr[now].rs, y);
		pushUp (now);
	} else {
		y = now; split (tr[now].ls, val, x, tr[now].ls);
		pushUp (now);
	}
}

int merge (int x, int y) {
	if (not x or not y) { return x | y; }

	if  (tr[x].key <= tr[y].key) {
		tr[x].rs = merge (tr[x].rs, y);
		pushUp (x);
		return x;
	} else {
		tr[y].ls = merge (x, tr[y].ls);
		pushUp (y);
		return y;
	}
}

inline int getNum (int now, int rnk) {
	while (now) {
		if (tr[tr[now].ls].siz + 1 == rnk) { return now; }
		if (rnk <= tr[tr[now].ls].siz) { now = tr[now].ls; }
		else { rnk -= tr[tr[now].ls].siz + 1; now = tr[now].rs; }
	}

	return -1;
}

inline void insert (int& now, int id) {
	int x, y; split (now, tr[id].val, x, y);
	now = merge (merge (x, id), y);
}

struct Set {
	int fa[maxn];

	inline void init (int n) { for (int i = 1; i <= n; i++) { fa[i] = i; } }

	int find (int x) {
		if (fa[x] == x) { return fa[x]; }
		return fa[x] = find (fa[x]);
	}
} s;

void dfs (int now, int& target) {
	if (not now) { return; }
	dfs (tr[now].ls, target);
	dfs (tr[now].rs, target);
	tr[now].ls = tr[now].rs = 0;
	tr[now].siz = 1;
	insert (target, now);
}

inline void addEdge (int u, int v) {
	u = s.find (u); v = s.find (v);
	if (u == v) { return; }
	if (tr[root[u]].siz > tr[root[v]].siz) { std::swap (u, v); }
	s.fa[u] = v;
	dfs (root[u], root[v]);
}

int main () {
	fastread

	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { std::cin >> w[i]; root[i] = newNode (w[i]); }
	s.init (n);
	for (int i = 1; i <= m; i++) { int u, v; std::cin >> u >> v; addEdge (u, v); }

	std::cin >> q;

	for (int i = 1; i <= q; i++) {
		char op; std::cin >> op;
		int x, y; std::cin >> x >> y;
		
		if (op == 'Q') { std::cout << getNum (root[s.find (x)], y) << "\n"; }
		else { addEdge (x, y); }
	}	

	return 0;
}

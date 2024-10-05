#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 1000005;

struct Edge {
	int u, v;
	int pre;
} es[maxn];

int last[maxn], cnt;
void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int n, q;

int fa[maxn];

int dfn[maxn], dpos;
int sub[maxn];
void dfs(int now) {
	dfn[now] = ++dpos;
	sub[now] = dfn[now];
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		dfs(t);	
		sub[now] = std::max(sub[now], sub[t]);	
	}
}

struct Tree {
	i64 tr[maxn];
	int lowbit(int x) { return x & (-x); }

	void add(int pos, i64 val) {
		for (int i = pos; i <= dpos; i += lowbit(i)) tr[i] += val;
	}

	i64 query(int pos) {
		i64 res = 0;
		for (int i = pos; i; i -= lowbit(i)) res += tr[i];
		return res;
	}

	i64 query(int l, int r) {
		return query(r) - query(l - 1);
	}
} valt, sizt;

i64 val[maxn], siz[maxn];

namespace DSU {
	int fa[maxn];
	void init() {
		rep (i, 1, n) fa[i] = i;
	}

	int find(int x) {
		if (fa[x] == x) return x;
		else return fa[x] = find(fa[x]);
	}
}

struct Node {
	int u;
	i64 lim;
	friend bool operator < (Node a, Node b) {
		return a.lim > b.lim;
	}
};

struct Query {
	int u;
	i64 x;

	int id;
	i64 ans;
	friend bool operator < (Query a, Query b) {
		return a.x < b.x;
	}
} qs[maxn];

std::bitset<maxn> added;

void solve() {
	std::cin >> n >> q;
	rep (i, 2, n) {
		std::cin >> fa[i];
		addEdge(fa[i], i);
	}

	rep (i, 1, n) std::cin >> val[i];
	rep (i, 1, n) siz[i] = 1;
	DSU::init();

	dfs(1);

	rep (i, 1, q) {
		std::cin >> qs[i].u >> qs[i].x;
		qs[i].id = i;
	}
	std::sort(qs + 1, qs + q + 1);

	i64 st = qs[1].x;
	rep (i, 1, n) val[i] += st;
	rep (i, 1, q) qs[i].x -= st;

	rep (i, 1, n) valt.add(dfn[i], val[i]), sizt.add(dfn[i], siz[i]);
	rep (i, 2, n) valt.add(dfn[fa[i]], -val[i]), sizt.add(dfn[fa[i]], -siz[i]);

	std::priority_queue<Node> rst;
	rep (i, 1, n) rst.push(Node { i, ceil(-1.0 * val[i] / siz[i]) });

	#define subtree(QWQ) dfn[QWQ], sub[QWQ]
	rep (qi, 1, q) {
		auto& cur = qs[qi];
		while (not rst.empty() and rst.top().lim <= cur.x) {
			int u = rst.top().u; rst.pop();
			if (added[u]) continue;
			added.set(u);

			int f = fa[u];
			if (not f) continue;
			int rt = DSU::find(f);
			DSU::fa[u] = rt; // link

			i64 sizu = sizt.query(subtree(u));
			i64 valu = valt.query(subtree(u));

			sizt.add(dfn[f], sizu), valt.add(dfn[f], valu);
			if (fa[rt]) sizt.add(dfn[fa[rt]], -sizu), valt.add(dfn[fa[rt]], -valu);

			if (added[rt]) continue;

			rst.push(Node { rt, ceil(-1.0 * valt.query(subtree(rt)) / sizt.query(subtree(rt))) });
		}

		cur.ans = sizt.query(subtree(cur.u)) * cur.x + valt.query(subtree(cur.u));
	}
	#undef subtree

	std::sort(qs + 1, qs + q + 1, [](Query a, Query b) -> bool { return a.id < b.id; });

	rep (i, 1, q) std::cout << qs[i].ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}

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

const int maxn = 100005;
const int maxm = 500005;

int n, q;

struct Edge {
	int u, v;
	int pre;
	i64 w;
} es[maxn << 1];

int last[maxn], cnt;

void addEdge(int u, int v, i64 w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

std::vector<int> g[maxn];

i64 dep[maxn];
int siz[maxn], son[maxn];

void dfs(int now, int fa) {
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;

		g[now].push_back(t);

		dep[t] = dep[now] + es[i].w;

		dfs(t, now);
		siz[now] += siz[t];
		
		if (siz[t] > siz[son[now]]) son[now] = t;
	}	
}

struct Pair {
	int a, b;
	i64 c;

	friend bool operator < (Pair x, Pair y) {
		if (x.b != y.b) return x.b < y.b;
		else return x.a < y.a;
	
};

std::vector<Pair> ps;

std::set<int> s;

void addPair(int now, i64 col) {
	auto it = s.lower_bound(now);
	if (it != s.end()) ps.push_back(Pair { now, *it, col });
	if (it != s.begin()) ps.push_back(Pair { *std::prev(it), now, col });
}

void add(int now, i64 col) {
	addPair(now, col);
	for (auto t : g[now]) add(t, col);
}

void ins(int now) {
	s.insert(now);
	for (auto t : g[now]) ins(t);
}

void mrg(int now) {
	ps.push_back(Pair { now, now, dep[now] });

	for (auto t : g[now]) {
		if (t == son[now]) continue;
		mrg(t);
		s.clear();
	}

	if (not son[now]) return s.insert(now), void(0);

	mrg(son[now]);

	for (auto t : g[now]) {
		if (t == son[now]) continue;
		add(t, dep[now]);
		ins(t);
	}

	s.insert(now);
}

struct Query {
	int l, r;
	int id;
	int ans;
	friend bool operator < (Query x, Query y) {
		if (x.r != y.r) return x.r < y.r;
		else return x.l < y.l;
	}
};

std::vector<Query> qs;

struct Tree {
	int tr[maxn];
	int lowbit(int x) {
		return x & (-x);
	}

	void modify(int pos, int val) {
		for (int i = pos; i <= n; i += lowbit(i)) tr[i] += val;
	}
	
	void add(int l, int r) {
		if (l > r) return;
		modify(l, 1); modify(r + 1, -1);
	}

	int query(int pos) {
		int res = 0;
		for (int i = pos; i; i -= lowbit(i)) res += tr[i];
		return res;
	}
} tr;

void solve() {
	std::cin >> n >> q;

	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		i64 w; std::cin >> w;
		addEdge(u, v, w); addEdge(v, u, w);
	}

	rep (i, 1, q) {
		int l, r; std::cin >> l >> r;
		qs.push_back(Query { l, r, i, 0 });
	}

	dfs(1, -1);
	mrg(1);

	std::sort(qs.begin(), qs.end());
	std::sort(ps.begin(), ps.end());

	int qi = 0, pi = 0;

	std::unordered_map<i64, int> lst;

	rep (r, 1, n) {
		while (pi < ps.size() and ps[pi].b == r) {
			auto cur = ps[pi];
			if (lst.count(cur.c)) {
				tr.add(lst[cur.c] + 1, cur.a);
				lst[cur.c] = std::max(lst[cur.c], cur.a); 
			} else {
				tr.add(1, cur.a);
				lst[cur.c] = cur.a;
			}

			pi++;
		}

		while (qi < qs.size() and qs[qi].r == r) qs[qi++].ans = tr.query(qs[qi].l);
	}

	std::sort(qs.begin(), qs.end(), [](Query x, Query y) -> bool { return x.id < y.id; });

	for (auto x : qs) std::cout << x.ans << "\n";
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

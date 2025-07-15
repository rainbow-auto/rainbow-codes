#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 200005;

using Edge = std::pair<int, int>;

int n, m, k;
std::vector<Edge> tr[maxn << 2];

std::bitset<maxn> ans;

void mdf(int now, int l, int r, int L, int R, Edge e) {
	if (L <= l and r <= R) return tr[now].push_back(e), void(0);
	int mid = (l + r) >> 1;
	if (L <= mid) mdf(now << 1, l, mid, L, R, e);
	if (R > mid) mdf(now << 1 | 1, mid + 1, r, L, R, e);
}

template<int maxn>
struct DSU {
	int siz[maxn];
	int fa[maxn];

	std::stack<std::pair<int, int>> st;

	int find(int x) {
		if (fa[x] != x) return find(fa[x]);
		return x;
	}

	inline void mrg(int u, int v) {
		if (find(u) == find(v)) return;
		u = find(u), v = find(v);
		if (siz[u] > siz[v]) std::swap(u, v);
		st.push(std::make_pair(u, v));
		fa[u] = v;
		siz[v] += siz[u];
	}

	inline void rollback() {
		auto lst = st.top(); st.pop();
		fa[lst.first] = lst.first;
		siz[lst.second] -= siz[lst.first];
	}

	inline int get() {
		return st.size();
	}

	inline void rollback(int t) {
		while (st.size() > t) rollback();
	}

	inline void init() {
		rep (i, 1, (n << 1)) fa[i] = i, siz[i] = 1;
	}
};

DSU<maxn> dsu;

inline void display() {
	rep (i, 1, (n << 1)) db << dsu.find(i) << " "; dbendl
}

// bool dbflg = false;

bool chk = true;
inline void add(Edge e) {
	// if (dbflg) db << "add " << e.first << " " << e.second << "\n";
	dsu.mrg(e.first, e.second + n);
	dsu.mrg(e.second, e.first + n);
	
	if (dsu.find(e.first) == dsu.find(e.first + n)) chk = false;
	if (dsu.find(e.second) == dsu.find(e.second + n)) chk = false;
}

void solve(int now, int l, int r) {
	bool old = chk;
	int t = dsu.get();
	for (auto e : tr[now]) add(e);

	if (l == r) {
		ans[l] = chk;
	} else {
		if (chk) {
			int mid = (l + r) >> 1;
			solve(now << 1, l, mid);
			solve(now << 1 | 1, mid + 1, r);
		}
	}

	chk = old;
	dsu.rollback(t);
}

void solve() {
	std::cin >> n >> m >> k;
	rep (i, 1, m) {
		int x, y; std::cin >> x >> y;
		int l, r; std::cin >> l >> r;
		if (l == r) continue;
		mdf(1, 0, k, l, r - 1, Edge{x, y});
	}
	
	dsu.init();

	solve(1, 0, k);

	rep (i, 0, k - 1) std::cout << (ans[i] ? "Yes\n" : "No\n");
}

bool MemED;
int main() {
	fastread
	// lookMem	

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}

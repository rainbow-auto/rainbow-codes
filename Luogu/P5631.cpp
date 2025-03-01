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

const int maxn = 2000005;

int n, m;

struct DSU {
	struct Info {
		int fa, siz;
	} s[maxn];

	inline void init() {
		rep (i, 1, n) s[i] = Info { i, 1 };
	}

	std::stack<int> his; // history
	inline int cur() { return his.size(); }

	int find(int x) {
		if (s[x].fa == x) return s[x].fa;
		return find(s[x].fa);
	}

	inline void mrg(int u, int v) {
//		db << "mrg " << u << " " << v << "\n";
		u = find(u), v = find(v);
		if (u == v) return;
		if (s[u].siz < s[v].siz) std::swap(u, v);
		// link v --> u
		his.push(v);
		s[v].fa = u;
		s[u].siz += s[v].siz;
	}

	inline void rollback(int t) {
		while (his.size() != t) {
			int x = his.top(); his.pop();
			s[s[x].fa].siz -= s[x].siz;
			s[x].fa = x;
		}
	}
} dsu;

struct Edge {
	int u, v;
};

std::vector<Edge> es[maxn];

bool ans[maxn];
void solve(int l, int r) {
	if (l == r) return ans[l] = (dsu.s[dsu.find(l)].siz == n), void(0);
	
	int mid = (l + r) >> 1;
	int t;

	t = dsu.cur();
	rep (i, mid + 1, r) for (auto e : es[i]) dsu.mrg(e.u, e.v);
	solve(l, mid);
	dsu.rollback(t);
	
	t = dsu.cur();	
	rep (i, l, mid) for (auto e : es[i]) dsu.mrg(e.u, e.v);
	solve(mid + 1, r);
	dsu.rollback(t);
}

void solve() {
	std::cin >> n >> m;
	
	dsu.init();	
	
	int mx = 0;
	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		int w; std::cin >> w;
		es[w].push_back(Edge { u, v });
		mx = std::max(mx, w);
	}
	
	solve(0, mx);
	
//	db << "ans: "; rep (i, 0, mx) db << ans[i] << " "; dbendl;
	
	rep (i, 0, mx) {
		if (ans[i]) return std::cout << i << "\n", void(0);
	}
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
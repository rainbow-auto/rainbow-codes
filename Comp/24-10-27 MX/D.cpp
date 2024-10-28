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
// #define MultiTask lovely_fairytale

const int maxn = 500005;

int n, m, q, K;

int p[maxn];

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

namespace K2 {
	int id[maxn];

	struct Query {
		int r;
		int id;
	};
	
	std::vector<Query> qs[maxn];
	int ans[maxn];

	std::vector<int> ns[maxn];

	struct Tree {
		int tr[maxn];
		inline int lowbit(int x) {
			return x & (-x);
		}

		inline int qry(int x) {
			int res = 0;
			for (int i = x; i; i -= lowbit(i)) res += tr[i];
			return res;
		}

		inline void mdf(int x, int val) {
			for (int i = x; i <= n; i += lowbit(i)) tr[i] += val;
		}
	} tr;

	inline void solve() {
		rep (i, 1, n) id[p[i]] = i;

		std::vector<std::pair<int, int>> rgs;

		rep (i, 1, cnt) {
			if (i & 1) continue;
			int u = es[i].u;
			int v = es[i].v;
			rgs.push_back(std::make_pair(std::min(id[u], id[v]), std::max(id[u], id[v])));
		}

		for (auto rg : rgs) ns[rg.first].push_back(rg.second);

		rep (i, 1, q) {
			int l, r; std::cin >> l >> r;
			qs[l].push_back(Query { r, i });

			// int res = 0;
			// for (auto rg : rgs) {
			// 	res += (l <= rg.first and rg.second <= r) * 2;
			// }
			// ans[i] = res;

			// int res = 0;
			// rep (j, 1, cnt) {
			// 	if (j & 1) continue;
			// 	res += 2 * (l <= id[es[j].u] and id[es[j].u] <= r and l <= id[es[j].v] and id[es[j].v] <= r);
			// }
			// std::cout << res << "\n";

			// std::cout << res << "\n";
		}

		per (i, n, 1) {
			for (auto x : ns[i]) tr.mdf(x, 1);
			for (auto qcur : qs[i]) ans[qcur.id] = 2 * tr.qry(qcur.r);
		}

		rep (i, 1, q) std::cout << ans[i] << "\n";
	}
}

namespace K3 {
	int id[maxn];

	struct Query {
		int r;
		int id;
	};
	
	std::vector<Query> qs[maxn];
	int ans[maxn];

	std::vector<int> ns[maxn];

	int siz[maxn];

	struct Tree {
		int tr[maxn];
		inline int lowbit(int x) {
			return x & (-x);
		}

		inline int qry(int x) {
			int res = 0;
			for (int i = x; i; i -= lowbit(i)) res += tr[i];
			return res;
		}

		inline void mdf(int x, int val) {
			for (int i = x; i <= n; i += lowbit(i)) tr[i] += val;
		}
	} tr;

	inline void solve() {
		rep (i, 1, n) id[p[i]] = i;

		std::vector<std::pair<int, int>> rgs;

		rep (now, 1, n) {
			std::vector<int> sons;
			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				sons.push_back(t);
			}

			for (auto x : sons) {
				for (auto y : sons) {
					rgs.push_back(std::make_pair(std::min(id[x], id[y]), std::max(id[x], id[y])));
				}
			}
		}

		for (auto rg : rgs) ns[rg.first].push_back(rg.second);

		rep (i, 1, q) {
			int l, r; std::cin >> l >> r;
			qs[l].push_back(Query { r, i });
		}

		per (i, n, 1) {
			for (auto x : ns[i]) tr.mdf(x, 1);
			for (auto qcur : qs[i]) ans[qcur.id] = tr.qry(qcur.r);
		}

		rep (i, 1, q) std::cout << ans[i] << "\n";
	}
}

void solve() {
	std::cin >> n >> m >> q >> K;

	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}

	rep (i, 1, n) std::cin >> p[i];

	if (K == 2) {
		K2::solve();
	} else if (K == 3) {
		K3::solve();
	}
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::freopen("path.in", "r", stdin);
	std::freopen("path.out", "w", stdout);

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

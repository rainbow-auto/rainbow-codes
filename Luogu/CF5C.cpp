#include <bits/stdc++.h>
#pragma GCC optimize(2)

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

constexpr int maxn = 1000005;

int n;

struct dsu {
	int fa[maxn];
	int siz[maxn];
	inline void init() {
		rep (i, 0, n) fa[i] = i;
		rep (i, 0, n) siz[i] = 1;
	}

	int find(int x) {
		if (fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}

	inline bool mrg(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return false;
		// v -> v
		if (siz[v] > siz[u]) std::swap(u, v); // gurantee siz[v] < siz[u]
		fa[v] = u;
		siz[u] += siz[v];
		return true;
	}

	inline bool same(int u, int v) {
		u = find(u); v = find(v);
		return u == v;
	}
} dsu;

int pre[maxn];

std::bitset<maxn> mrk;

std::vector<int> buc[maxn << 1];
auto pos = buc + maxn;

void solve() {
	std::string s; std::cin >> s;
	n = s.size(); s = " " + s;

	rep (i, 1, n) pre[i] = pre[i - 1] + (s[i] == '(' ? 1 : -1);
	rep (i, 0, n) pos[pre[i]].push_back(i);

	std::pair<i64, int> ans;

	// rep (i, 0, n) db << pre[i] << " "; dbendl;
		
	dsu.init();

	per (v, n, -n) {
		if (pos[v].empty()) continue;

		// dbg(v);

		int fst = -1;
		int lst = -1;
		for (auto p : pos[v]) {
			// dbg(p);

			if (not ~lst) {
				fst = lst = p;
				continue;
			}

			if (lst == p - 1 or (dsu.same(lst + 1, p - 1) and mrk[lst + 1] and mrk[p - 1])) {
				if (p - fst > ans.first) {
					// db << "upd " << p - fst << " | " << fst << " " << p << "\n";
					ans = { p - fst, 1 };
				} else if (p - fst == ans.first) {
					ans.second++;
				}
			} else {
				fst = p;
			}
			lst = p;
		}

		for (auto p : pos[v]) {
			if (p - 1 >= 0 and mrk[p - 1]) dsu.mrg(p, p - 1);
			if (p + 1 <= n and mrk[p + 1]) dsu.mrg(p, p + 1);
			mrk[p] = true;
		}
	}

	if (ans.first == 0) std::cout << "0 1\n";
	else std::cout << ans.first << " " << ans.second << "\n";
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

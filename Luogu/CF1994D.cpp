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
#define MultiTask lovely_fairytale

const int maxn = 20005;

int n;
int a[maxn];

int fa[maxn];
inline void init() {
	rep (i, 1, n) fa[i] = i;
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void mrg(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return;
	fa[v] = u;
}

int lst[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];

	init();

	std::vector<std::pair<int, int>> ans;
	per (m, n - 1, 1) {
		// mod m
		rep (i, 0, m - 1) lst[i] = 0;

		rep (i, 1, n) {
			if (lst[a[i] % m]) {
				if (find(i) != find(lst[a[i] % m])) {
					ans.push_back(std::make_pair((int) i, lst[a[i] % m]));
					mrg(i, lst[a[i] % m]);
					break;
				}
			}
			lst[a[i] % m] = i;
		}
	}

	std::reverse(ans.begin(), ans.end());

	std::cout << "YES\n";
	for (auto x : ans) std::cout << x.first << " " << x.second << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

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

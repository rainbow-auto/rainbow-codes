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

constexpr int maxn = 20;
constexpr int maxS = (1 << maxn) + 5;

int n, m;
i64 f[1 << maxn];
int son[maxn];

void solve() {
	std::cin >> n >> m;
	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		son[u] |= (1 << (v - 1));
	}	

	f[0] = 1;
	rep (S, 0, (1 << n) - 1) {
		rep (i, 1, n) {
			if (not (S & (1 << (i - 1))) and (S & son[i]) == son[i]) {
				f[S | (1 << (i - 1))] += f[S];
			}
		}
	}

	std::cout << f[(1 << n) - 1] << "\n";
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

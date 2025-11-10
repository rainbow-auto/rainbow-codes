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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr i64 inf = 2e9;

void solve() {
	int n; std::cin >> n;

	i64 mn_sub = 1e18;
	i64 mn_sum = 1e18;
	rep (i, 1, n) {
		i64 x, y; std::cin >> x >> y;
		mn_sub = std::min(mn_sub, -x + y);
		mn_sum = std::min(mn_sum, x + y);
	}

	i64 _, res1, res2;
	std::cout << "? L " << inf / 2 << std::endl;
	std::cin >> _;
	std::cout << "? L " << inf / 2 << std::endl;
	std::cin >> _;
	
	std::cout << "? D " << inf / 2 << std::endl;
	std::cin >> _;
	std::cout << "? D " << inf / 2 << std::endl;
	// (x0 - inf, y0 - inf)
	std::cin >> res1;

	std::cout << "? R " << inf / 2 << std::endl;
	std::cin >> _;
	std::cout << "? R " << inf / 2 << std::endl;
	std::cin >> _;
	std::cout << "? R " << inf / 2 << std::endl;
	std::cin >> _;
	std::cout << "? R " << inf / 2 << std::endl;
	// (x0 + inf, y0 - inf)
	std::cin >> res2;

	i64 v1 = mn_sum + 2ll * inf - res1; // x0 + y0
	i64 v2 = res2 - 2ll * inf - mn_sub; // x0 - y0

	assert((v1 + v2) % 2 == 0);
	std::cout << "! " << (v1 + v2) / 2 << " " << (v1 - v2) / 2 << std::endl;
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

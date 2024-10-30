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

void solve() {
	dbendl;

	int n; std::cin >> n;
	i64 T; std::cin >> T;
	std::vector<std::pair<i64, i64>> a[2];
	rep (i, 1, n) {
		i64 t, b; std::cin >> t >> b;
		a[b < 0].push_back(std::make_pair(t, b));
	}

	std::sort(a[0].begin(), a[0].end());	
	for (auto x : a[0]) {
		if (T <= x.first) return std::cout << "-1s\n", void(0);
		T += x.second;
	}

	std::sort(a[1].begin(), a[1].end(), [&](std::pair<i64, i64> x, std::pair<i64, i64> y) -> bool {
		return x.first + x.second > y.first + y.second;
	});

	for (auto x : a[1]) {
		if (T <= x.first) return std::cout << "-1s\n", void(0);
		T += x.second;
	}

	if (T <= 0) return std::cout << "-1s\n", void(0);

	std::cout << "+1s\n";
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

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

void solve() {
	int n; std::cin >> n;
	
	int inf; std::memset(&inf, 0x3f, sizeof inf);
	
	std::set<std::pair<int, int>> s;
	rep (i, 1, n) {
		int x; std::cin >> x;
		auto it = s.insert(std::make_pair(x, i)).first;

		if (i == 1) continue;

		std::pair<int, int> res { inf, inf };
		if (it != s.begin()) {
			auto pre = *std::prev(it);
			int cur = std::abs(x - pre.first);
			
			if (cur < res.first) res = std::make_pair(cur, pre.second);
		}

		if (std::next(it) != s.end()) {
			auto nxt = *std::next(it);
			int cur = std::abs(x - nxt.first);

			if (cur < res.first) res = std::make_pair(cur, nxt.second);
		}

		std::cout << res.first << " " << res.second << "\n";
	}	
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

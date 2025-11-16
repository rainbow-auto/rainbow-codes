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

constexpr i64 n = i64(1e12);

void solve() {
	i64 x, y, k; std::cin >> x >> y >> k;

	i64 pos = k;
	while (x--) {
		i64 l = 0, r = 1e13;
		i64 nxt = r;
		while (l <= r) {
			i64 mid = (l + r) >> 1;
			if (mid - mid / y >= pos) {
			  	nxt = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		if (nxt > n) return std::cout << "-1\n", void(0);
		pos = nxt;
	}
	std::cout << pos << "\n";
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

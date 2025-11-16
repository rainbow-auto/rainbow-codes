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

constexpr i64 n = 1e12;

////////

void solve() {
	i64 x, y, k; std::cin >> x >> y >> k;
	if (y == 1) return std::cout << "-1\n", void(0);

	i64 ans = k;
	for (i64 pos = 0; pos < x; ) {
		i64 a = (ans - 1);
		i64 d = (y - 1);
		
		// a = qd + r
		i64 q = a / d;
		i64 r = a % d;
		
		if (not q) break;
		i64 cnt = (d - r + (q - 1)) / q; // ceil((d - r) / q)
		
		i64 len = std::min(x - pos, cnt);
		ans += q * len;
		pos += len;
		if (ans > n) return std::cout << "-1\n", void(0);
	}

	std::cout << ans << "\n";
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

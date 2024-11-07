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

using u64 = unsigned long long;

struct Basis {
	u64 b[63];

	inline bool ins(u64 x) {
		per (i, 60, 0) {
			if (x & (1ull << i)) {
				if (not b[i]) return (b[i] = x), true;
				else x ^= b[i];
			}
		}
		return false;
	}

	inline u64 mx(u64 x) {
		per (i, 60, 0) x = std::max(x, x ^ b[i]);
		return x;
	}
} basis;

void solve() {
	int n; std::cin >> n;
	rep (i, 1, n) {
		u64 x; std::cin >> x;
		basis.ins(x);
	}

	std::cout << basis.mx(0) << "\n";
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

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

const i64 mod = 1e9 + 7;

i64 n, m;

void solve() {
	std::cin >> m >> n;

	if (m == 1) return std::cout << "0\n", void(0);
	// if (n == 1) return std::cout << "0\n", void(0);

	i64 cnt[2] = { n >> 1, n - (n >> 1) };

	i64 ans = 0;
	per (i, 62, 0) {
		if ((1ull << i) <= m) {
			(ans += (1ull << i) % mod * cnt[0] % mod * cnt[1] % mod) %= mod;
		}
	}

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::freopen("testdata.in", "r", stdin);
	std::freopen("testdata.out", "w", stdout);
	
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

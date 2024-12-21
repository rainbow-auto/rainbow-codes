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

const i64 mod = 1e9 + 7;
const int maxn = 1000005;

i64 n, m, v;
std::pair<i64, int> a[maxn];

namespace Solution {
	inline i64 ksm(i64 a, i64 b) {
		i64 res = 1;
		for (;b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
		return res;
	}

	inline void solve() {
		std::sort(a + 1, a + m + 1);

		rep (i, 2, m) if (a[i].first == a[i - 1].first and a[i].second != a[i - 1].second) return std::cout << "0\n", void(0);
		if (v == 1) return std::cout << "1\n", void(0);

		m = std::unique(a + 1, a + m + 1) - a - 1;

		i64 ans = 1;
		(ans *= ksm(v, 2ll * (a[1].first - 1))) %= mod;
		rep (i, 2, m) (ans *= (((ksm(v, 2ll * (a[i].first - a[i - 1].first)) - (v - 1) * ksm(v, a[i].first - a[i - 1].first - 1) % mod) % mod + mod) % mod)) %= mod;
		(ans *= ksm(v, 2ll * (n - a[m].first))) %= mod;
		
		std::cout << ans << "\n";
	}
}

void solve() {
	std::cin >> n >> m >> v;
	
	rep (i, 1, m) {
		std::cin >> a[i].first >> a[i].second;
	}

	Solution::solve();
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

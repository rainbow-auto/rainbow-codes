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

namespace Task1 {
	const int maxn = 7;

	i64 ans;
	int a[maxn];
	void dfs(int now) {
		if (now > n) {
			i64 cur = 0;
			rep (i, 1, n) rep (j, i + 1, n) (cur += (a[i] xor a[j])) %= mod;
			ans = std::max(ans, cur);

			return;
		}

		rep (i, 1, m) {
			a[now] = i;
			dfs(now + 1);
		}
	}

	inline void solve() {
		ans = 0;
		dfs(1);
		std::cout << ans << "\n";
	}
}

namespace Task2 {
	void solve() {
		i64 ans = 0;
		
		static i64 a[2];
		int lst = 0;
		per (i, 62, 0) {
			if (a[lst ^ 1] + (1ull << i) <= m) {
				a[lst ^ 1] |= (1ull << i);
				lst ^= 1;
				(ans += (1ull << i) % mod) %= mod;
			}
		}

		std::cout << (ans % mod) << "\n";
	}
}

namespace Task3 {
	inline void solve() {
		i64 ans = 0;

		static i64 a[2];
		int lst = 0;

		// 010
		// 101
		per (i, 62, 0) {
			if (a[lst ^ 1] + (1ull << i) <= m) {
				a[lst ^ 1] |= (1ull << i);
				lst ^= 1;
				(ans += (2ull * (1ull << i)) % mod) %= mod;
			}
		}

		std::cout << ans << "\n";
	}
}

namespace Solution {
	inline void solve() {
		i64 ans = 0;

		static i64 a[2]; int lst = 0;
		i64 cnt[2] = { n >> 1, n - (n >> 1) };
		per (i, 62, 0) {
			if (a[lst ^ 1] + (1ull << i) <= m) {
				a[lst ^ 1] |= (1ull << i); 
				lst ^= 1;
				(ans += (1ull * (cnt[0] * cnt[1]) % mod * (1ull << i) % mod)) %= mod;
			}
		}

		std::cout << ans << "\n";
	}
}

void solve() {
	std::cin >> m >> n;
	if (n == 1) std::cout << "0\n";
	else if (n <= 5 and m <= 10) Task1::solve();
	// else if (n == 2) Task2::solve();
	// else if (n == 3) Task3::solve();
	else Solution::solve();
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

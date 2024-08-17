#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

const int maxn = 20000005;
const i64 mod = 1e9 + 7;

int n;
i64 g[maxn];
i64 cnt[maxn];

i64 A, B, C;

namespace Task1 {
	inline void solve () {

		rep (c, 1, n) {
			for (int i = 1; i <= n; i += c) { cnt[i] ++; }
		}

		i64 ans = 0;
		rep (l, 1, n) {
			i64 curr = 0;
			rep (r, l, n) {
				curr += cnt[r - l + 1] * g[r]; curr %= mod;
				ans += curr; ans %= mod;
			}
		}

		std::cout << ans << "\n";
	}
}

namespace TaskA {
	i64 f[maxn];
	i64 sf[maxn];

	inline void solve () {

		rep (c, 1, n) {
			for (int i = 1; i <= n; i += c) { cnt[i] ++; }
		}
		rep (i, 1, n) { cnt[i] %= mod; }

		rep (len, 1, n) {
			f[len] = f[len - 1] + (cnt[len] * g[n]) % mod; f[len] %= mod;
		}

		rep (len, 1, n) {
			sf[len] = sf[len - 1] + f[len]; sf[len] %= mod;
		}

		i64 ans = 0;
		rep (l, 1, n) {
			ans += sf[n - l + 1];
			ans %= mod;
		}

		std::cout << ans << "\n";
	}
}

namespace TaskB {
	inline void solve () {

		rep (c, 1, n) {
			for (int i = 1; i <= n; i += c) { cnt[i] ++; }
		}

		i64 ans = 0;
		rep (l, 1, n) {
			i64 curr = 0;
			rep (r, n, n) {
				curr += cnt[r - l + 1] * g[r]; curr %= mod;
				ans += curr; ans %= mod;
			}
		}

		rep (r) {
			i64 curr = 0;
			rep (l, 1, r) {
				ans += g[r] * sumcnt (l, r);
			}

			ans += g[r] * (r * prefixsumcnt (r) - preprecnt (0, r - 1));
		}	

		std::cout << ans << "\n";
	}
}
int main () {
	fastread

	std::cin >> n >> A >> B >> C >> g[n];

	A %= mod; B %= mod; C %= mod; g[n] %= mod;

	per (i, n - 1, 1) { g[i] = (((A * g[i + 1]) % mod) * g[i + 1]) % mod + (B * g[i + 1]) % mod + C; g[i] %= mod; }

	bool taskAflag = true;
	rep (i, 2, n) { taskAflag &= (g[i] == g[i - 1]); }

	if (taskAflag) { TaskA::solve (); }
	else if (n <= 10000) { Task1::solve (); }
	else { TaskB::solve (); }

	return 0;
}

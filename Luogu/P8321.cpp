#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

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

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 5005;
const i64 mod = 998244353;

int n;
std::pair <int, bool> nums[maxn << 1];

inline i64 ksm (i64 a, i64 b) {
	i64 base = a % mod;
	i64 res = 1;
	while (b) {
		if (b & 1) { res *= base; res %= mod; }
		base *= base; base %= mod; b >>= 1;
	} 
	return res;
}

inline i64 inv (i64 x) { return ksm (x, mod - 2); }

int f[maxn << 1][maxn];
int sum[maxn << 1][2];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n;
	rep (i, 1, (n << 1)) { int x; std::cin >> x; nums[i] = std::pair <int, bool> { x, i > n }; }

	std::sort (nums + 1, nums + (n << 1) + 1);
	std::reverse (nums + 1, nums + (n << 1) + 1);

	rep (i, 1, (n << 1)) {
		rep (b, 0, 1) {
			sum[i][b] = sum[i - 1][b] + (nums[i].second == b);
		}
	}

	rep (i, 1, (n << 1)) {
		i64 now = nums[i].first;
		i64 cnt = sum[i][nums[i].second ^ 1];

		f[i][0] = 1;
		rep (j, 1, std::min ((int) i >> 1, n)) {
			(f[i][j] += 1ll * f[i - 1][j - 1] * now % mod * std::max ((cnt - (j - 1)), 0ll) % mod) %= mod;
			(f[i][j] += f[i - 1][j]) %= mod;
		}
	}

	i64 ans = f[n << 1][n];
	rep (i, 1, n) { ans *= inv (i); ans %= mod; }
	std::cout << ans << "\n";

	return 0;
}

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

const int maxn = 200005;
const int mod = 1e9 + 7;

int n, m;

struct Node {
	int x, y;
} a[maxn];

inline i64 ksm(i64 x, i64 y) {
	x %= mod;
	i64 res = 1;
	while (y) {
		if (y & 1) (res *= x) %= mod;
		(x *= x) %= mod; y >>= 1;
	}
	return res;
}

inline i64 inv(i64 x) { return ksm(x, mod - 2); }

i64 fac[maxn], ifac[maxn];
inline void init(int R) {
	fac[0] = 1;
	rep (i, 1, R) fac[i] = fac[i - 1] * i % mod;
	ifac[R] = inv(fac[R]);
	per (i, R - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

inline i64 choose(int a, int b) {
	if (a < b) return 0;
	return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

namespace Task1 {
	void solve() {
		std::cout << ksm(4, n) << "\n";
	}
}

namespace Task2 {
	inline i64 calc(int sx, int sy, int tx, int ty) {
		int xl = std::abs(sx - tx);
		int yl = std::abs(sy - ty);
		int len = xl + yl;

		if (m < len) return 0;
		if ((m - len) & 1) return 0;

		int cnt = (m - len) >> 1;

		return choose(m, xl) * choose(m - xl, yl) % mod * ksm(4, cnt) % mod;
	}

	void solve() {
		init(m);

		int mxx = -0x3f3f3f3f, mxy = -0x3f3f3f3f;
		int mnx = 0x3f3f3f3f, mny = 0x3f3f3f3f;

		rep (i, 1, n) mxx = std::max(mxx, a[i].x);
		rep (i, 1, n) mxy = std::max(mxy, a[i].y);
		rep (i, 1, n) mnx = std::min(mnx, a[i].x);
		rep (i, 1, n) mny = std::min(mny, a[i].y);

		i64 ans = 0;
		rep (x, mxx - m, mnx + m) {
			rep (y, mxy - m, mny + m) {

				i64 cur = 1;
				rep (i, 1, n) {
					(cur *= calc(a[i].x, a[i].y, x, y)) %= mod;
				}
				ans += cur;
			}	
		}

		std::cout << ans << "\n";
	}
}

void solve() {
	std::freopen("wolf.in", "r", stdin);
	std::freopen("wolf.out", "w", stdout);

	std::cin >> n >> m;

	rep (i, 1, n) std::cin >> a[i].x >> a[i].y;

	if (n == 1) Task1::solve();
	else Task2::solve();
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

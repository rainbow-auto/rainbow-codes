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
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

using i128 = __int128;

constexpr int N = 1000000;
constexpr i64 mod = 666623333;
constexpr i128 $1 = 1;

i64 l, r;

std::vector<i64> ps;
inline void seive() {
	std::bitset<N + 5> vis;
	rep (i, 2, N) {
		if (not vis[i])	ps.push_back(i);
		for (auto p : ps) {
			if (i * p > N) break;
			vis.set(i * p);
			if (i % p == 0) break;
		}
	}
}

inline i128 ksm(i128 a, i128 b) {
	i64 res = 1;
	for (; b; (a *= a) %= mod, b >>= 1) if (b & 1) (res *= a) %= mod;
	return res;
}

inline i128 inv(i128 x) {
	return ksm(x, mod - 2);
}

i128 a[N + 5], ans[N + 5];

void solve() {
	std::cin >> l >> r;

	seive();

	rep (i, l, r) a[i - l] = i;
	rep (i, l, r) ans[i - l] = 1;

	for (auto p : ps) {
		i128 inv_p = inv(p);
		for (i128 k = (l / p); k <= (r / p); k++) {
			i128 x = p * k;
			if (x < l) continue;
			if (x > r) break;

			while (a[x - l] % p == 0) a[x - l] /= p;
			(ans[x - l] *= $1 * (p - 1) % mod * inv_p % mod) %= mod;
		}
	}

	rep (i, l, r) if (a[i - l] > 1) (ans[i - l] *= $1 * (a[i - l] - 1) % mod * inv(a[i - l]) % mod) %= mod;

	i64 res = 0;
	rep (i, l, r) {
		(res += (i % mod - $1 * i * ans[i - l] % mod + mod) % mod) %= mod;
	}

	std::cout << res << "\n";
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

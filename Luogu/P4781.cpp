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

const i64 mod = 998244353;
const int maxn = 2005;

inline i64 ksm(i64 a, i64 b) {
	a %= mod;
	i64 res = 1;
	for (; b; (b >>= 1), (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
	return res;
}

inline i64 inv(i64 x) { return ksm(x, mod - 2); }

int n;
i64 k;
i64 x[maxn], y[maxn];

i64 h(i64 i) {
	i64 p = 1, q = 1;
	rep (j, 1, n) {
		if (j == i) continue;
		(p *= (k - x[j]) % mod) %= mod;
		(q *= (x[i] - x[j]) % mod) %= mod;
	}
	return p * inv(q) % mod;
}

void solve() {
	std::cin >> n >> k;

	rep (i, 1, n) std::cin >> x[i] >> y[i];

	i64 res = 0;
	rep (i, 1, n) {
		(res += y[i] % mod * h(i) % mod) %= mod;
	}

	(res += mod) %= mod;

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

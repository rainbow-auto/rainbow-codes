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

constexpr int maxn = 100005; 
constexpr int mod = 998244353;

int n, k;
i64 a[maxn], b[maxn];

inline i64 ksm(i64 a, i64 b) {
	a %= mod;
	i64 res = 1;
	for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
	return res;
}

void solve() {
	std::cin >> n >> k;
	if (k == 0) return std::cout << n << "\n", void(0);

	rep (i, 1, n) {
		std::cin >> a[i];
		((a[i] %= mod) += mod) %= mod;
	}
	
	rep (i, 1, n) {
		std::cin >> b[i];
		((b[i] %= mod) += mod) %= mod;
	}

	i64 w = 0;
	rep (i, 1, n) (w += a[i] * b[i] % mod) %= mod;

	w = ksm(w, k - 1);

	i64 s1 = 0;
	rep (i, 1, n) (s1 += a[i] % mod) %= mod;

	i64 s2 = 0;
	rep (i, 1, n) (s2 += b[i] % mod) %= mod;

	std::cout << s1 * s2 % mod * w % mod << "\n";
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

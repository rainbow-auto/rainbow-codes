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

namespace NTT {
	const i64 g = 3, mod = 998244353;

	inline i64 ksm(i64 a, i64 b) {
		i64 res = 1;
		for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
		return res;
	}

	inline i64 inv(i64 x) { return ksm(x, mod - 2); }

	const int maxb = 21;
	const int maxn = 1 << maxb;
	i64 cache[maxn << 1], *pw = cache + maxn;
	inline void init() {
		i64 v = ksm(g, (mod - 1) / maxn);
		pw[0] = pw[0 - maxn] = 1;
		rep (i, 1, maxn - 1) pw[i] = pw[i - maxn] = pw[i - 1] * v % mod;
	}

	inline void DFT(std::vector<i64> &a, int c) {
		int len = a.size();

		std::vector<i64> org = a;
		rep (i, 0, len - 1) {
			int pos = 0;
			rep (b, 0, maxb - 1) if (i & (1 << b)) pos += (len >> (b + 1));
			a[pos] = org[i];
		}

		for (int h = 2; h <= len; h <<= 1) {
			for (int i = 0; i < len; i += h) {
				for (int j = i; j < i + (h >> 1); j++) {
					i64 u = a[j] % mod;
					i64 v = a[j + (h >> 1)] % mod * pw[(maxn / h) * c * (j - i)] % mod;
					a[j] = (u + v >= mod ? u + v - mod : u + v); 
					a[j + (h >> 1)] = (u - v < 0 ? u - v + mod : u - v);
				}
			}
		}

		if (c == -1) {
			i64 inv_n = inv(len);
			rep (i, 0, len - 1) (a[i] *= inv_n) %= mod;
		}
	}

	inline std::vector<i64> mul(std::vector<i64> a, std::vector<i64> b) {
		int len = 1;
		while (len < a.size() + b.size()) len <<= 1;
		a.resize(len); b.resize(len);

		DFT(a, 1);
		DFT(b, 1);

		std::vector<i64> c(len);
		rep (i, 0, len - 1) c[i] = a[i] * b[i] % mod;
		
		DFT(c, -1);
		return c;
	}
}	

void solve() {
	int n, m; std::cin >> n >> m;

	std::vector<i64> a(n + 1);
	for (auto &x : a) std::cin >> x;
	
	std::vector<i64> b(m + 1);
	for (auto &x : b) std::cin >> x;

	NTT::init();
	auto c = NTT::mul(a, b);

	rep (i, 0, n + m) std::cout << c[i] << " \n"[i == n + m];
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

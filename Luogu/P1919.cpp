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

namespace NTT {
	const i64 mod = 998244353, g = 3;

	inline i64 ksm(i64 a, i64 b) {
		i64 res = 1;
		for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
		return res;
	}

	inline i64 inv(i64 x) {
		return ksm(x, mod - 2);
	}

	const int maxb = 21;
	const int maxn = 1 << maxb;
	int cache[maxn << 1], *pw = cache + maxn;
	inline void init() {
		i64 wn = ksm(g, (mod - 1) / maxn);
		pw[0] = pw[0 - maxn] = 1;
		rep (i, 1, maxn - 1) pw[i] = pw[i - maxn] = 1ll * pw[i - 1] * wn % mod;
	}

	int rev[maxn];

	inline void DFT(std::vector<int> &a, int c) {
		int len = a.size();
		rep (i, 0, len - 1) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
		
		for (int h = 2; h <= len; h <<= 1) {
			for (int j = 0; j < len; j += h) {
				for (int i = j; i < j + (h >> 1); i++) {
					i64 u = 1ll * a[i] % mod;
					i64 v = 1ll * a[i + (h >> 1)] * pw[maxn / h * c * (i - j)] % mod;
					a[i] = (u + v >= mod ? u + v - mod : u + v);
					a[i + (h >> 1)] = (u - v < 0 ? u - v + mod : u - v);
				}
			}
		}

		if (c == -1) {
			i64 inv_len = inv(len);
			rep (i, 0, len - 1) a[i] = 1ll * a[i] * inv_len % mod;
		}
	}

	inline std::vector<int> mul(std::vector<int> a, std::vector<int> b) {
		int t = a.size() + b.size();
		int len = 1; while (len < t) len <<= 1;
		a.resize(len); b.resize(len);

		rep (i, 0, len - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (len >> 1));

		DFT(a, 1); DFT(b, 1);

		std::vector<int> c(len);
		rep (i, 0, len - 1) c[i] = 1ll * a[i] * b[i] % mod;
		
		DFT(c, -1);

		return c;
	}
}

std::string s;
inline void input(std::vector<int> &a) {
	std::cin >> s;
	per (i, (int) s.size() - 1, 0) a.push_back(s[i] - '0');
}

void solve() {
	std::vector<int> a, b;
	input(a); input(b);

	NTT::init();
	auto c = NTT::mul(a, b);

	c.push_back(0);
	rep (i, 0, (int) c.size() - 2) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}

	int st = c.size() - 1;
	while (st and c[st] == 0) st--;
	per (i, st, 0) std::cout << char(c[i] + '0');

	lookTime
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

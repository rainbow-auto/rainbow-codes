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

i64 n, A, B, mod;

constexpr int maxn = 3;
struct Matrix {
	std::array<std::array<i64, maxn>, maxn> a;

	std::array<i64, maxn>& operator[](int i) { return a[i]; }

	inline void clr() {
		for (auto &x : a) x.fill(0);
	}
	
	friend Matrix operator * (Matrix a, Matrix b) {
		Matrix c; c.clr();
		rep (i, 0, 2) rep (k, 0, 2) rep (j, 0, 2) {
			(c[i][j] += a[i][k] * b[k][j] % mod) %= mod;
		}
		return c;
	}
};

Matrix e = Matrix {{{
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1}
}}};

inline Matrix ksm(Matrix a, i64 b) {
	Matrix res = e;
	for (; b; b >>= 1, a = a * a) if (b & 1) res = res * a;
	return res;
}

void solve() {
	std::cin >> n >> A >> B >> mod;

	auto up = [&](i64 a, i64 b) -> i64 {
		return (a - 1) / b + 1;
	};

	Matrix ans = {{{
		{ 0, A % mod, 1 },
		{ 0, 0, 0 },
		{ 0, 0, 0 }
	}}};
	
	i64 pw = 10ll;
	rep (len, 1, 18) {
		if (pw > A) {
			Matrix P = {{{
				{ pw % mod, 0, 0 },
				{ 1 , 1, 0 },
				{ 0 , B % mod, 1 }
			}}};

			i64 cnt = up(pw - A, B);
			cnt = std::min(cnt, n);
			n -= cnt;

			if (cnt) {
				A += B * cnt;
				ans = ans * ksm(P, cnt);
			}
		}

		pw *= 10ll;
	}
	
	std::cout << ans[0][0] << "\n";
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

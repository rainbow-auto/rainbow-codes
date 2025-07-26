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

constexpr int maxn = 105;
constexpr int mod = 1e9 + 7;

int n;
i64 k;

template<int maxn>
struct Matrix {
	std::array<std::array<int, maxn>, maxn> a;
	std::array<int, maxn>& operator[](int i) { return a[i]; }

	inline void clr() {
		for (auto &x : a) x.fill(0);
	}

	inline void I() {
		clr();
		rep (i, 0, maxn - 1) a[i][i] = 1;
	}

	friend Matrix operator * (Matrix a, Matrix b) {
		Matrix c; c.clr();
		rep (i, 0, maxn - 1) rep (k, 0, maxn - 1) rep (j, 0, maxn - 1) {
			(c[i][j] += (1ll * a[i][k] * b[k][j] % mod)) %= mod;
		}
		return c;
	}
};

Matrix <100> a;

Matrix<100> ksm(Matrix<100> a, i64 b) {
	Matrix<100> res; res.I();
	for (; b; b >>= 1, (a = a * a)) if (b & 1) res = res * a;
	return res;
}

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n) rep (j, 1, n) {
		std::cin >> a[i][j];
	}

	a = ksm(a, k);
	
	rep (i, 1, n) rep (j, 1, n) {
		std::cout << a[i][j] << " \n"[j == n];
	}
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

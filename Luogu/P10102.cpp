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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int mod = 998244353;
constexpr int maxn = 3005;

struct Matrix {
	int n, m;
	std::vector<std::vector<int>> a;
	std::vector<int>& operator[](int i) { return a[i]; }

	Matrix(int _n, int _m) {
		n = _n; m = _m;
		a.resize(n);
		for (auto &x : a) x.assign(m, 0);
	}

	friend Matrix operator* (Matrix a, Matrix b) {
		assert(a.m == b.n);
		Matrix c(a.n, b.m);
		rep (i, 0, a.n - 1) rep (k, 0, b.n - 1) rep (j, 0, b.n - 1) 
			(c[i][j] += 1ll * a[i][k] * b[k][j] % mod) %= mod; 
		return c;
	}

	friend bool operator == (Matrix a, Matrix b) {
		if (a.n != b.n) return false;
		if (a.m != b.m) return false;

		rep (i, 0, a.n - 1) rep (j, 0, a.m - 1) if (a[i][j] != b[i][j]) return false;
		return true;
	}
};

int n;

void solve() {
	std::cin >> n;

	Matrix A(n, n), B(n, n), C(n, n);
	rep (i, 0, n - 1) rep (j, 0, n - 1) std::cin >> A[i][j];
	rep (i, 0, n - 1) rep (j, 0, n - 1) std::cin >> B[i][j];
	rep (i, 0, n - 1) rep (j, 0, n - 1) std::cin >> C[i][j];

	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	Matrix D(1, n);
	auto chk = [&]() -> bool {
		rep (i, 0, n - 1) D[0][i] = rng() % mod;
	
		Matrix lhs = D * A * B;
		Matrix rhs = D * C;

		return lhs == rhs;
	};

	bool x = true;
	rep (k, 0, 2) x &= chk();

	if (x) return std::cout << "Yes\n", void(0);
	else return std::cout << "No\n", void(0);
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

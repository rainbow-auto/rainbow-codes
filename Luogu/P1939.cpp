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
#define MultiTask lovely_fairytale

const int mod = 1e9 + 7;

struct Matrix {
	int a[3][3];

	inline void init(bool flg) {
		std::memset(a, 0, sizeof a);
		if (flg) rep (i, 0, 2) a[i][i] = 1;
	}

	Matrix(bool flg = false) { init(flg); }

	int* operator[] (int i) { return a[i]; }

	friend Matrix operator *(Matrix a, Matrix b) {
		Matrix res;
		rep (i, 0, 2) {
			rep (j, 0, 2) {
				rep (k, 0, 2) {
					(res[i][j] += 1ll * a[i][k] * b[k][j] % mod) %= mod;
				}
			}
		}

		return res;
	}
};

inline Matrix ksm(Matrix a, i64 b) {
	Matrix res(1);
	while (b) {
		if (b & 1) res = res * a; 
		b >>= 1; a = a * a;
	}

	return res;
}

void solve() {
	i64 n; std::cin >> n;

	if (n <= 3) return std::cout << "1\n", void(0);

	Matrix a;
	a[0][0] = 1; a[0][1] = 1; a[0][2] = 1;
	Matrix b;
	b[0][0] = 1; b[0][1] = 1; b[0][2] = 0;
	b[1][0] = 0; b[1][1] = 0; b[1][2] = 1;
	b[2][0] = 1; b[2][1] = 0; b[2][2] = 0;

	auto res = a * ksm(b, n - 3);
	
	std::cout << res[0][0] << "\n";
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

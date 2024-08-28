#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

i64 p;

struct Matrix {
	i64 mat[2][2];

	i64* operator[] (int i) { return mat[i]; }

	friend Matrix operator * (Matrix a, Matrix b) {
		Matrix res = { { { 0, 0 }, { 0, 0 } } };
		rep (i, 0, 1) {
			rep (j, 0, 1) {
				rep (k, 0, 1) {
					res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % p) % p;
				}
			}
		}
		return res;
	}
};

constexpr Matrix e = Matrix { { { 1, 0 }, { 0, 1 } } };

inline Matrix ksm (Matrix a, i64 b) {
	Matrix res = e;
	while (b) {
		if (b & 1) { res = res * a; }
		a = a * a; b >>= 1;
	}
	return res;
}

inline i64 bsgs (Matrix a, Matrix b, Matrix c) {
	std::unordered_map <i64, i64> R;
	
	i64 m = (i64) sqrt (p) + 1;
	rep (j, 0, m) { 
		Matrix curr = ksm (a, j) * c;
		R[curr[0][0]] = j; 
	}

	Matrix base = ksm (a, m);
	Matrix pw = base;
	rep (i, 1, m + 1) {
		Matrix curr = pw * b;
		pw = pw * base; 
		if (not R.count (curr[0][0])) { continue; }
		return i * m - R[curr[0][0]];
	}
	return -1;
}

i64 a, b, s, g;

inline i64 solve () {
	std::cin >> p;
	std::cin >> a >> b >> s >> g;
	if (not a) {
		if (g == s) { return 0; }
		if (g == b) { return 1; }
		return -1;
	}

	Matrix A = Matrix { { { a, b }, { 0, 1 } } };
	Matrix B = Matrix { { { s, 0 }, { 1, 0 } } };
	Matrix C = Matrix { { { g, 0 }, { 1, 0 } } };

	return bsgs (A, B, C);
}

bool MemED;
int main () {
	fastread
	// lookMem	

	int T; std::cin >> T;

	while (T--) { std::cout << solve () << "\n"; }

	return 0;
}

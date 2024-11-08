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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const i64 mod = 1e9 + 7;

struct Matrix {
	i64 mat[5][5];

	inline void init (int x = 0) {
		memset (mat, 0, sizeof (mat));
		if (x == 1) { rep (i, 0, 4) { mat[i][i] = 1; } }
	}	

	i64* operator[] (int i) { return mat[i]; }

	friend Matrix operator * (Matrix x, Matrix y) {
		Matrix res; res.init ();

		rep (i, 0, 4) {
			rep (j, 0, 4) {
				rep (k, 0, 4) {
					res[i][j] += x[i][k] * y[k][j] % mod;
					res[i][j] %= mod;
				}
			}
		}
		return res;
	}
};

inline Matrix ksm (Matrix a, i64 b) {
	Matrix base = a;
	Matrix res; res.init (1);

	while (b) {
		if (b & 1) { res = res * base; }
		base = base * base; b >>= 1;
	}

	return res;
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	Matrix t = Matrix { {
		{ 1, 1, 1, 0, 1 }, 
		{ 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 1, 1 },
		{ 0, 0, 1, 0, 1 }, 
		{ 0, 0, 0, 0, 1 }
	} };

	Matrix st = { {
		{ 1, 0, 1, 0, 1 }
	} };

	int _; std::cin >> _;
	while (_--) {
		i64 n; std::cin >> n;
		i64 T = n - 3;
		if (T < 0) { std::cout << 0 << "\n"; continue; }

		Matrix res = st * ksm (t, T);

		std::cout << res[0][4] * 2ll % mod << "\n";
	}

	return 0;
}

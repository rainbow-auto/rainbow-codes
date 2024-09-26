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

const int mod = 1e9 + 7;

int n, m;

struct Matrix {
	int a[3][3];

	Matrix(bool flag = false) {
		memset(a, 0, sizeof a);
		if (flag) rep (i, 0, 2) a[i][i] = 1;
	}
	
	int* operator[] (int i) { return a[i]; }

	friend Matrix operator* (Matrix a, Matrix b) {
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

Matrix ksm(Matrix a, i64 b) {
	Matrix res(1);
	Matrix base = a;
	while (b) {
		if (b & 1) res = res * base;
		base = base * base; b >>= 1;
	}
	return res;
}

void solve() {
	Matrix a;
	a[0][0] = 1;

	Matrix t1;
	t1[0][0] = 1; t1[0][1] = 2; t1[0][2] = 1;
	t1[1][0] = 0; t1[1][1] = 1; t1[1][2] = 1;
	t1[2][0] = 1; t1[2][1] = 2; t1[2][2] = 2; 

	Matrix t2;
	t2[0][0] = 1; t2[0][1] = 2; t2[0][2] = 1;
	t2[1][0] = 0; t2[1][1] = 1; t2[1][2] = 1;
	t2[2][0] = 0; t2[2][0] = 0; t2[2][2] = 1;

	std::cin >> n >> m;

	int last = -1;
	rep (i, 1, m) {
		int now; std::cin >> now;
		a = a * ksm(t1, now - last - 1);
		a = a * t2;
		last = now;
	}

	a = a * ksm(t1, n - last - 1);

	std::cout << a[0][2] << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}

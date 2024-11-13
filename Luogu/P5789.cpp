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
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 105;
const int mod = 2017;

int n, m;
i64 k;

struct Matrix {
	int a[maxn][maxn];
	Matrix(bool flg = false) {
		std::memset(a, 0, sizeof a);
		if (flg) rep (i, 0, n) a[i][i] = 1;
	}

	int* operator[] (int i) { return a[i]; }

	friend Matrix operator * (Matrix a, Matrix b) {
		Matrix res;
		rep (i, 0, n) {
			rep (j, 0, n) {
				rep (k, 0, n) {
					(res[i][j] += a[i][k] * b[k][j] % mod) %= mod;					
				}
			}
		}
		return res;
	}
};

inline Matrix ksm(Matrix a, i64 b) {
	Matrix res(1);
	for (; b; b >>= 1, a = a * a) if (b & 1) res = res * a;
	return res;
}

void solve() {
	std::cin >> n >> m;
	Matrix g;
	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		g[u][v]++, g[v][u]++;
	}	

	rep (i, 1, n) g[i][0] ++;
	rep (i, 0, n) g[i][i] ++;

	std::cin >> k;
	g = ksm(g, k);

	i64 ans = 0;
	rep (i, 0, n) (ans += g[1][i]) %= mod;
	std::cout << ans << "\n";
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

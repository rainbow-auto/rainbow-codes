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

constexpr int maxn = 55;
constexpr int mod = 1e9 + 7;

int n, K;

i64 f[maxn][maxn][maxn * maxn * 2 + 5];

void solve() {
	std::cin >> n >> K;

	int dt = maxn * maxn;

	f[0][0][0 + dt] = 1;
	rep (i, 1, n) {
		rep (j, 0, i) {
			rep (k, -n * n, n * n) {
				(f[i][j][k + dt] += f[i - 1][j][k + dt]) %= mod;
				if (j) (f[i][j][k + dt] += f[i - 1][j][k + dt] * 2 * j % mod) %= mod;
				if (j + 1 <= i - 1 and k - 2 * i >= -n * n) (f[i][j][k + dt] += f[i - 1][j + 1][k - 2 * i + dt] * (j + 1) % mod * (j + 1) % mod) %= mod;
				if (j > 0 and k + 2 * i <= n * n) (f[i][j][k + dt] += f[i - 1][j - 1][k + 2 * i + dt]) %= mod;
				// db << f[i][j][k + dt] << " ";
			}
			// dbendl;
		}
	}

	std::cout << f[n][0][K + dt] << "\n";
}

/*
0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 3 0 1 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 
0 0 0 0 0 3 0 2 0 1 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 4 0 9 0 4 0 1 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 5 0 3 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
*/

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

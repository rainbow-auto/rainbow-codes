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

constexpr int maxn = 3005;
constexpr int mod = 1e9 + 7;

int n, m;
bool flg[maxn][maxn];

int f[maxn][maxn];

i64 calc(int sx, int sy, int tx, int ty) {
	if (flg[sx][sy]) return 0;
	std::memset(f, 0, sizeof f);
	f[sx][sy] = 1;
	rep (i, 1, n) rep (j, 1, m) {
		if (flg[i][j]) {
			f[i][j] = 0;
		} else {
			f[i][j] += (f[i - 1][j] + f[i][j - 1]) % mod;
		}
	}

	return f[tx][ty];
}

void solve() {
	std::cin >> n >> m;

	rep (i, 1, n) {
		rep (j, 1, m) {
			char c; std::cin >> c;
			flg[i][j] = (c == '#');
		}
	}	

	int ans = ((calc(1, 2, n - 1, m) * calc(2, 1, n, m - 1) % mod - calc(1, 2, n, m - 1) * calc(2, 1, n - 1, m) % mod) % mod + mod) % mod;
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

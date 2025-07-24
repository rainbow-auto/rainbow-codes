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
constexpr i64 inf = 1e18;

int n;
i64 w[maxn];

i64 f[maxn][maxn][maxn];
i64 X;

inline i64 calc(int M) {
	rep (i, 0, n) rep (j, 0, n) rep (k, 0, n) f[i][j][k] = -inf;

	f[0][0][0] = 0;
	rep (i, 1, n) {
		rep (j, 0, i) {
			rep (k, 0, M - 1) {
				f[i][j][k] = std::max(f[i][j][k], f[i - 1][j][k]);
				if (j and f[i - 1][j - 1][((k - w[i]) % M + M) % M] != -inf) f[i][j][k] = std::max(f[i][j][k], f[i - 1][j - 1][((k - w[i]) % M + M) % M] + w[i]);
			}
		}
	}

	return f[n][M][X % M];
}

void solve() {
	std::cin >> n >> X;
	rep (i, 1, n) std::cin >> w[i];

	i64 ans = inf;
	rep (K, 1, n) {
		dbg(K);
		i64 sum = calc(K);
		db << sum << "\n";
		if (sum != -inf) ans = std::min(ans, (X - sum) / K);
	}

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

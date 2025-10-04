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

constexpr int mod = 998244353;

constexpr int maxn = 105;
constexpr int maxm = 2005;

int n, m;
i64 a[maxn][maxm];
i64 sum[maxn];

i64 f[maxn][maxn << 1];
i64 calc(int k) {
	std::memset(f, 0, sizeof f);
	
	int dt = 100;
	f[0][0 + dt] = 1;
	rep (i, 1, n) {
		rep (cur, -n, n) {
			(f[i][cur + 1 + dt] += f[i - 1][cur + dt] * a[i][k] % mod) %= mod;
			(f[i][cur - 1 + dt] += f[i - 1][cur + dt] * (((sum[i] - a[i][k]) % mod + mod)) % mod % mod) %= mod;
			f[i][cur + dt] += f[i - 1][cur + dt];
		}
	}

	i64 res = 0;
	rep (c, 1, n) (res += f[n][c + dt]) %= mod;

	return res;
}

void solve() {
	std::cin >> n >> m;

	i64 ans = 1;
	rep (i, 1, n) {
		rep (j, 1, m) {
			std::cin >> a[i][j];
			(sum[i] += a[i][j]) %= mod;
		}
		(ans *= (sum[i] + 1)) %= mod;
	}

	rep (j, 1, m) {
		i64 x = calc(j);
		db << j << ": " << x << "\n";
		(((ans -= x) %= mod) += mod) %= mod;
	}
	
	std::cout << ans - 1 << "\n";
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

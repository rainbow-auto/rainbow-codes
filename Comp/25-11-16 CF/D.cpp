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

constexpr int maxn = 5010;
constexpr int mod = 998244353;

int n;
int a[maxn];
i64 t[maxn];

i64 f[maxn][maxn];

void clr() {
	rep (i, 0, n + 1) rep (j, 0, n) f[i][j] = 0;
	rep (i, 0, n) t[i] = 0;
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) t[a[i]]++;

	t[++n] = 0;
	std::sort(t + 1, t + n + 1, [&](int u, int v) -> bool {
		return u > v;
	});

	f[n + 1][0] = 1;
	per (i, n, 1) {
		rep (j, 0, n) f[i][j] = f[i + 1][j];

		rep (j, 0, n) {
			if (0 <= t[i] + j and t[i] + j <= n) {
				(f[i][t[i] + j] += f[i + 1][j] * t[i] % mod) %= mod;
			}
		}
	}

	// rep (i, 1, n) rep(j, 0, n) db << f[i][j] << " \n"[j == n];

	i64 ans = 0;
	
	i64 pre_sum = 0;
	i64 pre_f = 1;

	rep (i, 1, n) {
		int mx = t[i];
		// pre_sum + nxt_sum >= mx; 
		rep (nxt_sum, 0, n) {
			if (pre_sum + nxt_sum >= mx) {
				(ans += 1ll * pre_f * f[i + 1][nxt_sum] % mod) %= mod;
			}
		}

		pre_sum += t[i];
		(pre_f *= t[i]) %= mod;

		if (not mx) break;
	}

	std::cout << ans << "\n";

	clr();

	// db << "--------\n";
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

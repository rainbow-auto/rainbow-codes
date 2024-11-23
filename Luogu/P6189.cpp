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

const int maxn = 100005;
const int maxB = 333;

int n;
int mod;

i64 f[maxn];
i64 g[maxB][maxn];

void solve() {
	std::cin >> n >> mod;

	int B = (int) sqrt(n) + 1;

	// calc f
	f[0] = 1;
	rep (i, 1, B - 1) {
		rep (j, i, n) {
			(f[j] += f[j - i]) %= mod;
		}
	}

	// calc g
	g[0][0] = 1;
	rep (i, 1, B - 1) {
		rep (j, i, n) {
			g[i][j] = g[i][j - i];
			if (j >= B) (g[i][j] += g[i - 1][j - B]) %= mod;
		}
	}

	i64 ans = 0;
	rep (j, 0, n) {
		i64 cur = 0;
		rep (i, 0, B - 1) (cur += g[i][n - j]) %= mod;
		(ans += (f[j] * cur) % mod) %= mod;
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

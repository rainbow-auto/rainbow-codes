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

const int maxn = 3005;
const int mod = 1e9 + 7;

int n, s, t;
int f[maxn][maxn];

void solve() {
	std::cin >> n >> s >> t;
	
	f[1][1] = 1; // 放入 s
	rep (i, 2, n) {
		rep (j, 1, i) {
			if (i != s and i != t) f[i][j] = (f[i - 1][j - 1] * (j - (i > s) - (i > t)) % mod + f[i - 1][j + 1] * j % mod) % mod;
			else f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod;
		}
	}

	std::cout << f[n][1] << "\n";
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

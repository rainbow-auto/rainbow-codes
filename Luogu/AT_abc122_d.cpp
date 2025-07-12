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

const int maxn = 105;
const int mod = 1e9 + 7;

int n;
int f[maxn][4][4][4];

void solve() {
	std::cin >> n;

	f[0][0][0][0] = 1;
	int T = 0;
	int A = 1;
	int G = 2;
	int C = 3;

	rep (i, 1, n) {
		rep (x, 0, 3) rep (y, 0, 3) rep (z, 0, 3) rep (t, 0, 3) {
			if (y == A and z == G and t == C) continue;
			if (y == G and z == A and t == C) continue;
			if (y == A and z == C and t == G) continue;
			if (x == A and z == G and t == C) continue;
			if (x == A and y == G and t == C) continue;

			(f[i][y][z][t] += f[i - 1][x][y][z]) %= mod;
		}
	}

	i64 ans = 0;
	rep (x, 0, 3) rep (y, 0, 3) rep (z, 0, 3) {
		(ans += f[n][x][y][z]) %= mod;		
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

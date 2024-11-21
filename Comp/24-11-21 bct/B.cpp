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
const int maxS = 1000005;

int mod; 

int n, k;
i64 f[maxn][maxS];

void solve() {
	std::cin >> n >> k >> mod;

	int sum = 0;
	f[0][0] = 1;
	rep (i, 1, n) {
		sum += i * k;
		rep (j, 0, sum) f[i][j] = f[i - 1][j];
		rep (j, i, sum) (f[i][j] += f[i][j - i]) %= mod;
		int d = i * (k + 1);
		per (j, sum, d) (((f[i][j] -= f[i][j - d]) %= mod) += mod) %= mod;
	}

	rep (x, 1, n) {
		i64 res = 0;
		rep (S, 0, sum) (res += f[n - x][S] * f[x - 1][S] % mod) %= mod;
		std::cout <<((res * (k + 1) % mod - 1) % mod + mod) % mod << "\n";
	}
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

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

constexpr int maxn = 505;

int n;
int a[maxn];
int c[maxn];

int f[maxn][maxn][maxn];

inline bool chkmin(int& x, int y) {
	return y < x ? x = y, 1 : 0;
}

void solve() {
	std::cin >> n;

	int tot = 0;
	rep (i, 1, n) {
		std::cin >> a[i];
		a[i] &= 1;
		tot += a[i];
	}
	rep (i, 1, n) std::cin >> c[i];
	
	rep (i, 0, n) rep (j, 0, n) rep (k, 0, n) std::memset(&f[i][j][k], 0x3f, sizeof f[i][j][k]);
	f[0][0][0] = 0;
	rep (i, 0, n - 1) {
		rep (j, 0, n) {
			rep (k, 0, n) {
				if (f[i][j][k] == 0x3f3f3f3f) continue;
				rep (t, 0, 1) {
					chkmin(f[i + 1][j + t][k + ((j + t) & 1)], f[i][j][k] + (a[i + 1] == t ? 0 : c[i + 1]));
				}
			}
		}
	}

	rep (i, 0, n) {
		if (f[n][tot][i] == 0x3f3f3f3f) std::cout << "-1 ";
		else std::cout << f[n][tot][i] << " ";
	}
	std::cout << "\n";
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

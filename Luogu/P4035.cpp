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

const int maxn = 205;

int n;
f64 pos[maxn][maxn];

f64 a[maxn][maxn];
inline void gauss() {
	rep (i, 1, n) {
		int t = i;
		rep (j, i + 1, n) {
			if (std::abs(a[j][i]) > std::abs(a[t][i])) t = j;
		}
		std::swap(a[t], a[i]);

		per (j, n + 1, i) a[i][j] /= a[i][i];

		rep (j, i + 1, n) {
			per (k, n + 1, i) a[j][k] -= a[j][i] * a[i][k];
		}
	}

	per (i, n - 1, 1) rep (j, i + 1, n) a[i][n + 1] -= a[i][j] * a[j][n + 1];
}

void solve() {
	std::cin >> n;	
	rep (i, 1, n + 1) rep (j, 1, n) std::cin >> pos[i][j];

	rep (i, 1, n) {
		rep (j, 1, n) {
			a[i][j] = 2.0 * (pos[i][j] - pos[i + 1][j]);
			a[i][n + 1] += (pos[i][j] * pos[i][j] - pos[i + 1][j] * pos[i + 1][j]);
		}
	}

	rep (i, 1, n) {
		rep (j, 1, n + 1) db << a[i][j] << " ";
		dbendl;
	}

	gauss();

	rep (i, 1, n) std::printf("%.3lf ", a[i][n + 1]);
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

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

const int maxn = 55;

int n;
f64 a[maxn][maxn];

inline void display() {
	rep (i, 1, n) rep (j, 1, n + 1) db << a[i][j] << " \n"[j == n + 1];
}

const f64 eps = 1e-10;
inline int gauss() {
	int rnkA = 0; // 系数矩阵的秩
	rep (i, 1, n) {
		int t = rnkA + 1;
		rep (j, rnkA + 1, n) {
			if (std::fabs(a[j][i]) > std::fabs(a[t][i])) t = j; 
		}

		if (std::fabs(a[t][i]) < eps) continue;
		rnkA++;
		std::swap(a[rnkA], a[t]);

		per (j, n + 1, i) a[rnkA][j] /= a[rnkA][i];

		rep (j, rnkA + 1, n) {
			per (k, n + 1, i) a[j][k] -= a[rnkA][k] * a[j][i];
		}
	}

	if (rnkA == n) {
		per (i, n - 1, 1) rep (j, i + 1, n) a[i][n + 1] -= a[i][j] * a[j][n + 1];
		return -1; // 有唯一解
	} else {
		rep (i, rnkA + 1, n) if (std::fabs(a[i][n + 1]) > eps) return 0; // 无解
		return 1; // 无穷多解
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) rep (j, 1, n + 1) std::cin >> a[i][j];
	
	int st = gauss();

	if (not ~st) rep (i, 1, n) std::printf("x%d=%.2lf\n", i, a[i][n + 1]);
	else if (st == 1) std::cout << "0\n";
	else std::cout << "-1\n";
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

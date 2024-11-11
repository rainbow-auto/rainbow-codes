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

const int maxn = 2005;
const int maxq = 200005;

int n, m, q;

bool a[maxn][maxn];

int sum[maxn][maxn];

inline int qry(int i, int l, int r) {
	if (l > r) return 0;
	l = std::max(l, 1);
	return sum[i][r] - sum[i][l - 1];
}

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) {
		rep (j, 1, n) {
			char ch; std::cin >> ch;
			a[i][j] = ch == 'O';
			sum[i][j] = sum[i][j - 1] + a[i][j];
		}
	}

	std::cin >> q;
	// count (s, t) | s <= u, t <= v, 2s + t > 2u + v - 2m
	rep (i, 1, q) {
		int u, v; std::cin >> u >> v;
		int res = 0;
		rep (s, 1, u) {
			// 2u + v - 2m -2s < t <= v
			res += qry(s, 2 * u + v - 2 * m - 2 * s + 1, v);
		}
		std::cout << res << "\n";
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

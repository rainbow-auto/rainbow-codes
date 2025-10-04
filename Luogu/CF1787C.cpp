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

constexpr int maxn = 200005;

int n, s;
int a[maxn];

i64 b[maxn][2];
i64 f[maxn][2];

void solve() {
	std::cin >> n >> s;
	rep (i, 1, n) std::cin >> a[i];

	rep (i, 2, n - 1) {
		if (a[i] <= s) {
			b[i][0] = 0;
			b[i][1] = a[i];
		} else {
			b[i][0] = s;
			b[i][1] = a[i] - s;
		}
	}

	b[1][0] = b[1][1] = a[1];
	b[n][0] = b[n][1] = a[n];

	rep (i, 0, n) f[i][0] = f[i][1] = 1e18;

	f[1][1] = f[1][1] = 0;

	rep (i, 2, n) {
		rep (p, 0, 1) {
			rep (q, 0, 1) {
				f[i][p] = std::min(f[i][p], f[i - 1][q] + b[i - 1][q ^ 1] * b[i][p]);
			}
		}
	}

	std::cout << std::min(f[n][0], f[n][1]) << "\n";
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

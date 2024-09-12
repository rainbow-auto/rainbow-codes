#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 2005;

int k;

int c[maxn][maxn];
int sum[maxn][maxn];

inline void init (int R) {
	rep (i, 0, R) { c[i][i] = c[i][0] = 1; }
	rep (i, 1, R) {
		rep (j, 1, i - 1) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
		}
	}

	rep (i, 1, R) {
		rep (j, 1, R) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (bool) (c[i][j] == 0 and j <= i);
		}
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _; std::cin >> _;
	std::cin >> k;

	init (2000);

	while (_--) {
		int n, m; std::cin >> n >> m;

		std::cout << sum[n][m] << "\n";
	}

	return 0;
}

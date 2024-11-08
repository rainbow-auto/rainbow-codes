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
bool MemST;

const int maxn = 25;
const int maxS = (1 << 20) + 5;

int n;
int a[maxn][maxn];
int dp[maxn][maxS];

inline void print (int S) {
	std::cerr << "S: "; 
	rep (i, 0, n - 1) { if (S & (1 << i)) { std::cerr << 1; } else { std::cerr << 0; } } 
	std::cerr << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n;

	rep (i, 0, n - 1) {
		rep (j, 0, n - 1) {
			std::cin >> a[i][j];
		}
	}

	memset (dp, 0x3f, sizeof (dp));

	dp[0][1] = 0;
	rep (S, 1, (1 << n) - 1) {
		rep (i, 0, n - 1) {
			if (not (S & (1 << i))) { continue; }
			rep (j, 0, n - 1) {
				if (i == j) { continue; }
				if (not (S & (1 << j))) { continue; }
				dp[i][S] = std::min (dp[i][S], dp[j][S ^ (1 << i)] + a[i][j]);
			}
		}
	}

	std::cout << dp[n - 1][(1 << n) - 1] << "\n";	

	return 0;
}

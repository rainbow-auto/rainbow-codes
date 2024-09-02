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

const int maxn = 255;

int n, m;
int a[maxn];

int f[maxn][maxn][maxn << 1]; // f_{i, j, k} 前 i 个数, 第 i 个数为 j, 有 k 个富余 / 缺少

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n >> m;
	rep (i, 1, n) { std::cin >> a[i]; }

	int inf; memset (&inf, 0x3f, sizeof (int));
	memset (f, 0x3f, sizeof (f));
	f[0][m][0 + m] = 0;

	rep (i, 0, n - 1) {
		rep (j, 0, m) {
			rep (k, -m, m) {
				if (f[i][j][k + m] >= inf) { continue; }
				rep (nxt, 0, j) {
					if ((k + a[i + 1] - nxt) + m < 0) { continue; }

					int& to = f[i + 1][nxt][(k + a[i + 1] - nxt) + m];
					to = std::min (to, f[i][j][k + m] + (int) abs (k + a[i + 1] - nxt));
				}
			}
		}	
	}

	int ans = inf;
	rep (j, 0, m) { ans = std::min (ans, f[n][j][0 + m]); }
	std::cout << ans << "\n";

	return 0;
}

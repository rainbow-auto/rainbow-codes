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

const int maxn = 505;

int n, k;
int a[maxn][maxn];

namespace Solution {
    int sum[maxn][maxn][maxn];

    inline void init () {
        rep (c, 1, n) {
            rep (i, 1, n) {
                rep (j, 1, n) {
                    sum[i][j][c] = sum[i - 1][j][c] + sum[i][j - 1][c] - sum[i - 1][j - 1][c] + (a[i][j] == c);
                }
            }
        }
    }

    inline bool query (int c, int x1, int y1, int x2, int y2) {
        return sum[x2][y2][c] - sum[x1 - 1][y2][c] - sum[x2][y1 - 1][c] + sum[x1 - 1][y1 - 1][c];
    }

    inline bool chk (int x1, int y1, int x2, int y2) {
        int cnt = 0;
        rep (c, 1, n) { cnt += query (c, x1, y1, x2, y2); }
        return cnt <= k;
    }

    int ans[maxn][maxn];
    inline void _solve (int Lx, int Ly) {
        int len = 0;
        while (Lx <= n and Ly <= n) {
            while (Lx + len <= n and Ly + len <= n and chk (Lx, Ly, Lx + len, Ly + len)) { len ++; }
            ans[Lx][Ly] = std::max (ans[Lx][Ly], len);
            Lx ++; Ly ++; len --; 
        }
    }

    inline void solve () {
        init ();

        rep (i, 1, n) { _solve (i, 1); }
        rep (j, 1, n) { _solve (1, j); }

        rep (i, 1, n) {
            rep (j, 1, n) {
                std::cout << ans[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
}


bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    freopen ("square.in", "r", stdin);
    freopen ("square.out", "w", stdout);

    std::cin >> n >> k;
    rep (i, 1, n) {
        rep (j, 1, n) {
            std::cin >> a[i][j];
        }
    }

    Solution::solve ();

	return 0;
}

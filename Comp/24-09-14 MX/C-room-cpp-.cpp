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

const int maxn = 1005;

int n, m;
bool a[maxn][maxn];

namespace Task1 {
    const int maxn = 23;

    const int dx[] = { 0, 1, -1, 0 };
    const int dy[] = { 1, 0, 0, -1 };

    bool vis[maxn][maxn];
    void dfs (int x, int y) {
        if (not a[x][y]) { return; }

        vis[x][y] = true;
        if (x == n and y == m) { return; }

        rep (i, 0, 3) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (not vis[nx][ny]) { dfs (nx, ny); }
        }
    }

    inline bool chk (int x1, int y1, int x2, int y2) {
        a[x1][y1] = a[x2][y2] = true;
        memset (vis, 0, sizeof (vis));
        dfs (1, 1);
        a[x1][y1] = a[x2][y2] = false;
        return vis[n][m];
    }

    inline void solve () {
        int ans = 0;
        rep (x1, 1, n) {
            rep (y1, 1, m) {
                if (a[x1][y1]) { continue; }
                rep (x2, 1, n) {
                    rep (y2, 1, m) {
                        if (a[x2][y2]) { continue; }
                        if (x1 == x2 and y1 == y2) { continue; }

                        ans += chk (x1, y1, x2, y2);
                    }
                }
            }
        }
        std::cout << ans / 2 << "\n";
    }
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    freopen ("room.in", "r", stdin);
    freopen ("room.out", "w", stdout);

    std::cin >> n >> m;
    rep (i, 1, n) {
        rep (j, 1, m) {
            char ch; std::cin >> ch;
            a[i][j] = ch == '.';
        }
    }

    Task1::solve ();

	return 0;
}

#include <iostream>

const int maxn = 2005;

int n, m;
int a[maxn][maxn];

namespace Task1 {
    int dp[maxn][maxn];
    
    inline bool get (int S, int pos) { return S & (1 << (pos - 1)); }

    inline int getid (int S, int pos) {
        int fst = get (S, ((pos - 1) << 1 | 1));
        int sec = get (S, (pos << 1));

        return ((fst << 1) | sec);
    }

    struct Node {
        int x, y;
    };

    Node ns[maxn];
    int cnt;

    int cur[maxn][maxn];
    bool chk (int S) {
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= m + 1; j++) {
                cur[i][j] = 1;
            }  
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cur[i][j] = 0;
            }
        }

        for (int i = 1; i <= cnt; i++) {
            if (getid (S, i) == 0) {
                cur[ns[i].x][ns[i].y] ++;
                cur[ns[i].x][ns[i].y - 1] ++;
                cur[ns[i].x + 1][ns[i].y] ++;
            } else if (getid (S, i) == 1) {
                cur[ns[i].x][ns[i].y] ++;
                cur[ns[i].x][ns[i].y + 1] ++;
                cur[ns[i].x + 1][ns[i].y] ++;
            } else if (getid (S, i) == 2) {
                cur[ns[i].x][ns[i].y] ++;
                cur[ns[i].x][ns[i].y - 1] ++;
                cur[ns[i].x - 1][ns[i].y] ++;
            } else if (getid (S, i) == 3) {
                cur[ns[i].x][ns[i].y] ++;
                cur[ns[i].x][ns[i].y + 1] ++;
                cur[ns[i].x - 1][ns[i].y] ++;
            }
        }

        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= m + 1; j++) {
                if (cur[i][j] > 1) { return false; }
            }  
        }
        return true;
    }

    inline void solve () {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == 1) { ns[++cnt] = Node { i, j }; }
            }
        }

        int ans = 0;
        for (int S = 0; S < (1 << (cnt << 1)); S++ ) {
            ans += chk (S);
        }

        std::cout << ans << "\n";
    }   
}

int main () {

    // freopen ("almostconvex.in", "r", stdin);
    // freopen ("almostconvex.out", "w", stdout);

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch; std::cin >> ch;
            a[i][j] = ch - '0';
        }
    }

    Task1::solve ();

    return 0;
}
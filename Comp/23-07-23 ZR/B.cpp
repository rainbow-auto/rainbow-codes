#include <iostream>

#define int long long

using namespace std;

const int maxn = 250005;

int n;
int x[maxn], y[maxn], w[maxn];
int maxx, maxy;

namespace Task2 {
    const int maxn = 5005;

    int a[maxn][maxn];
    int sum[maxn][maxn];

    void init () {
        for (int i = 1; i <= maxx; i++) {
            for (int j = 1; j <= maxy; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
            }
        }
    }

    int query (int x1, int y1, int x2, int y2) {
        return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
    }

    void solve () {
        init ();

        int ans = -0x3f3f3f3f3f3f3f3f;    
        for (int i = 1; i <= maxx; i++) {
            for (int j = i; j <= maxx; j++) {
                for (int k = 1; k <= maxy; k++) {
                    ans = max (ans, query(i, 1, j, k));
                }
            }
        }

        cout << ans << endl;
    }
}

signed main () {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> w[i];
        maxx = max (maxx, x[i]);
        maxy = max (maxy, y[i]);
    }

    if (maxx <= 800 and maxy <= 800) {
        for (int i = 1; i <= n; i++) {
            Task2::a[x[i]][y[i]] += w[i];
        }
        
        Task2::solve();
    } else {
        cout << "摆烂" << endl;
    }

    return 0;
}
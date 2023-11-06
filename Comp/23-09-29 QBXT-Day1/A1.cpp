#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 505;

int a[maxn][maxn];

int n, K;

int s[maxn][maxn][maxn];

inline int getSum (int k, int x1, int y1, int x2, int y2) {
    return s[x2][y2][k] - s[x2][y1 - 1][k] - s[x1 - 1][y2][k] + s[x1 - 1][y1 - 1][k];
}

int main () {

    freopen ("square.in", "r", stdin);
    freopen ("square.out", "w", stdout);

    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    cin >> n >> K;

    int maxCol = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            maxCol = max (a[i][j], maxCol);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= maxCol; k++) {
                s[i][j][k] = s[i - 1][j][k] + s[i][j - 1][k] - s[i - 1][j - 1][k];
            }
            s[i][j][a[i][j]] ++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int l = 1, r = n - max (i, j) + 1;
            int ans = 0;

            while (l <= r) {
            
                int mid = (l + r) >> 1;

                int sum = 0;
                for (int col = 1; col <= maxCol; col ++) {
                    sum += ( getSum (col, i, j, i + mid - 1, j + mid - 1) > 0);
                }

                if (sum > K) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                    ans = mid;
                }
            }

            cout << ans << " ";
        }
        cout << "\n";
    }

    return 0;
}
#include <iostream>

using namespace std;

const int maxn = 505;

int a[maxn][maxn];

int n, K;

int s[maxn][maxn][maxn];

inline int getSum (int k, int x1, int y1, int x2, int y2) {
    return s[k][x2][y2] - s[k][x2][y1 - 1] - s[k][x1 - 1][y2] + s[k][x1 - 1][y1 - 1];
}

int main () {

    freopen ("square.in", "r", stdin);
    freopen ("square.out", "w", stdout);

    cin >> n >> K;

    int maxCol = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            maxCol = max (a[i][j], maxCol);
        }
    }

    for (int k = 0; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                s[k][i][j] = s[k][i - 1][j] + s[k][i][j - 1] - s[k][i - 1][j - 1] + (a[i][j] == k);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int k;
            for (k = 1; i + k - 1 <= n and j + k - 1 <= n; k++) {
                int sum = 0;
                for (int col = 1; col <= maxCol; col ++) {
                    sum += ( getSum (col, i, j, i + k - 1, j + k - 1) > 0);
                }

                if (sum > K) {
                    break;
                } 
            }

            cout << k - 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
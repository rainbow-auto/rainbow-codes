#include <iostream>

using namespace std;

const int maxn = 100;
int g[maxn][maxn][maxn];

int n = 4;

int clac (int now) {
    int cnt = 0;

    for (int a = 1; a <= n; a++)
    for (int b = 1; b <= n; b++)
    for (int c = 1; c <= n; c++) {
        if (g[now][a][b] and g[now][b][c] and g[now][c][a]){
            cnt++;
        }
    }
    return cnt;
}

int main() {

    int ans = 0;
    int k = 0;

    int now = 0;
    for (int S1 = 0; S1 < (1 << (n - 1)); S1++)
    for (int S2 = 0; S2 < (1 << (n - 1)); S2++)
    for (int S3 = 0; S3 < (1 << (n - 1)); S3++)
    for (int S4 = 0; S4 < (1 << (n - 1)); S4++) {
        now ++;

        for (int i = 1; i <= n; i++) {
            if (S1 & (1 << (i - 1))) {
                g[now][1][i] = 1;
            }
            if (S2 & (1 << (i - 1))) {
                g[now][2][i] = 1;
            }
            if (S3 & (1 << (i - 1))) {
                g[now][3][i] = 1;
            }
            if (S4 & (1 << (i - 1))) {
                g[now][4][i] = 1;
            }
        }
        
        if (clac(now) < ans) {
            ans = clac(now);
            k = now;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[k][i][j];
        }
        cout << endl;
    }

    return 0;
}
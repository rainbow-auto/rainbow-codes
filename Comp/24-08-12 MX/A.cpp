#include <iostream>

#define rep(iii, iist, iied) for (int iii = (iist); iii <= (iied); iii++)

const int maxn = 2005;

int n, m;
char a[maxn][maxn];

int main () {

    std::cin >> n >> m;

    rep (i, 0, n + 1) {
        rep (j, 0, m + 1) {
            a[i][j] = char('z' + 1);
        }
    }

    rep (i, 1, n) {
        rep (j, 1, m) {
            std::cin >> a[i][j];
        }
    }

    int nowx = 1;
    int nowy = 1;

    std::string ans; ans = ans + a[nowx][nowy];
    while (not (nowx == n and nowy == m)) {
        if (a[nowx + 1][nowy] < a[nowx][nowy + 1]) { ans = ans + a[nowx + 1][nowy]; nowx ++; }
        else { ans = ans + a[nowx][nowy + 1]; nowy ++; }
    }

    std::cout << ans << "\n";

    return 0;
}
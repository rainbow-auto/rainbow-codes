#include <iostream>

const int maxn = 55;

int W, H;
int sx, sy;

int a[maxn][maxn];

int main () {

    std::cin >> H >> W;

    std::cin >> sx >> sy;

    for (int i = 0; i <= H + 1; i++) {
        for (int j = 0; j <= W + 1; j++) {
            a[i][j] = 1;
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            char c; std::cin >> c;
            a[i][j] = (c == '#');
        }
    }

    std::string op; std::cin >> op;

    int nowx = sx, nowy = sy;

    for (auto p : op) {
        if (p == 'U') {
            if (not a[nowx - 1][nowy]) { nowx --; }
        } else if (p == 'D') {
            if (not a[nowx + 1][nowy]) { nowx ++; }
        } else if (p == 'L') {
            if (not a[nowx][nowy - 1]) { nowy --; }
        } else if (p == 'R') {
            if (not a[nowx][nowy + 1]) { nowy ++; }
        }
    }

    std::cout << nowx << " " << nowy << "\n";

    return 0;
}
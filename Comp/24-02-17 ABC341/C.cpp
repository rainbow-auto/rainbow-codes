#include <iostream>
#include <string>

const int maxn = 505;

char a[maxn][maxn];

int h, w, n;

std::string op;

inline bool check (int nowx, int nowy) {
    if (a[nowx][nowy] == '#') { return false; }
    
    for (auto c : op) {
        if (c == 'L') { nowy --; }
        if (c == 'R') { nowy ++; }
        if (c == 'U') { nowx --; }
        if (c == 'D') { nowx ++; }
        
        if (a[nowx][nowy] == '#') { return false; }
    
    }
    return true;
}

int main () {

    std::cin >> h >> w >> n;

    std::cin >> op;

    for (int i = 0; i <= h + 1; i++) {
        for (int j = 0; j <= w + 1; j++) {
            a[i][j] = '#';
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            std::cin >> a[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (check (i, j)) { ans ++; }
        }
    }

    std::cout << ans << "\n";

    return 0;
}
#include <iostream>
#include <string>

using i64 = long long;

const int maxn = 10;

int n;

char a[maxn][maxn];
std::string r;
std::string c;

bool check () {
    for (int i = 1; i <= n; i++) {
        int dcnt = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '.') {  dcnt ++; continue; }
            if (a[i][j] != r[i]) { 
                if (j == 1) { return false; }    
                else { a[i][j - 1] = r[i]; }
            }
        }

        if (dcnt == n) { a[i][1] = r[i]; }
    }

    return true;
}

inline void display () {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << a[i][j];
        }
        std::cout << "\n";
    }
}

void dfs (int now) {
    if (now > n) {
        if (check ()) { std::cout << "Yes\n"; display (); exit (0); } 

        return;
    }

    for (int i = 1; i <= n; i++) {
        a[i][now] = c[now];
        dfs (now + 1);    
        a[i][now] = '.';
    }
}

int main () {

    std::cin >> n;

    std::cin >> r; r = " " + r;
    std::cin >> c; c = " " + c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = '.';
        }
    }

    dfs (1);

    std::cout << "No\n";

    return 0;
}
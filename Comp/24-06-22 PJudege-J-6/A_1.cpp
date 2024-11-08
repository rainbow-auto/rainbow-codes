#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 105;

int n, m;
int q;

char ops[maxn];

char c[maxn][maxn];

inline void apply (char op) {
    if (op == 'L') {
        for (int i = 1; i <= n; i++) {
            std::vector<char> s;
            for (int j = 1; j <= m; j++) {
                if (c[i][j] == '.') { continue; }
                s.push_back (c[i][j]);
                c[i][j] = '.';
            }

            int now = 1;
            for (auto x : s) {
                c[i][now] = x;
                now ++;
            }
        }
    } else if (op == 'R') {
        for (int i = 1; i <= n; i++) {
            std::vector<char> s;
            for (int j = 1; j <= m; j++) {
                if (c[i][j] == '.') { continue; }
                s.push_back (c[i][j]);
                c[i][j] = '.';
            }

            std::reverse (s.begin (), s.end ());

            int now = m;
            for (auto x : s) {
                c[i][now] = x;
                now --;
            }
        }
    } else if (op == 'U') {
        for (int j = 1; j <= m; j++) {
            std::vector<char> s;
            for (int i = 1; i <= n; i++) {
                if (c[i][j] == '.') { continue; }
                s.push_back (c[i][j]);
                c[i][j] = '.';
            }

            int now = 1;
            for (auto x : s) {
                c[now][j] = x;
                now ++;
            }
        }
    } else if (op == 'D') {
        for (int j = 1; j <= m; j++) {
            std::vector<char> s;
            for (int i = 1; i <= n; i++) {
                if (c[i][j] == '.') { continue; }
                s.push_back (c[i][j]);
                c[i][j] = '.';
            }

            std::reverse (s.begin (), s.end ());

            int now = n;
            for (auto x : s) {
                c[now][j] = x;
                now --;
            }
        }
    }
}

int main () {

    std::cin >> n >> m >> q;

    for (int i = 1; i <= q; i++) { std::cin >> ops[i]; }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> c[i][j];
        }
    }

    for (int i = 1; i <= q; i++) {
        apply (ops[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cout << c[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}
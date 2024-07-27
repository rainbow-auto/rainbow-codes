#include <iostream>
#include <set>

#pragma GCC Optimize("Ofast")

const int maxn = 505;

int n, m;

bool a[maxn][maxn];

std::set <int> mem[maxn][maxn];

std::set <int> dfs (int i, int j) {
void dfs (int i, int j) {
    std::set <int> res;

    if (not j) { res.insert (i); return res; }

    if (mem[i][j].size ()) { return mem[i][j]; }

    if (a[i][j]) {
        if (i == 1) { 
            res = dfs (i + 1, j - 1);
        } else if (i == n) {
            res = dfs (i - 1, j - 1);
        } else {
            auto x = dfs (i + 1, j - 1);
            auto y = dfs (i - 1, j - 1);

            if (x.size () > y.size ()) {
                for (auto it : y) { x.insert (it); }
                res = x;
            } else {
                for (auto it : x) { y.insert (it); }
                res = y;
            }
        }
    } else {
        res = dfs (i, j - 1);
    }

    mem[i][j] = res;
    return mem[i][j];
}

inline void clear () {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m + 1; j++) {
            mem[i][j].clear ();
        }
    }
}

int main () {

    int T; std::cin >> T;

    while (T--) {
        std::cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m + 1; j++) {
                char c; std::cin >> c;
                if (c == '1') { a[i][j] = 1; }
                else { a[i][j] = 0; }
            }
        }

        for (int i = 1; i <= n; i++) {
            auto res = dfs (i, m + 1);
            std::cout << res.size () << " ";
        }        
        std::cout << "\n";

        clear ();
    }

    return 0;
}
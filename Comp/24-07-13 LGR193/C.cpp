#include <iostream>
#include <algorithm>

using i64 = long long;

const int maxn = 25;
const int maxm = 1000005;

int n, m;

int rules[maxn][maxm];

namespace Task1 {
    bool can[maxm][maxn];

    int ord[maxm];
    
    int result[maxn][maxm];

    inline void update () {
        for (int i = 1; i <= (1 << n); i++) { result[n + 1][i] = ord[i]; }
        
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= (1 << (i - 1)); j++) {
                if (rules[i][j] == 1) {
                    result[i][j] = std::max (result[i + 1][(j << 1) - 1], result[i + 1][j << 1]);
                } else {
                    result[i][j] = std::min (result[i + 1][(j << 1) - 1], result[i + 1][j << 1]);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= (1 << (i - 1)); j++) {
                can[result[i][j]][n - i + 2] = true;
            }
        }
    }

    inline void pre () {
        for (int i = 1; i <= (1 << n); i++) { ord[i] = i; }   

        do {
            update ();
        } while (std::next_permutation (ord + 1, ord + (1 << n) + 1));
    }

    inline void solve () {
        pre ();
     
        while (m--) {
            int a, b; std::cin >> a >> b;
            
            if (can[a][b]) { std::cout << "Yes\n"; }
            else { std::cout << "No\n"; }
        }
    }
}

namespace Task2 {
    inline void solve (bool flag, int cnt1, int cnt2) {
        while (m--) {
            int a, b; std::cin >> a >> b;

            if (flag) {
                if (a >= (1 << (b - 1))) { std::cout << "Yes\n"; }
                else { std::cout << "No\n"; }
            } else {
                bool ans = false;
                if (cnt1 == 0) { ans = (a < n - 1); }   
                else if (cnt2 == 0) { ans = (a > 1); }
                else { ans = true; }

                if (ans) { std::cout << "Yes\n"; }
                else { std::cout << "No\n"; }
            }
        }
    }
}

int main () {

    std::cin >> n >> m;

    bool Task2Flag = true;

    int cnt1 = 0, cnt2 = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (1 << (i - 1)); j++) {
            std::cin >> rules[i][j];
            if (i == n) { cnt1 += (rules[i][j] == 1); cnt2 += (rules[i][j] == 2); }
            Task2Flag &= (rules[i][j] == 1);
        }
    }

    Task2::solve (Task2Flag, cnt1, cnt2);

    return 0;
}
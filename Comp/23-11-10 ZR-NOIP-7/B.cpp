#include <iostream>

using i64 = long long;

const int maxn = 100005;
const int maxm = 30;

int n, m;

i64 a[maxn][maxm];
i64 b[maxn];

namespace Subtask1 {
    const i64 inf = 10000000000000000;

    i64 ans = inf;
    
    inline void solve () {
        for (int S = 1; S < (1 << m); S++) {
            i64 ans_now = 0;

            for (int i = 1; i <= m; i++) {
                if (S & (1 << (i - 1))) {
                    ans_now += b[i];
                }
            }       

            for (int i = 1; i <= n; i++) {
                i64 min_cost = inf;
                for (int j = 1; j <= m; j++) {
                    if (S & (1 << (j - 1))) {
                        min_cost = std::min (min_cost, a[i][j]);
                    }
                }
                ans_now += min_cost;
            }

            ans = std::min (ans, ans_now);
        }

        std::cout << ans << "\n";
    }
}

int main () {

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++) { std::cin >> b[i]; }

    Subtask1::solve ();

    return 0;
}
#include <iostream>
#include <cstring>

using i64 = long long;

int C, T;

i64 n, m, k, d;

namespace Subtask1 {
    const int maxn = 105;

    i64 x[maxn], y[maxn], v[maxn];

    bool run[maxn];
    i64 sum[maxn];

    inline i64 get_sum (int l, int r) { 
        if (l <= or r <= 0) { return 0; }
        return sum[r] - sum[l - 1];
    }

    inline void solve () {
        while (T--) {
            memset (run, 0, sizeof (run));
            memset (x, 0, sizeof (x));
            memset (y, 0, sizeof (y));
            memset (v, 0, sizeof (v));
            memset (sum, 9, sizeof (sum));

            std::cin >> n >> m >> k >> d;

            for (int i = 1; i <= m; i++) { std::cin >> x[i] >> y[i] >> v[i]; }

            i64 ans = 0;

            for (int S = 0; S < (1 << (n + 1)); S++) {
                i64 curr = 0;
                
                int len_now = 0;
                int len = 0;
                for (int i = 1; i <= n; i++) { 
                    run[i] = S & (1 << i); 
                    sum[i] = sum[i - 1] + run[i];

                    if (run[i]) { curr -= d; }

                    if (not run[i]) { len_now = 0; continue; }
                    else { len_now ++; len = std::max (len, len_now); }
                }

                if (len > k) { continue; }
                
                for (int i = 1; i <= m; i++) {
                    if (get_sum (x[i] - y[i] + 1, x[i]) == y[i]) { curr += v[i]; }
                }

                ans = std::max (ans, curr);
            }

            std::cout << ans << "\n";
        }
    }
}

int main () {

    std::cin >> C >> T;

    if (C == 1 or C == 2) { Subtask1::solve (); }

    return 0;
}

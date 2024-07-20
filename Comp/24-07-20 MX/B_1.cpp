#include <iostream>

using i64 = long long;

#define db(x) std::cerr << #x << " : " << x << "\n";

const int maxn = 305;
const i64 mod = 1e9 + 7;

int siz[2];

struct Limit {
    int l, r;
};
Limit a[2][maxn];

int maxSum;

namespace Task1 {

    i64 dp[2][maxn][maxn * maxn];

    inline void init (int id) {
        for (int sum = a[id][1].l; sum <= a[id][1].r; sum ++) { dp[id][1][sum] = 1; }

        auto last = a[id][1];

        for (int i = 2; i <= siz[id]; i++) {
            for (int pre = last.l; pre <= last.r; pre ++) {
                for (int now = a[id][i].l; now <= a[id][i].r; now++) {
                    dp[id][i][pre + now] += dp[id][i - 1][pre];
                    dp[id][i][pre + now] %= mod;
                }
            }

            last = Limit { last.l + a[id][i].l, last.r + a[id][i].r };
        }
    }

    inline void solve () {
        init (0); init (1);

        for (int i = 1; i <= siz[0]; i ++) {
            for (int j = 1; j <= siz[1]; j ++) {
                i64 ans = 0;
                
                for (int sum = 0; sum <= maxSum; sum ++) {
                    ans += dp[0][i][sum] * dp[1][j][sum];
                    ans %= mod;
                }

                std::cout << ans << " ";
            }
           std::cout << "\n";
        }
    }
}

int main () {

    // freopen ("sum.in", "r", stdin);
    // freopen ("sum.out", "w", stdout);

    std::cin >> siz[0] >> siz[1];

    int preA = 0;
    for (int i = 1; i <= siz[0]; i++) { std::cin >> a[0][i].l >> a[0][i].r; preA += a[0][i].r; }
    int preB = 0;
    for (int i = 1; i <= siz[1]; i++) { std::cin >> a[1][i].l >> a[1][i].r; preB += a[1][i].r; }

    maxSum = std::max (preA, preB);

    Task1::solve ();

    return 0;
}
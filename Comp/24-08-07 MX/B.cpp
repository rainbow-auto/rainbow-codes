#include <iostream>
#include <set>
#include <algorithm>

using i64 = long long;

const int maxn = 100005;
const i64 mod = 998244353;

int n, m;
i64 k;

int a[maxn], b[maxn];
i64 sum_a[maxn], sum_b[maxn];

std::set <i64> p;

namespace Task1 { // O (\sqrt{k} + n ^ 2)
    i64 cnt_a[maxn], cnt_b[maxn];
    
    inline void solve () {
        for (int l = 1; l <= n; l++) {
            for (int r = l; r <= n; r++) {
                cnt_a[sum_a[r] - sum_a[l - 1]] ++;
                cnt_a[sum_a[r] - sum_a[l - 1]] %= mod;
            }
        }

        for (int l = 1; l <= m; l++) {
            for (int r = l; r <= m; r++) {
                cnt_b[sum_b[r] - sum_b[l - 1]] ++;
                cnt_b[sum_b[r] - sum_b[l - 1]] %= mod;
            }
        }


        i64 ans = 0;
        for (auto now : p) {
            ans = (ans + cnt_a[now] * cnt_b[k / now]) % mod;
        }

        std::cout << ans << "\n";
    }
}

namespace Task2 { // O (\sqrt{k} + d(k) * n)
    i64 cnt[maxn];

    inline i64 countA (i64 x) {
        i64 res = 0;
        for (int r = 0; r <= n; r++) {
            if (sum_a[r] - x >= 0) { res += cnt[sum_a[r] - x]; res %= mod; }
            cnt[sum_a[r]]++;
        }

        for (int i = 0; i <= n; i++) { cnt[sum_a[i]] = 0; }

        return res;
    }

    inline i64 countB (i64 x) {
        i64 res = 0;
        for (int r = 0; r <= m; r++) {
            if (sum_b[r] - x >= 0) { res += cnt[sum_b[r] - x]; res %= mod; }
            cnt[sum_b[r]]++;
        }

        for (int i = 0; i <= m; i++) { cnt[sum_b[i]] = 0; }

        return res;
    }

    inline void solve () {
        i64 res = 0;
        for (auto now : p) {
            res = (res + countA (now) * countB (k / now)) % mod;
        }

        std::cout << res << "\n";
    }
}

int main () {

    freopen ("rain.in", "r", stdin);
    freopen ("rain.out", "w", stdout);

    std::cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; sum_a[i] = sum_a[i - 1] + a[i]; }
    for (int i = 1; i <= m; i++) { std::cin >> b[i]; sum_b[i] = sum_b[i - 1] + b[i]; }

    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            p.insert (i);
            if (k / i != i) { p.insert (k / i); }
        }
    }

    Task2::solve ();

    return 0;
}
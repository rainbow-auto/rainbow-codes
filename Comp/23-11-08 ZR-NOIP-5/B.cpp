#include <iostream>
#include <algorithm>
#include <vector>

using i64 = long long;

const int maxn = 3005;
const i64 mod = 998244353;

int n;
int fa[maxn];

i64 m;

namespace Subtask1 {
    inline i64 ksm (i64 a, i64 b) {
        i64 res = 1;
        i64 base = a;

        while (b) {
            if (b & 1) { res *= base; res %= mod; }
            b >>= 1; base *= base; base %= mod;
        }
        return res;
    }

    int a[maxn];

    inline void solve () {

        i64 ans = 0ll;

        for (int i = 1; i <= n; i++) { a[i] = i; }

        do {
            int k = 0;

            for (int i = 1; i <= n; i++) {
                int u = i, v = fa[i];

                bool flag = true;
                while (v) { flag &= a[u] <= a[v]; v = fa[v]; }
                k += flag;
            }
            
            ans += ksm (m, k);
            ans %= mod;
        } while (std::next_permutation (a + 1, a + n + 1));

        std::cout << ans << "\n";
    }
}

int main () {

    std::cin >> n >> m;

    for (int i = 2; i <= n; i++) { std::cin >> fa[i]; }

    Subtask1::solve ();

    return 0;
}
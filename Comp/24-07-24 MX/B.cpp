#include <iostream>
#include <unordered_map>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

#pragma GCC Optimize (2)
#pragma GCC Optimize (3)
#pragma GCC Optimize ("OFast")

using i64 = long long;

const int maxn = 100005;

i64 n;
int q;

namespace Solution {
    inline void solve () {
        while (q--) {
            i64 s; std::cin >> s;

            i64 len = s / (n + 1);
            i64 rest = s % (n + 1);

            std::cerr << len << " with " << rest << " rest\n";

            i64 ans = 0;
            if (rest == 0) { ans += (n / 2ll) - len + 1; }

            if (rest >= len + 1 and rest <= (n + 1) / 2ll) { ans ++; }
            if ((n - rest + 1 >= 1) and (n - rest + 1) + len <= (n / 2ll)) { ans++; }

            i64 lim = std::min (rest - 1, ((n + 1) / 2ll));
            if (rest == n + len + 2) { ans += lim; }
        
            std::cout << ans << "\n";
        }
    }
}

namespace Task1 {
    i64 sum[maxn];

    // std::unordered_map <i64, int> cnt;

    __gnu_pbds::gp_hash_table <i64, int> cnt;

    inline void solve () {
        for (int i = 1; i <= n; i++) {
            i64 curr;
            if (i & 1) { curr = (i + 1) / 2ll; }
            else { curr = n + 1 - i / 2ll; }

            sum[i] = sum[i - 1] + curr;
     
            cnt[sum[i]] ++;
        }
        cnt[0]++;

        while (q--) {
            i64 s; std::cin >> s;

            i64 ans = 0;
            for (int i = 1; i <= n; i++) {
                i64 suml = sum[i] - s;
                ans += cnt[suml];
            }

            std::cout << ans << "\n";
        }
    }
}

int main () {

    // freopen ("sequence.in", "r", stdin);
    // freopen ("sequence.out", "w", stdout);

    std::ios::sync_with_stdio (false);
    std::cin.tie (0); std::cout.tie (0);

    std::cin >> n >> q;

    // Solution::solve (); // 挂了
    Task1::solve (); 

    return 0;
}

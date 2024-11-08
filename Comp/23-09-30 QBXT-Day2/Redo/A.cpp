#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

const int maxn = 200005;

int n, m;
int a[maxn];

namespace Solution {

    bool is_prime[maxn];
    vector<int> primes;

    inline void getPrimes () {
        memset (is_prime, 1, sizeof (is_prime));

        for (int i = 2; i <= 200000; i++) { // a_i 值域是2e5
            if (is_prime[i]) { primes.push_back (i); }

            for (auto j : primes) {
                if (i * j > 200000) { break; }

                is_prime[i * j] = false;
                if (i % j == 0) { break; }
            }
        }
    }

    inline int get (int x, int p) {
        int res = 0;
        while (x) {
            res += x / p;
            x /= p;
        }
        return res;
    }

    int cnt[maxn]; // cnt[i] : 大于i的数的个数
    inline bool check (int now) {
        
        memset (cnt, 0, sizeof (cnt));
        for (int i = 1; i <= now; i++) { cnt[a[i]] ++; }
        for (int i = 200000; i >= 1; i--) { cnt[i] += cnt[i + 1]; } // 处理出大于等于i的数的个数

        for (auto p : primes) {
            int sum = 0;

            int base = p; // base = p ^ i
            for (int i = 1; base <= 200000; i++) {
                for (int j = 1; j * base <= 200000; j++) { // j * p ^ i
                    sum += cnt[j * base]; // 所有大于 j * p ^ i 的数的阶乘中都存在p 
                }
                base *= p; 
            }

            if (sum > get (n, p)) { return false; }
        }

        return true;
    }

    inline void solve () {
        getPrimes ();

        sort (a + 1, a + m + 1);

        int l = 1, r = m;
        int ans = -1;

        while (l <= r) {
            int mid = (l + r) >> 1;

            if (check (mid)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }

        cout << ans << endl;
    }
}

signed main () {

    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) { cin >> a[i]; }

    Solution::solve ();

    return 0;
}

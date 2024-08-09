#include <iostream>
#include <algorithm>
#include <map>
#include <ctime>

using i64 = long long;

const int maxn = 500005;

int n;
i64 a[maxn];

i64 cnt[maxn];

int main () {

    freopen ("divide.in", "r", stdin);
    freopen ("divide.out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        cnt[a[i]] ++;
    }

    std::sort (cnt + 1, cnt + n + 1);
    int l = 1, r = n;

    int ans = 0;
    while (l <= r) {
        i64 pre = 0;
        while (pre + cnt[l] < cnt[r]) {
            pre += cnt[l];
            l ++;
        }

        if (cnt[l] - (cnt[r] - 1 - pre) > 0) { cnt[l] -= (cnt[r] - 1 - pre); }

        ans ++;
        r--;
    }

    std::cout << ans << "\n";        

    return 0;
}
#include <iostream>

using i64 = long long;

const int maxn = 100005;

i64 n;
i64 k, Q;

inline bool check (i64 pre, i64 t, i64 x) {
    return pre + x * k >= t;
}

inline i64 solve (i64 pre, i64 t) {
    i64 l = 0, r = 1e9;
    i64 ans = -1;

    while (l <= r) {
        i64 mid = (l + r) >> 1;
        if (check (pre, t, mid)) { ans = mid; r = mid - 1; }
        else { l = mid + 1; }
    }

    // std::cerr << pre << " + " << ans << " * " << k << " >= " << t << "\n";

    return ans;
}

i64 pre[maxn];

int main () {

    std::cin >> n >> k >> Q;

    for (i64 i = 1; i <= n - 1; i++) { i64 now; std::cin >> now; pre[i] = pre[i - 1] + now; }

    while (Q--) {
        i64 id, t; std::cin >> id >> t;

        i64 ans = solve (pre[id - 1], t);
        ans = pre[id - 1] + ans * k - t;

        std::cout << ans << "\n";   
    }

    return 0;
}
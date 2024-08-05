#include <iostream>

const int maxn = 200005;

using i64 = long long;

i64 n, m;
i64 a[maxn];

int main () {

    std::cin >> n >> m;

    i64 sum = 0;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; sum += a[i]; }
    if (sum <= m) { std::cout << "infinite\n"; return 0; }

    i64 l = 0, r = 1e18;
    i64 res = 0;

    while (l <= r) {
        i64 mid = (l + r) >> 1;

        i64 curr = 0;
        for (int i = 1; i <= n; i++) { curr += std::min (a[i], mid); }

        if (curr <= m) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }   

    std::cout << res << "\n";

    return 0;
}
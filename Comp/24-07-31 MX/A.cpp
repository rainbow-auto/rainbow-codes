#include <iostream>

using i64 = long long;

const int maxn = 100005;

int n;
i64 a[maxn];

inline i64 f (i64 x) {
    i64 res = 0; while (x) { res += x % 10ll; x /= 10ll; }
    return res;
}

int main () {

    freopen ("digit.in", "r", stdin);
    freopen ("digit.out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    i64 ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans += f (a[i] + a[j]);
        }
    }
    ans *= 2ll;
    for (int i = 1; i <= n; i++) { ans += f (a[i] + a[i]); }

    std::cout << ans << "\n";

    return 0;
}
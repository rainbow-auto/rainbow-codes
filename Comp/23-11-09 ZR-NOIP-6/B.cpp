#include <iostream>
#include <algorithm>

using i64 = long long;

const int maxn = 5005;

int n, k, A, B;
int t[maxn];

namespace Subtask2 {
    inline void solve () {
        std::sort (t + 1, t + n + 1);

        i64 ans = 0;

        i64 sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += t[i];
            if (i % k == 0) {
                if (sum < A) { ans += sum; }
                else { ans += A; }
                sum = 0;
            }
        }

        if (sum) { ans += sum; }

        std::cout << ans << "\n";
    }
}

int main () {

    std::cin >> n >> k >> A >> B;
    for (int i = 1; i <= n; i++) { std::cin >> t[i]; }

    if (B == 0) { Subtask2::solve (); }

    return 0;
}
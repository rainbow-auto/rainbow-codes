#include <iostream>
#include <cstring>

const int maxn = 100005;

using i64 = long long;

int T;
i64 n;

i64 a[maxn];
i64 cnt[maxn];

i64 pre[maxn];
i64 pre2[maxn];

i64 col[maxn];

inline void clear () {
    for (int i = 0; i <= n; i++) { cnt[i] = 0; }
}

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n;

        i64 ans = 0;

        i64 curr = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];

            ans += a[i];
            cnt[a[i]] ++;
            if (cnt[a[i]] >= 2) { curr = std::max (curr, a[i]); }

            pre[i] = curr;
        }

        clear ();

        curr = 0;
        for (int i = 1; i <= n; i++) {
            ans += pre[i];
            cnt[pre[i]] ++;
            if (cnt[pre[i]] >= 2) { curr = std::max (curr, pre[i]); }
            
            pre2[i] = curr;
        }

        for (i64 i = 1; i <= n; i++) {
            ans += pre2[i] * (n - i + 1);
        }

        std::cout << ans << "\n";

        clear ();
    }

    return 0;
}
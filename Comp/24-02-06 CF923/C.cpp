#include <iostream>

using i64 = long long;

const int maxn = 400005;

int T;

int n, m, k;
int a[maxn], b[maxn];
int a_cnt[maxn], b_cnt[maxn];

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n >> m >> k;

        for (int i = 1; i <= n; i++) { std::cin >> a[i]; if (a[i] <= k) { a_cnt[a[i]] ++; } }
        for (int i = 1; i <= m; i++) { std::cin >> b[i]; if (b[i] <= k) { b_cnt[b[i]] ++; } }

        int a_only = 0, b_only = 0;
        for (int i = 1; i <= k; i++) {
            if (a_cnt[i] and not b_cnt[i]) { a_only ++; }
            if (b_cnt[i] and not a_cnt[i]) { b_only ++; }
            if (not a_cnt[i] and not b_cnt[i]) { std::cout << "NO\n"; goto end; }
        }

        if (a_only > k / 2) { std::cout << "NO\n"; goto end; }
        if (b_only > k / 2) { std::cout << "NO\n"; goto end; }
        std::cout << "YES\n";
        
        end:;
        
        for (int i = 1; i <= n; i++) { if (a[i] <= k) { a_cnt[a[i]] = 0; } }
        for (int i = 1; i <= m; i++) { if (b[i] <= k) { b_cnt[b[i]] = 0; } }
    }

    return 0;
}
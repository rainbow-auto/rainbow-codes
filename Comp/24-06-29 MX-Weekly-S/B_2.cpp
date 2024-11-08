#include <iostream>

const int maxn = 2000005;

int n, q;
int a[maxn];

int cnt[maxn];

inline void solve () {
    while (q--) {
        int op; std::cin >> op;

        if (op == 1) {
            int x; std::cin >> x;
            cnt[x] ++;
        } else if (op == 2) {
            int x; std::cin >> x;
            cnt[x] --;
        } else {
            int k; std::cin >> k;

            int ans = 0;
            for (int i = 1; i <= n; i++) {
                if (cnt[i] > k) { ans += cnt[i] - k; }
            }
            std::cout << ans << "\n";
        }
    }
}

int main () {

    std::cin >> n >> q;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; cnt[a[i]] ++; }

    solve ();

    return 0;
}
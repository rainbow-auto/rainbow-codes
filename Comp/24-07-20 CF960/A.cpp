#include <iostream>
#include <cstring>

const int maxn = 55;

int T;

int n;
int a[maxn];
int cnt[maxn];

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n;
        
        memset (cnt, 0, sizeof (cnt));

        int mx = 0;
        for (int i = 1; i <= n; i++) { std::cin >> a[i]; mx = std::max (mx, a[i]); cnt[a[i]] ++; }

        int col = 0;

        for (int i = n; i >= 1; i--) {
            if (cnt[i]) { col += cnt[i]; }
            if (col & 1) { std::cout << "YES\n"; goto IE; }
        }

        std::cout << "NO\n";

        IE:;
    }

    return 0;
}
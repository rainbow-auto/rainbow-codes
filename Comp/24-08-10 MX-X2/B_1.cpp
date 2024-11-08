#include <iostream>
#include <cstring>
#include <algorithm>

const int maxn = 500005;

#define int long long

int n;
int a[maxn];

int cnt[40];

signed main () {

    int T; std::cin >> T;

    while (T--) {
        std::cin >> n;

        for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

        std::sort (a + 1, a + n + 1);
        memset (cnt, 0, sizeof (cnt));

        int ans = 0;
        int tot0 = 0;

        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) { ans += n; continue; }

            int tot = 0;
            int fst = -1;
            for (int j = 30; j >= 0; j--) {
                if (a[i] & (1 << j)) { 
                    tot ++; 
                    if (tot == 1) { fst = j; }
                    else { ans += cnt[j]; }
                }
            }

            if (fst == -1) { continue; }
            cnt[fst] ++;
        }

        std::cout << ans << "\n";
    }


    return 0;
}
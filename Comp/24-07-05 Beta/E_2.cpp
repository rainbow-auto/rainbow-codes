#include <iostream>
#include <algorihtm>
#include <vector>
#include <cstring>

using i64 = long long;

const int maxn = 200005;

int n;

i64 a[maxn];
i64 v[10], lim[10];

i64 sum[maxn];

inline void clac () {

}

inline void solve () {
    int now[10]; memset (now, 0x3f, sizeof (now));
    int nxt[10]; memset (nxt, 0, sizeof (nxt));

    while (true) {
        for (int i = 1; i <= 4; i++) { nxt[i] = *std::lower_bound (a + 1, a + n + 1); }

    }
}

int main () {

    int T; std::cin >> T;

    while (T--) {
        std::cin >> n;

        for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

        for (int i = 1; i <= 4; i++) { std::cin >> lim[i]; }
        for (int i = 1; i <= 5; i++) { std::cin >> v[i]; }

        std::sort (a + 1, a + n + 1);

    }

    return 0;
}
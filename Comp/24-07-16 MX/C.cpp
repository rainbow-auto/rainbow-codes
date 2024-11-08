#include <iostream>
#include <set>
#include <cstring>

using i64 = long long;

const int maxn = 5005;

int n, m;
int s[maxn];

int cnt[maxn];

inline void solve (int l, int r) {
    for (int i = l; i <= r; i++) { s[i] ^= 1; }

    memset (cnt, 0, sizeof (cnt));
    
    int res = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] == 0) {
            int pos = i;
            while (pos >= 2 and s[pos - 1] == 0) { pos --; }
            cnt[pos - 1] ++;
        } else {
            int pos = i;
            while (pos <= n - 1 and s[pos + 1] == 1) { pos ++; }
            cnt[pos] ++;
        }
    }

    for (int i = 0; i <= n; i++) { res = std::max (res, cnt[i]); }

    std::cout << res << "\n";
}

int main () {

    freopen ("ball.in", "r", stdin);
    freopen ("ball.out", "w", stdout);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char c; std::cin >> c;
        if (c == '/') { s[i] = 0; }
        if (c == '\\') { s[i] = 1; }
    }

    while (m--) {
        int u, v; std::cin >> u >> v;
        solve (u, v);
    }

    return 0;
}
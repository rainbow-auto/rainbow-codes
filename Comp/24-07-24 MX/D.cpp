#include <iostream>

using i64 = long long;

const int maxn = 15;

int n, k;
int a[maxn];

namespace Task1 {

    int ans = 0;
    void dfs (int now, int xorsum, int rest) {
        if (now == n + 1) { ans += (xorsum == 0); return; }

        for (int i = 0; rest - i * a[now] >= 0; i++) {
            dfs (now + 1, xorsum xor a[now], rest - i * a[now]);
        }
    }

    inline void solve () {

    }
}

int main () {

    // freopen ("game.in", "r", stdin);
    // freopen ("game.in", "w", stdout);
    
    std::cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        
    }

    return 0;
}
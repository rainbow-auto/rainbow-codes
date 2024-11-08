#include <iostream>

const int maxn = 100005;

int n;
int a[maxn];
int b[maxn];

namespace Task1 {

    int ans = 0x3f3f3f3f;
    void dfs (int now, int S, int sum) {
        if (now == n + 1) { ans = std::min (ans, sum); return; }
        
        for (int i = 0; i <= 10; i++) {
            if (S & (1 << (a[now] + i))) { continue; }
            dfs (now + 1, S | (1 << a[now] + i), sum + i * b[now]);
        }   
    }

    inline void solve () {
        dfs (1, 0, 0);
        std::cout << ans << "\n";
    }
}

int main () {

    freopen ("resource.in", "r", stdin);
    freopen ("resource.out", "w", stdout);

    std::cin >> n;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
    for (int i = 1; i <= n; i++) { std::cin >> b[i]; }

    Task1::solve ();

    return 0;
}
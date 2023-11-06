#include <iostream>
#include <algorithm>

using i64 = long long;

const int maxn = 300005;

int n;
i64 m;
i64 pos[maxn];

int main () {

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) { std::cin >> pos[i]; }
    std::sort (pos + 1, pos + n + 1);

    int ans = 0;

    int l = 1;
    for (int r = 1; r <= n; r++) {
        while (pos[r] >= pos[l] + m) { l++; }
        ans = std::max (ans, r - l + 1);
    }    

    std::cout << ans << "\n";

    return 0;
}
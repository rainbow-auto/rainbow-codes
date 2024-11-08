#include <iostream>

const int maxn = 100005;

int T;

int n, x, y;

int ans[maxn];

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n >> x >> y;
        for (int i = 1; i <= n; i++) { ans[i] = 0; }   

        for (int i = y; i <= x; i++) { ans[i] = 1; }
        for (int i = y - 1; i >= 1; i--) { ans[i] = ans[i + 1] * (-1); }
        for (int i = x + 1; i <= n; i++) { ans[i] = ans[i - 1] * (-1); }

        for (int i = 1; i <= n; i++) { std::cout << ans[i] << " "; }
        std::cout << "\n";
    }   

    return 0;
}
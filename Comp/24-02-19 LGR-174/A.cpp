#include <iostream>
#include <algorithm>

const int maxn = 1000005;

int n;
int a[maxn];

int main () {

    std::cin >> n;
    
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    std::sort (a + 1, a + n + 1);

    int ans = -1e9;
    for (int i = 1; i <= n - 1; i++) { ans = std::max (ans, a[i] - a[i + 1]); }
    std::cout << ans << "\n";

    return 0;
}

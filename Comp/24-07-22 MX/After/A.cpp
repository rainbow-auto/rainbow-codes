#include <iostream>
#include <algorithm>

#pragma GCC Optimize(3)

int n, m;

int ans;

void dfs (int x, int y, int pre_x, int pre_y) {
    if (x > std::max (n, m) or y > std::max (n, m)) { return; }

    if (x <= n and y <= m) { ans ++; }

    if (x != pre_y and y != pre_x) { dfs (y, x, x, y); } // 无需再次翻转
    dfs (x + y * 2, y, x, y);
}

int main () {
    
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);

    std::cin >> n >> m;

    dfs (1, 2, 0, 0);

    std::cout << ans << "\n";

    return 0;
}
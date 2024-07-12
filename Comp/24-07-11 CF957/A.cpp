#include <iostream>

using i64 = long long;

int a[5];

int ans;

void dfs (int now) {
    if (now > 5) { ans = std::max (ans, a[1] * a[2] * a[3]); return; }
    
    for (int i = 1; i <= 3; i++) {
        a[i] ++;
        dfs (now + 1);
        a[i] --;
    }
}

int main () {

    int T; std::cin >> T;

    while (T--) {
        for (int i = 1; i <= 3; i++) { std::cin >> a[i]; }

        ans = 0;
        dfs (1);
        
        std::cout << ans << "\n";
    }

    return 0;
}
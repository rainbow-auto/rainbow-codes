#include <iostream>

using i64 = long long;

const int maxn = 105;

int T;

int n;
int a[maxn];

int main () {
    
    std::cin >> T;

    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

        i64 last = a[1];
        for (int i = 2; i <= n; i++) {
            last = (i64 (last + a[i]) / a[i]) * a[i];
        }

        std::cout << last << "\n";
    }

    return 0;
}
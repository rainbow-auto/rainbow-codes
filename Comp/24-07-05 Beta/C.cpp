#include <iostream>

using i64 = long long;

const int maxn = 45;

int n;
i64 f[maxn];

int main () {

    std::cin >> n;

    f[1] = 0; f[2] = 1; f[3] = 1;

    for (int i = 1; i <= n; i++) {
        if (i <= 3) { std::cout << f[i] << " "; continue; }

        f[i] = f[i - 1] + f[i - 2];

        std::cout << f[i];
        if (i % 10 == 0) { std::cout << "\n"; }
        else { std::cout << " "; }
    }

    return 0;
}
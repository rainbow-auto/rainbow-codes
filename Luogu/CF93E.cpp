#include <iostream>
#include <algorithm>

#pragma GCC Optimize(3)

using i64 = long long;

const int maxn = 200005;
const int lim = 200000;
const int maxk = 105;

i64 n, k;

i64 a[maxk];

i64 mem[maxn][maxk];

i64 dp (i64 i, i64 j) {
    if (i == 0) { return 0; }
    if (j == 1) { return i / a[j]; }

    if (i <= lim and mem[i][j]) { return mem[i][j]; }

    i64 res = dp (i, j - 1) + (i / a[j]) - dp (i / a[j], j - 1);
    if (i <= lim) { mem[i][j] = res; }
    return res;
}

int main () {

    std::cin >> n >> k;

    for (int i = 1; i <= k; i++) { std::cin >> a[i]; }
    std::sort (a + 1, a + k + 1);
    
    std::cout << n - dp (n, k) << "\n";

    return 0;
}
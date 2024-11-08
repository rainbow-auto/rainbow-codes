#include <iostream>
#include <string>

using i64 = long long;

int n;

int m;
int a[maxn];

const int mod = 1e9 + 9;
const int base = 233;

int hs[maxn][maxn];

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::string s; std::cin >> s;

        int pos = 0;
        for (auto c : s) { pos ++; hs[i][pos] = hs[i][pos - 1] * ; }
    }

    return 0;
}
#include <iostream>
#include <algorithm>

#pragma GCC Optimize("Ofast")

using i64 = long long;

const int maxn = 10;
const int maxm = 100005;

int n, m;

int a[maxn];
int l[maxn], v[maxn];

int ord[maxn];

int pos[maxn];

int main () {

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
    for (int i = 1; i <= m; i++) { std::cin >> l[i] >> v[i]; }

    for (int i = 1; i <= n; i++) { ord[i] = i; }

    do {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int nxt = 0;
                int sum = 0;
                for (int k = i - 1; k >= 1; k--) {
                    
                }
            }
        }
    } while (std::next_permutation (ord + 1, ord + n + 1));

    return 0;
}
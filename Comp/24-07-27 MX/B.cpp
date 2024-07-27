#include <iostream>
#include <string>

const int maxn = 1000005;

using i64 = long long;

int n;

int a[maxn];
int b[maxn];

i64 sum[maxn];
i64 sumsum[maxn];

int main () {

    freopen ("wood.in", "r", stdin);
    freopen ("wood.out", "w", stdout);

    std::cin >> n;
    
    std::string s; std::cin >> s;
    for (int i = 1; i <= n; i++) { b[i] = (s[i - 1] == '1'); }
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    for (int i = 1; i <= n; i++) { sum[i] = sum[i - 1] + a[i]; }
    for (int i = 1; i <= n; i++) { sumsum[i] = sumsum[i - 1] + sum[i]; }

    i64 ans = 0;

    i64 len = 0;
    b[0] = 114514;
    for (i64 r = 1; r <= n; r++) {
        if (b[r] != b[r - 1]) { 
            len = 1;
        } else {
            len ++;
        }  

        i64 delta = sumsum[len] * 2ll + (sumsum[r] - sumsum[len]) + (r - len) * sum[len];
        ans += delta;
    }

    std::cout << ans << "\n";

    return 0;
}
#include <iostream>
#include <string>

using i64 = long long;

const int maxn = 1000005;

int n;
i64 a[maxn], b[maxn];

inline i64 query (int l, int r) {
    i64 res = 0;

    int pos = r;

    int apos = 1;
    for (int i = r; i >= l; i--) {
        if (i == r or b[i] == b[i + 1]) { 
            res += 2ll * a[apos]; apos ++;
            pos = i;
        } else {
            break;
        }
    }

    pos --;
    for (int i = pos; i >= l; i--) {
        res += a[apos]; apos ++;
    }

    return res;
}

int main () {

    std::cin >> n;

    std::string s; std::cin >> s;

    for (int i = 1; i <= n; i++) { b[i] = (s[i - 1] == '1'); }
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    i64 ans = 0;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            ans += query (l, r);
        }
    }

    std::cout << ans << "\n";

    return 0;
}
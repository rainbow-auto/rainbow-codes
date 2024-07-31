#include <iostream>

using i64 = long long;

int n;

const int maxn = 100005;

i64 a[maxn];
i64 cnt[20][10];
i64 num[maxn][20];

inline i64 f (i64 x) {
    i64 res = 0; while (x) { res += x % 10ll; x /= 10ll; }
    return res;
}

i64 pw[20];
inline void getpw () {
    pw[0] = 1ll;
    for (int i = 1; i <= 16; i++) { pw[i] = pw[i - 1] * 10ll; }
}

inline void upd (i64 x, i64 id) {
    for (int i = 1; i <= 16; i++) {
        i64 curr = (x / pw[i - 1]) % 10ll;
        cnt[i][curr] ++;
        num[id][i] = curr;
    }   
}

int main () {

    getpw ();

    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; upd (a[i], i); }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 16; j++) {
            std::cerr << num[i][j];
        }
        std::cerr << "\n";
    }

    for (int i = 1; i <= 16; i++) {
        std::cerr << i << ": ";
        for (int j = 0; j < 10; j++) { std::cerr << cnt[i][j] << " "; }
        std::cerr << "\n";
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        i64 delta = 0;
        for (int j = 1; j <= 16; j++) {
            for (int k = 0; k < 10; k++) {
                ans += cnt[j][k] * f (num[i][j] + k);
                delta += cnt[j][k] * f (num[i][j] + k);
            }
        }

        std::cerr << delta << "\n";
    }

    std::cout << ans << "\n";
    
    return 0;
}
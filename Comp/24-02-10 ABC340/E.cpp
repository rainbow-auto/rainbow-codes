// unsolved

#include <iostream>

const int maxn = 200005;

using i64 = long long;

int n, m;

i64 a[maxn], b[maxn];

i64 d[maxn];

inline void add (int l, int r, int val) {
    if (l > r) { return; }
    std::cerr << "add " << l << " " << r << " " << val << "\n";
    d[l] += val;
    d[r + 1] -= val; 
}

int main () {

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; } 
    for (int i = 1; i <= m; i++) { std::cin >> b[i]; b[i] ++; }

    for (int i = 1; i <= m; i++) {
        if (b[i] + a[i] <= n) { add (b[i] + 1, b[i] + a[i], 1); }
        else {
            add (b[i] + 1, n, 1); a[i] -= n - (b[i] + 1) + 1;
            i64 x = a[i] / n;
            i64 y = a[i] % n;

            add (1, n, x);
            add (1, y, 1);
        }
    }

    i64 now = 0;

    for (int i = 1; i <= n; i++) {
        now += d[i];
        std::cout << now << " ";
    }

    return 0;
}
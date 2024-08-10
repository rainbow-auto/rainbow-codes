#include <iostream>

const int maxn = 300005;

int T, m, k;
int n;

int a[maxn];
int sum[maxn];

int a_new[maxn];

int main () {

    std::cin >> T >> k >> m;

    int n = (1 << k);

    for (int i = 0; i < n; i++) { std::cin >> a[i]; }

    sum[0] = 0;
    for (int i = 1; i < n; i++) { sum[i] = sum[i - 1] + bool (a[i] != a[i - 1]); }

    int last = 0;
    while (m--) {
        int op; std::cin >> op;

        if (op == 1) {
            int x; std::cin >> x;
            x = (x xor (last * T));

            for (int i = 0; i < n; i++) { a_new[i] = a[i xor x]; }
            for (int i = 0; i < n; i++) { a[i] = a_new[i]; }
            
            sum[0] = 0;
            for (int i = 1; i < n; i++) { sum[i] = sum[i - 1] + bool (a[i] != a[i - 1]); }
            
        } else {
            int l; std::cin >> l;
            int r; std::cin >> r;
            l = (l xor (last * T));
            r = (r xor (last * T));
            if (l > r) { std::swap (l, r); }

            if (l == 0) { last = sum[r] + 1; }
            else { last = sum[r] - sum[l] + 1; }
            std::cout << last << "\n";
        }
    }

    return 0;
}
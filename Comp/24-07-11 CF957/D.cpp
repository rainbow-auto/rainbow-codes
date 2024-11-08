#include <iostream>

using i64 = long long;

int n, m, k;
int a[maxn];

inline bool check () {
    for (int i = 0; i <= n + 1; i++) {
        if (not a[i]) { continue; }
        if (a[i] == 2) { return false; }

        int pos = i + 1;
        int len = 0;

        bool c = false;
        int close_c = n + 1;

        int close_c_w_cnt = 0;

        while (pos <= n + 1) {
            if (not a[pos]) { break; }

            len ++;

            if (a[pos] == 2) { close_c = std::min (close_c, len); c = true; }
            if (a[pos] == 1) { if (len <= close_c) { close_c_w_cnt ++; } }

            if (len > m - 1) { break; }
        }

        if (len <= m - 1) {
            i = pos;
            continue; 
        } else {
            if (close_c <= m) {
                i = i + close_c;
            } else if (close_c_w_cnt <= ) {

            }
        }

    }

}

int main () {

    int T; std::cin >> T;

    while (T--) {
        std::cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            char x; std::cin >> x;
            if (x == 'C') { a[i] = 1; }
            if (x == 'W') { a[i] = 2; }
        }

        if (check ()) { std::cout <<  }
    }


    return 0;
}
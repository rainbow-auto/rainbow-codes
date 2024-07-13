#include <iostream>
#include <algorithm>

const int maxn = 400005;

int n;

struct Tree {
    struct Node {
        int sum;
        int ls, rs;
    } tr[maxn];

    inline void pushUp (int now) { tr[now].sum = tr[tr[now].ls].sum + tr[tr[now].rs].sum; }

    void query (int now, int l, int r, int L, int R) {
        
    }

} tr;

i64 line[10], v[10];
i64 a[maxn];

inline i64 get_nxt (i64 now) {
    i64 nxt = std::upper_bound (a + 1, a + n + 1, now) - a - 1;
    if (nxt == n + 1) { return -1; }

    return nxt - now;
}

i64 now[10];
inline void solve () {
    for (int i = 1; i <= 4; i++) { now[i] = -2e9 + line[i]; }

    while (true) {

        i64 min_len = 2e9;
        for (int i = 1; i <= 4; i++) {
            if (get_nxt (now[i]) == -1) { continue; }
            min_len = std::min (min_len, get_nxt (now[i]));
        }

        if (min_len == 2e9) { break; } 

        for (int i = 1; i <= 5; i++) {
            
        }
    }   
}

int main () {

    int T; std::cin >> T;

    while (T--) {
        std::cin >> n;

        for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
        std::sort (a + 1, a + n + 1);

        for (int i = 1; i <= 4; i++) { std::cin >> line[i]; }
        for (int i = 1; i <= 5; i++) { std::cin >> v[i]; }   

        solve ();
    }

    return 0;
}
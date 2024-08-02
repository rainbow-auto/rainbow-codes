#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

const int maxn = 1000005;
const int maxnn = 1005;

using i64 = long long;

int n, q;
i64 a[maxn];
int len, belong[maxn];
int L[maxnn], R[maxnn], tot;

std::vector <i64> num[maxnn];

i64 tag[maxnn];

inline void init () {
    memset (L, 0x3f, sizeof (L));

    len = sqrt (n);
    for (int i = 1; i <= n; i++) { 
        belong[i] = (i / len) + 1;
        L[belong[i]] = std::min (L[belong[i]], i);
        R[belong[i]] = std::max (R[belong[i]], i);
        tot = std::max (tot, belong[i]);

        num[belong[i]].push_back (a[i]);
    }

    for (int i = 1; i <= tot; i++) { std::sort (num[i].begin (), num[i].end ()); }
}

inline void pushDown (int now) {
    for (int i = L[now]; i <= R[now]; i++) { a[i] += tag[now]; }
    tag[now] = 0;
}

inline void rebuild (int now) {
    num[now].clear ();
    for (int i = L[now]; i <= R[now]; i++) { num[now].push_back (a[i]); }
    std::sort (num[now].begin (), num[now].end ());
}

inline void modify (int l, int r, i64 c) {
    if (belong[l] == belong[r]) {
        pushDown (belong[l]);
        for (int i = l; i <= r; i++) { a[i] += c; }
        rebuild (belong[l]);
        return;
    }
    
    for (int i = belong[l] + 1; i <= belong[r] - 1; i++) { tag[i] += c; }

    pushDown (belong[l]);
    for (int i = l; i <= R[belong[l]]; i++) { a[i] += c; }   
    rebuild (belong[l]);

    pushDown (belong[r]);
    for (int i = L[belong[r]]; i <= r; i++) { a[i] += c; }
    rebuild (belong[r]);
}

inline i64 query (int l, int r, i64 c) {
    i64 res = 0;
    
    if (belong[l] == belong[r]) {
        for (int i = l; i <= r; i++) { res += (a[i] + tag[belong[i]] >= c); }
        return res;
    }
    
    for (int i = belong[l] + 1; i <= belong[r] - 1; i++) { 
        res += num[i].size () - (std::lower_bound (num[i].begin (), num[i].end (), c - tag[i]) - num[i].begin ());
    }

    for (int i = l; i <= R[belong[l]]; i++) { res += (a[i] + tag[belong[l]] >= c); }
    for (int i = L[belong[r]]; i <= r; i++) { res += (a[i] + tag[belong[r]] >= c); }

    return res;
}   

int main () {

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    init ();

    while (q--) {
        char op; std::cin >> op;
        if (op == 'M') {
            int l, r, c; std::cin >> l >> r >> c;
            modify (l, r, c);
        } else if (op == 'A') {
            int l, r, c; std::cin >> l >> r >> c;
            std::cout << query (l, r, c) << "\n";
        }
    }

    return 0;
}
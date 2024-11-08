#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <chrono>
#include <cstring>

#pragma GCC Optimize("Ofast")

const int maxn = 1000005;

int n, m;
int a[maxn];

inline int read () {
    int res = 0;
    char ch = getchar ();

    while (not isdigit (ch)) { ch = getchar (); }
    while (isdigit (ch)) { res = res * 10 + (ch - '0'); ch = getchar (); }
    
    return res;
}

namespace Task1 {
    struct Node {
        int ls, rs;
        int cnt; // 仅在叶子节点处有效
        int sum;
    } tr[maxn << 5];

    int tot, root;

    void modify (int& now, int l, int r, int pos, int val) {
        if (not now) { now = ++tot; }

        if (l == r) { 
            tr[now].cnt += val; 
            tr[now].sum = (tr[now].cnt > 0);
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); }
        if (pos > mid) { modify (tr[now].rs, mid + 1, r, pos, val); }
        
        tr[now].sum = tr[tr[now].ls].sum + tr[tr[now].rs].sum;
    }

    int query (int now, int l, int r) {
        if (not now) { return 0; }
        if (l == r) { return (tr[now].sum > 0); }   

        int mid = (l + r) >> 1;
        if (tr[tr[now].ls].sum == (mid - l + 1)) { return (mid - l + 1) + query (tr[now].rs, mid + 1, r); }
        else { return query (tr[now].ls, l, mid); }
    } 

    int a_new[maxn];

    inline void calc () {
        for (int i = 1; i <= n; i++) { modify (root, 0, 1e9, a[i], 1); }
    
        for (int i = 1; i <= n; i++) {
            modify (root, 0, 1e9, a[i], -1);
            a_new[i] = query (root, 0, 1e9);
            modify (root, 0, 1e9, a[i], 1);
        }

        for (int i = 1; i <= n; i++) { modify (root, 0, 1e9, a[i], -1); }
        for (int i = 1; i <= n; i++) { a[i] = a_new[i]; }
    }

    inline void solve () {

        for (int t = 1; t <= m; t++) { calc (); }

        for (int i = 1; i <= n; i++) { std::cout << a[i] << " "; } std::cout << "\n";
    }
}

namespace Solution {  
    
    int cnt[maxn];

    inline void calc () {
        // std::unordered_map<int, int> cnt;

        memset (cnt, 0, sizeof (cnt));

        for (int i = 1; i <= n; i++) { 
            if (a[i] <= n) { cnt[a[i]] ++; }
        }

        int mex = 0;
        while (cnt[mex]) { mex ++; } // O (n)

        for (int i = 1; i <= n; i++) {
            if (a[i] > mex) { a[i] = mex; }
            else {
                if (cnt[a[i]] > 1) { a[i] = mex; }
                // 否则 a[i] 不变
            }
        }
    }

    inline void solve () {
        // using namespace Task1;
        
        if (m == 1) { 
            calc ();
        } else if (m == 2) {
            calc (); calc ();
        } else {
            if (m & 1) { calc (); calc (); calc (); }
            else { calc (); calc (); }
        }

    }
}

int main () {

    // freopen ("rabbit.in", "r", stdin);
    // freopen ("rabbit.out", "w", stdout);

    // auto st = std::chrono::steady_clock::now ();
    
    int T; std::cin >> T;

    while (T--) {
        n = read ();
        m = read ();

        for (int i = 1; i <= n; i++) { a[i] = read (); }

        Solution::solve ();

        for (int i = 1; i <= n; i++) { printf ("%d ", a[i]); } printf ("\n");
    }

    // auto ed = std::chrono::steady_clock::now ();

    // double cost = (double) (std::chrono::duration_cast<std::chrono::microseconds> (ed - st) .count ()) / 1000.0;
    // std::cerr << cost << "\n";

    return 0;
}
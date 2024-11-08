#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>

using i64 = long long;

const int maxn = 200005;

i64 read () {
    i64 res = 0, flag = 1;

    char ch = getchar ();
    while (not isdigit (ch)) { if (ch == '-') { flag = -1; } ch = getchar (); }
    while (isdigit (ch)) { res *= 10; res += ch - '0'; ch = getchar (); }
    
    return res * flag;
}

int n;
std::vector <i64> lines, v;

i64 a[maxn];

struct Tree {
    struct Node {
        i64 sum;
        int ls, rs;
    } tr[maxn << 9];

    int rt, tot;

    inline void clear () { 
        rt = ++tot;
    }

    inline void pushUp (int now) { tr[now].sum = tr[tr[now].ls].sum + tr[tr[now].rs].sum; }

    void modify (int& now, i64 l, i64 r, i64 pos, i64 val) {
        if (not now) { now = ++tot; }

        tr[now].sum += val;
        if (l == r) { return; }

        i64 mid = (l + r) >> 1;
        if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); }
        if (pos > mid) { modify (tr[now].rs, mid + 1, r, pos, val); }
    }

    i64 query (int now, i64 l, i64 r, i64 L, i64 R) {
        if (not now) { return 0; }
        if (L <= l and r <= R) { return tr[now].sum; }

        i64 mid = (l + r) >> 1;
        i64 res = 0;
        if (L <= mid) { res += query (tr[now].ls, l, mid, L, R); }
        if (R > mid) { res += query (tr[now].rs, mid + 1, r, L, R); }

        return res;
    }
} tr;

inline i64 get_val (i64 h) {
    i64 res = 0;

    res += tr.query (tr.rt, -1e9, 1e9, -1e9, lines[0] + h - 1) * v[0];
    res += tr.query (tr.rt, -1e9, 1e9, lines[0] + h, lines[1] + h - 1) * v[1];
    res += tr.query (tr.rt, -1e9, 1e9, lines[1] + h, lines[2] + h - 1) * v[2];
    res += tr.query (tr.rt, -1e9, 1e9, lines[2] + h, lines[3] + h) * v[3];
    res += tr.query (tr.rt, -1e9, 1e9, lines[3] + h + 1, 1e9) * v[4];

    return res;
}

inline void solve () {
    // std::set <i64> hs;
    
    i64 ans = -2e15;
    
    for (int l = 0; l < 4; l++) {
        i64 now = lines[l];

        for (int i = 1; i <= n; i++) {
            int s = (l == 3) ? -1 : 0;
            int t = (l == 3) ? 0  : 1;

            for (int delta = s; delta <= t; delta ++) {
                i64 nxt = a[i] + delta;

                i64 h = nxt - now;

                ans = std::max (ans, get_val (h));
                
                // hs.insert (h);
            }
        }   
    }

    // for (auto h : hs) { ans = std::max (ans, get_val (h)); }

    std::cout << ans << "\n"; 
}

int main () {

    int T = read ();

    while (T--) {
        tr.clear ();

        n = read ();

        for (int i = 1; i <= n; i++) { a[i] = read (); tr.modify (tr.rt, -1e9, 1e9, a[i], 1); }        

        for (int i = 1; i <= 4; i++) { 
            i64 x = read ();
            if (lines.size () < 4) { lines.push_back (x); }
            else { lines[i - 1] = x; }
        }

        for (int i = 1; i <= 5; i++) { 
            i64 x = read (); 
            if (v.size () < 4) { v.push_back (x); }
            else { v[i - 1] = x; }
        }
        
        solve ();   
    }

    return 0;
}
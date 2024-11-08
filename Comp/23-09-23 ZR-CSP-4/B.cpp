#include <iostream>

using namespace std;

int n;

namespace Task1 {
    
    const int maxn = 50005;

    int a[maxn];

    struct Node{
        int mn, mx;
        int tag;
    } tr[maxn << 4];

    inline void pushUp (int now) {
        tr[now].mn = min (tr[now << 1].mn, tr[now << 1 | 1].mn);
        tr[now].mx = max (tr[now << 1].mx, tr[now << 1 | 1].mx);
    }

    inline void pushDown (int now) {
        tr[now << 1].tag += tr[now].tag;
        tr[now << 1].mx += tr[now].tag;
        tr[now << 1].mn += tr[now].tag;
        
        tr[now << 1 | 1].tag += tr[now].tag;
        tr[now << 1 | 1].mx += tr[now].tag;
        tr[now << 1 | 1].mn += tr[now].tag;
        
        tr[now].tag = 0;
    }

    void build (int now, int l, int r) {
        if (l == r) {
            tr[now].mn = tr[now].mx = a[l];
            return;
        }

        int mid = (l + r) >> 1;

        build (now << 1, l, mid);
        build (now << 1 | 1, mid + 1, r);
        pushUp (now);
    }

    void change (int now, int l, int r, int L, int R, int val) {
        if (L <= l and r <= R) {
            tr[now].mx += val;
            tr[now].mn += val;
            tr[now].tag += val;
 
            return;
        }

        pushDown (now);

        int mid = (l + r) >> 1;

        if (L <= mid) { change (now << 1, l, mid, L, R); }
        if (R > mid) { change (now << 1 | 1, mid + 1, r, L, R); }

        pushUp (now);
    }

    int query_min (int now, int l, int r, int L, int R) {
        if (L > R) { return 0x3f3f3f3f; }
        
        if (L <= l and r <= R) {
            return tr[now].mn;
        }

        pushDown (now);
        
        int mid = (l + r) >> 1;

        int res = 0x3f3f3f3f;
        if (L <= mid) { res = min (res, query_min (now << 1, l, mid, L, R)); }
        if (R > mid) { res = min (res, query_min (now << 1 | 1, mid + 1, r, L, R)); }

        return res;
    }

    int query_max (int now, int l, int r, int L, int R) {
        if (L > R) { return 0; }

        if (L <= l and r <= R) {
            return tr[now].mx;
        }

        pushDown (now);

        int mid = (l + r) >> 1;
        
        int res = 0;
        if (L <= mid) { res = max (res, query_max (now << 1, l, mid, L, R)); }
        if (R > mid) { res = max (res, query_max (now << 1 | 1, mid + 1, r, L, R)); }

        return res;
    }

    inline void solve () {
        
    }
}

int main () {

    int T;
    cin >> T;

    while (T--) {
        cin >> n;

        if (n <= 5000) {
            Task1::solve ();
        }
    }

    return 0;
}
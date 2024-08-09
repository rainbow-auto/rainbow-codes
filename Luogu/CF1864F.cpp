#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxn = 1000010;

int n, q;
int a[maxn];

struct SegTree {
    struct Node {
        int mx;
    } tr[maxn << 3];
       
    void modify (int now, int l, int r, int pos, int val) {
        if (l == r) { tr[now].mx = val; return; }

        int mid = (l + r) >> 1;
        if (pos <= mid) { modify (now << 1, l, mid, pos, val); }
        else { modify (now << 1 | 1, mid + 1, r, pos, val); }

        tr[now].mx = std::max (tr[now << 1].mx, tr[now << 1 | 1].mx);
    }

    int query (int now, int l, int r, int L, int R) {
        if (L <= l and r <= R) { return tr[now].mx; }

        int mid = (l + r) >> 1;
        int res = 0;
        if (L <= mid) { res = std::max (res, query (now << 1, l, mid, L, R)); }
        if (R > mid) { res = std::max (res, query (now << 1 | 1, mid + 1, r, L, R)); }

        return res;
    }

    inline int query (int L, int R) {
        if (L <= R) { return query (1, 1, n, L, R); }
        else { return 0; }
    }
} tr;

struct FenwickTree {
    int tr[maxn];

    inline int lowbit (int x) { return x & (-x); }

    inline void modify (int pos, int val) { 
        if (pos == 0) { return; }
        for (int i = pos; i <= n + 5; i += lowbit (i)) { tr[i] += val; } 
    }

    inline int query (int pos) { int res = 0; for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; } return res; }
    inline int query (int l, int r) { return (l <= r) ? (query (r) - query (l - 1)) : 0; }

} fwktr;

std::vector <int> pos[maxn];
std::vector <int> pre[maxn];

struct PointQuery {
    int val;
    int flag;
    int id;
}; 

std::vector <PointQuery> pq[maxn]; 
int ans[maxn];

int cnt[maxn];

int main () {
	fastread

    std::cin >> n >> q;

    for (int i = 1; i <= n; i++) { 
        std::cin >> a[i]; 
        pos[a[i]].push_back (i); 
    }

    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1];
        if (not pos[i].empty ()) { cnt[i] ++; }
    }

    for (int val = 1; val <= n; val ++) {
        int last = -1;

        for (auto curr : pos[val]) {
            if (last != -1) { 
                int p = tr.query (last + 1, curr - 1);
                if (p) { pre[val].push_back (p); } 
            }
                
            last = curr;
        }
        
        for (auto curr : pos[val]) {
            tr.modify (1, 1, n, curr, val);
        }
    }

    for (int i = 1; i <= q; i++) {
        int l, r; std::cin >> l >> r;
        pq[l - 1].push_back (PointQuery { l, -1, i });
        pq[r].push_back (PointQuery { l, 1, i });

        ans[i] = cnt[r] - cnt[l - 1];
    }

    for (int val = 1; val <= n; val ++) {
        for (auto curr : pre[val]) { fwktr.modify (curr, 1); }

        for (auto curr : pq[val]) { ans[curr.id] += curr.flag * fwktr.query (curr.val, n); }
    }

    for (int i = 1; i <= q; i++) { std::cout << ans[i] << "\n"; }

	return 0;
}

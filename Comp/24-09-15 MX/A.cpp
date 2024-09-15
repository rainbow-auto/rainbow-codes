#include <bits/stdc++.h>
#pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 1000005;

int n;
i64 k;
i64 a[maxn];

// struct Tree {
//     struct Node {
//         i64 mn;
//         Node () { mn = 1e18; }
//     } tr[maxn << 2];

//     void clear (int now, int l, int r) {
//         tr[now].mn = 1e18;
//         if (l == r) { return; }
//         int mid = (l + r) >> 1;
//         clear (now << 1, l, mid);
//         clear (now << 1 | 1, mid + 1, r);
//     }

//     inline void pushUp (int now) { tr[now].mn = std::min (tr[now << 1].mn, tr[now << 1 | 1].mn); }

//     void modify (int now, int l, int r, int pos, i64 val) {
//         if (l == r) { tr[now].mn = val; return; }
//         int mid = (l + r) >> 1;
//         if (pos <= mid) { modify (now << 1, l, mid, pos, val); }
//         else { modify (now << 1 | 1, mid + 1, r, pos, val); }
//         pushUp (now);
//     }

//     i64 query (int now, int l, int r, int L, int R) {
//         if (L <= l and r <= R) { return tr[now].mn; }
//         i64 res = 1e18;
//         int mid = (l + r) >> 1;
//         if (L <= mid) { res = std::min (res, query (now << 1, l, mid, L, R)); }
//         if (R > mid) { res = std::min (res, query (now << 1 | 1, mid + 1, r, L, R)); }
//         return res;
//     } 

// } tr;

// inline i64 calc (int m) {
//     tr.clear (1, 1, n);
//     rep (i, 1, m) { tr.modify (1, 1, n, i, a[i]); }

//     rep (i, m + 1, n) {
//         i64 curr = tr.query (1, 1, n, i - m, i - 1) + a[i];
//         tr.modify (1, 1, n, i, curr);
//     }

//     return tr.query (1, 1, n, n - m + 1, n);   
// }

i64 f[maxn];
inline i64 calc (int m) {
    std::deque <i64> q;
    rep (i, 1, n) {
        while (not q.empty () and q.front () < i - m) { q.pop_front (); }
        
        if (i >= m + 1) {
            f[i] = f[q.front ()] + a[i];
        } else {
            f[i] = a[i];
        }
        
        while (not q.empty () and f[q.back ()] > f[i]) { q.pop_back (); }
        q.push_back (i);
    }

    i64 ans = 1e18;
    rep (i, n - m + 1, n) { ans = std::min (ans, f[i]); }
    
    return ans;
}


namespace Task1 {
    inline void solve () {
        std::pair <i64, i64> ans = { 1e18, 1e18 }; 

        rep (m, 1, n) {
            i64 curr = calc (m);
            ans = std::min (ans, std::pair <i64, i64> { std::abs (curr - k), curr });
        }

        std::cout << ans.second << "\n";
    }
}

namespace Solution {
    inline std::pair <i64, i64> binary1 () {
        i64 l = 1, r = n;
        std::pair <i64, i64> ans = { 1e18, 1e18 };
        
        while (l <= r) {
            int mid = (l + r) >> 1;
            i64 curr = calc (mid);
            if (curr <= k) { r = mid - 1; ans = std::min (ans, std::pair <i64, i64> { k - curr, curr } ); }
            else { l = mid + 1; }
        }
        return ans;
    }  

    inline std::pair <i64, i64> binary2 () {
        i64 l = 1, r = n;
        std::pair <i64, i64> ans = { 1e18, 1e18 };
        
        while (l <= r) {
            int mid = (l + r) >> 1;
            i64 curr = calc (mid);
            if (curr >= k) { l = mid + 1; ans = std::min (ans, std::pair <i64, i64> { curr - k, curr } ); }
            else { r = mid - 1; }
        }

        return ans;
    }
    
    inline void solve () {
        std::pair <i64, i64> ans = { 1e18, 1e18 };
        ans = std::min (ans, binary1 ());
        ans = std::min (ans, binary2 ());
        std::cout << ans.second << "\n";
    }
}

bool MemED;
int main () {
	fastread
	// lookMem	
	TimeST = clock ();

    freopen ("wind.in", "r", stdin);
    freopen ("wind.out", "w", stdout);

    std::cin >> n >> k;
    rep (i, 1, n) { std::cin >> a[i]; }

    Solution::solve ();
    // Task1::solve ();

    lookTime

	return 0;
}

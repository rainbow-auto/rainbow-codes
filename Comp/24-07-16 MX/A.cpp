#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using i64 = long long;

int n, k;

namespace Task1 {
    struct Range {
        int l, r;

        friend bool operator < (Range a, Range b) {
            if (a.r != b.r) { return a.r < b.r; }
            else { return a.l < b.l; }
        }
    };

    std::vector <Range> rs;
    
    inline void init () {
        for (int l = 1; l <= n; l ++) {
            for (int r = l; r <= n; r ++) {
                rs.push_back (Range { l, r });
            }
        }
    }

    inline bool chk (Range x, Range y) {
        if (x.l <= y.l and y.l <= x.r) { return true; }
        if (x.l <= y.r and y.r <= x.l) { return true; }
        if (y.l <= x.l and x.l <= y.r) { return true; }
        if (y.l <= x.r and x.r <= y.r) { return true; }
        return false;
    }

    inline bool get (int S, int pos) { return S & (1 << pos); }
    
    std::vector <Range> curr;

    int t[10];
    inline int calc () {
        int res = 0;
        
        for (int S = 0; S <= ((1 << (curr.size ())) - 1); S++) {
            memset (t, 0, sizeof (t));
            int cnt = 0;
            for (int i = 0; i < curr.size (); i++) {
                if (not get (S, i)) { continue; }
                cnt ++;
                for (int j = curr[i].l; j <= curr[i].r; j++) { t[j] ++; }   
            }

            bool flag = false;
            for (int i = 1; i <= n; i++) { if (t[i] > 1) { flag = true; } }
            
            if (flag) { continue; }

            res = std::max (res, cnt);   
        }

        return res;
    }    

    inline void solve () {
        init ();

        int res = 0;
        for (int S = 0; S <= ((1 << (rs.size ())) - 1); S++) {
            curr.clear ();
            for (int i = 0; i < rs.size (); i++) {
                if (get (S, i)) { curr.push_back (rs[i]); }
            }

            if (calc () == k) { res ++; }
        }

        std::cout << res;
    }
}

namespace Task1_faster {
    int ans[6][6];

    inline void init () {
        ans[1][1] = 1;
        ans[2][1] = 5;
        ans[2][2] = 2;
        ans[3][1] = 23;
        ans[3][2] = 32;
        ans[3][3] = 8;
        ans[4][1] = 127;
        ans[4][2] = 480;
        ans[4][3] = 352;
        ans[4][4] = 64;
        ans[5][1] = 927;
        ans[5][2] = 8928;
        ans[5][3] = 14720;
        ans[5][4] = 7168;
        ans[5][5] = 1024;
    }

    inline void solve () {
        init ();
        std::cout << ans[n][k] << "\n";
    }
}

int main () {

    freopen ("seg.in", "r", stdin);
    freopen ("seg.out", "w", stdout);

    std::cin >> n >> k;

    Task1_faster::solve ();
    // Task1::solve ();

    return 0;
}
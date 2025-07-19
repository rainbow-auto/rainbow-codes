#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 505;

int n;

int a[maxn][maxn];

namespace Solution {
    bool chk(int k) {
        bool flg1n = 0;
        rep (i, 1, n) rep (j, 1, n) {
            if (std::abs(a[i][j] - a[1][n]) > k) {
                // db << "(" << i << ", " << j << ")\n";
                flg1n = true; 
            }
        }
        
        // dbg(a[1][n]);
        // dbg(flg1n);
        
        bool flgn1 = 0;
        rep (i, 1, n) rep (j, 1, n) {
            if (std::abs(a[i][j] - a[n][1]) > k) {
                flgn1 = true; 
            }
        }

        // dbg(a[n][1]);
        // dbg(flgn1);
        
        if (flg1n and flgn1) return false;
        return true;
    }

    inline void solve() {
        int mx = 0, mn = 0x3f3f3f3f;
        rep (i, 1, n) rep (j, 1, n) mx = std::max(mx, a[i][j]);
        rep (i, 1, n) rep (j, 1, n) mn = std::min(mn, a[i][j]);
        
        int l = 0, r = mx - mn;
        int ans = -1;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (chk(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        std::cout << ans << "\n";
    }
}

namespace Task0 {
    int ans = 0x3f3f3f3f;

    std::vector<int> stp;
    void dfs(int now, int lst, int mxl, int mxr, int mnl, int mnr, bool flg) {
        if (now > n) {
            if (lst == 0) return;
            if (flg) return;

            int ansnow = std::max(mxl - mnr, mxr - mnl);
            // for (auto x : stp) db << x << " "; dbendl;
            
            // dbg(mxl);
            // dbg(mnl);
            // dbg(mxr);
            // dbg(mnr);

            // db << ansnow << "\n";
            ans = std::min(ans, ansnow);
            return;
        }

        rep (k, 1, lst) {
            mxl = std::max(mxl, a[now][k]);
            mnl = std::min(mnl, a[now][k]);
        }
        rep (cur, lst, n) {
            if (cur) mxl = std::max(mxl, a[now][cur]);
            if (cur) mnl = std::min(mnl, a[now][cur]);

            int n_mnr = mnr;
            int n_mxr = mxr;
            rep (x, cur + 1, n) {
                n_mnr = std::min(n_mnr, a[now][x]);
                n_mxr = std::max(n_mxr, a[now][x]);
            }

            stp.push_back(cur);
            dfs(now + 1, cur, mxl, n_mxr, mnl, n_mnr, (flg and (cur == n)));
            stp.pop_back();
        }
    }

    inline void solve() {
        dfs(1, 0, 0, 0, 0x3f3f3f3f, 0x3f3f3f3f, true);
        std::cout << ans << "\n";
    }
}

void solve() {
    std::cin >> n;
    rep (i, 1, n) rep (j, 1, n) {
        std::cin >> a[i][j];
    }

    Solution::solve();
    // Task0::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("walk")

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}

/*
10
7 2 0 8 10 1 28 21 23 9 
9 21 28 24 17 16 22 1 11 23 
27 23 2 6 20 2 28 29 8 22 
20 9 1 1 13 23 25 24 23 21 
15 19 2 22 11 17 6 11 10 16 
10 20 17 28 13 23 29 4 27 19 
27 13 23 19 22 16 10 12 21 9 
18 19 3 26 2 0 10 21 24 2 
8 13 17 3 15 2 14 2 13 11 
27 24 11 5 7 16 24 12 20 7 
*/

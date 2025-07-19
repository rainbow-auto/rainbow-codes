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
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x"0.out", "w", stdout);

constexpr int maxn = 505;

int n;

int a[maxn][maxn];

namespace Solution {
    bool chk(int k) {
        bool flg1p = 0;
        rep (p, 1, n) {
            rep (i, 1, n) rep (j, 1, n) {
                if (std::abs(a[i][j] - a[1][p]) > k) {
                    flg1p = true; 
                    break;
                }
            }
            if (flg1p) break;
        }
        
        bool flgp1 = 0;
        rep (p, 1, n) {
            rep (i, 1, n) rep (j, 1, n) {
                if (std::abs(a[i][j] - a[p][1]) > k) {
                    flgp1 = true; 
                    break;
                }
            }
            if (flgp1) break;
        }

        bool flgpn = 0;
        rep (p, 1, n) {
            rep (i, 1, n) rep (j, 1, n) {
                if (std::abs(a[i][j] - a[p][n]) > k) {
                    flgpn = true; 
                    break;
                }
            }
            if (flgpn) break;
        }

        bool flgnp = 0;
        rep (p, 1, n) {
            rep (i, 1, n) rep (j, 1, n) {
                if (std::abs(a[i][j] - a[n][p]) > k) {
                    flgnp = true; 
                    break;
                }
            }
            if (flgnp) break;
        }

        return !(flg1p and flgp1 and flgnp and flgpn);
    }

    inline void solve() {
        int mx = 0, mn = 0x3f3f3f3f;
        rep (i, 1, n) rep (j, 1, n) mx = std::max(mx, a[i][j]);
        rep (i, 1, n) rep (j, 1, n) mn = std::min(mn, a[i][j]);
        
        int l = 0, r = mx - mn;
        int ans = mx - mn;

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
            // if (ansnow == 21) {
            //     for (auto x : stp) db << x << " "; dbendl;
            // }
            
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

    // Solution::solve();
    Task0::solve();
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

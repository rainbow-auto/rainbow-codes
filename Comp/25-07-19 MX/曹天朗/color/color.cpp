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

constexpr int maxn = 1505;

int n;

int a[maxn][maxn];

namespace Task1 {
    std::vector<std::pair<int, int>> b[maxn];
    std::vector<std::pair<int, int>> c[maxn];

    inline bool chk(int d) {
        std::vector<int> x;
        std::vector<int> y;

        int lst_x = 0;
        rep (i, 1, n) {
            for (auto t : b[i]) {
                int len = t.second;
                rep (j, t.first, t.first + len - 1) {
                    if (j + d - 1 > t.first + len - 1) break;
                    if (not lst_x) lst_x = i;
                    if (lst_x != i) return true;
                    x.push_back(j);
                }
            }
        }

        int lst_y = 0;
        rep (i, 1, n) {
            for (auto t : c[i]) {
                int len = t.second;
                rep (j, t.first, t.first + len - 1) {
                    if (j + d - 1 > t.first + len - 1) break;
                    if (not lst_y) lst_y = i;
                    if (lst_y != i) return true;
                    y.push_back(j);
                }
            }
        }
        
        if (lst_y) {
            for (auto j : x) {
                if (j > lst_y) return true;
                if (j + d - 1 < lst_y) return true;
            }
        }
        
        if (lst_x) {
            for (auto j : y) {
                if (j > lst_x) return true;
                if (j + d - 1 < lst_x) return true;
            }
        }

        if (not x.empty()) if (x.front() + d - 1 < x.back()) return true;
        if (not y.empty()) if (y.front() + d - 1 < y.back()) return true;

        return false;
    }

    inline void solve() {
        rep (i, 1, n) {
            rep (j, 1, n) {
                if (not a[i][j]) continue;

                if (a[i][j] and a[i][j - 1]) {
                    b[i].back().second++;
                } else {
                    b[i].push_back(std::pair<int, int> { j, 1 });
                }
            }
        }

        rep (i, 1, n) {
            rep (j, 1, n) {
                if (not a[j][i]) continue;

                if (a[j][i] and a[j - 1][i]) {
                    c[i].back().second++;
                } else {
                    c[i].push_back(std::pair<int, int> { j, 1 });
                }
            }
        }

        // db << chk(5) << "\n";

        int l = 1, r = n;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (chk(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }        
        std::cout << ans << "\n";
    }
}

void solve() {
    std::cin >> n;
    rep (i, 1, n) rep (j, 1, n) {
        char c; std::cin >> c;
        if (c == '.') a[i][j] = 1;
        if (c == 'X') a[i][j] = 0;
    }
 
    Task1::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("color")

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

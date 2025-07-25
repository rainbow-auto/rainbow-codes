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

constexpr int maxn = 200005;

int n, m, q;
std::pair<int, int> a[maxn];

namespace Task0 {
    constexpr int maxn = 2005;

    int id[maxn];
    using Range = std::pair<int, int>;

    std::set<Range> col[maxn];

    inline void solve(int l, int r) {
        // db << "qry " << l << " " << r << "\n";
        
        rep (i, 1, n) {
            id[i] = i;
            col[i].clear();
            col[i].insert(Range{ i, i });
        }

        rep (i, l, r) {
            int x = a[i].first;
            int y = a[i].second;

            // db << x << " -> " << y << "\n";
            if (x == y) continue;

            if (not id[x]) continue;
            if (not id[y]) {
                id[y] = id[x];
                id[x] = 0;
                continue;
            }

            int xxx = x;
            x = id[x];
            y = id[y];

            for (auto rg : col[x]) {
                // db << rg.first << " " << rg.second << "\n";

                auto it = col[y].upper_bound({ rg.second, 0 });
                if (it != col[y].end()) {
                    // db << "it1 -> " << it->first << " " << it->second << "\n";
                    if (it -> first == rg.second + 1) {
                        rg = Range { rg.first, it -> second };
                        col[y].erase(it);
                        
                        // db << "mrgd: " << rg.first << " " << rg.second << "\n";
                    }
                }
                
                it = col[y].upper_bound({ rg.first, 0 });
                if (it != col[y].begin()) {
                    it--;
                    // db << "it2 -> " << it->first << " " << it->second << "\n";
                    if (it -> second == rg.first - 1) {
                        rg = Range { it -> first, rg.second };
                        col[y].erase(it);
                        // db << "mrgd: " << rg.first << " " << rg.second << "\n";
                    }
                }
                col[y].insert(rg);
            }

            col[x].clear();
            id[xxx] = 0;
        }

        int ans = 0;
        rep (i, 1, n) ans += col[i].size();
        // rep (i, 1, n) db << col[i].size() << " "; dbendl
        std::cout << ans << "\n";

        // dbendl
    }

    inline void solve() {
        while (q--) {
            int l, r; std::cin >> l >> r;
            solve(l, r);
        }
    }
}

void solve() {
	std::cin >> n >> m >> q;
    rep (i, 1, m) std::cin >> a[i].first >> a[i].second;
    
    Task0::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("flower")

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

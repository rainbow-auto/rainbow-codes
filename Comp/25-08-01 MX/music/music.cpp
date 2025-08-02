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

constexpr int maxn = 500005;

int n, k;
int a[maxn];

namespace Sol {
    int suf[maxn];

    int to[maxn];

    inline void solve() {
        std::sort(a + 1, a + n + 1);

        rep (i, 1, n) to[i] = std::upper_bound(a + 1, a + n + 1, a[i] + k) - a;
        per (i, n, 1) suf[i] = std::max(suf[i + 1], to[i] - (int) i);

        int ans = 0;
        rep (i, 1, n) ans = std::max(ans, (to[i] - (int) i) + suf[to[i]]);
        std::cout << ans << "\n";
    }
}

namespace Task0 {
    inline void solve() {
        std::sort(a + 1, a + n + 1);
        
        int ans = 0;
        rep (i, 1, n) {
            rep (j, i, n) {
                if (a[j] - a[i] > k) continue;
                rep (l1, j + 1, n) {
                    rep (r1, l1, n) {
                        if (a[r1] - a[l1] > k) continue;
                        ans = std::max(ans, int (j - i + 1) + int (r1 - l1 + 1));
                    }
                }
            }
        }

        std::cout << ans << "\n";
    }
}

void solve() {
	std::cin >> n >> k;
    rep (i, 1, n) std::cin >> a[i];

    Sol::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("music")

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

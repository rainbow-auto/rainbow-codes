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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 1000005;

int n, m;
int h[maxn];

namespace Solution {
    int cnt[maxn];

    inline void solve() {
        if (n == 1) return std::cout << "0\n", void(0);
        int dmx = m / (n - 1) + 1; 

        int ans = 0x3f3f3f3f;
        rep (d, 0, dmx) {
            int mx = 0;
            rep (i, 1, n) {
                int A = h[i] - (i - 1) * d;
                if (A >= 0) {
                    cnt[A]++;
                    mx = std::max(mx, cnt[A]);
                }
            }

            ans = std::min(ans, n - mx);

            rep (i, 1, n) {
                int A = h[i] - (i - 1) * d;
                if (A >= 0) cnt[A]--;
            }
        }

        std::cout << ans << "\n";
    }
}

void solve() {
	std::cin >> n >> m;
    rep (i, 1, n) std::cin >> h[i];

    Solution::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("climb")

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

    lookTime

	return 0;
}

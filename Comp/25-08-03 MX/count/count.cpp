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

constexpr int mod = 998244353;

int n, k;

namespace Sol {
    std::map<int, int> ps;
    inline void solve() {
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                ps[i]++;
                n /= i;
            }
        }
        if (n > 1) ps[n]++;

        i64 ans = 1;
        for (auto [_, a] : ps) {
            if (a % k == 0 and a / k < a) (ans *= 2ll) %= mod;
        }
        std::cout << ans << "\n";
    }
}

void solve() {
    std::cin >> n;
    std::cin >> k;

    Sol::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("count")

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

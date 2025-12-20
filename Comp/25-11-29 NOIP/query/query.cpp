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

using u64 = unsigned long long;

constexpr int maxn = 100005;

int n;
i64 a[maxn];

inline u64 solve(int l, int r) {
    u64 ans = 0;
 
    rep (i, 1, n) {
        
    }

    rep (i, 1, n) {
        rep (k, i, n) {
            
        }

        ans ^= (1ull * cur * i);
    }
}

void solve() {
    std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];
    rep (i, 1, n) a[i] += a[i - 1];

    std::cin >> q;
    while (q--) {
        int l, r; std::cin >> l >> r;
        std::cout << solve() << "\n";
    }
}

bool MemED;
int main() {
	fastread
	// lookMem	

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

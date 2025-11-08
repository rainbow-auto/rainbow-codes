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

int n, m;
bool s[maxn];
int c[maxn];

namespace Task1 {
    int p[maxn];

    inline void solve() {
        rep (i, 1, n) p[i] = i;
        
        int ans = 0;
        do {
            int tot = 0;
            int x = 0;
            rep (i, 1, n) {
                if (not s[i]) {
                    tot++;
                } else {
                    if (tot >= c[p[i]]) {
                        tot++;
                    } else {
                        x++;
                    }
                }
            }

            if (x >= m) ans++;
        } while (std::next_permutation(p + 1, p + n + 1));

        std::cout << ans << "\n";
    }
}

void solve() {
	std::cin >> n >> m;
    rep (i, 1, n) {
        char c; std::cin >> c;
        s[i] = c - '0';
    }

    rep (i, 1, n) {
        std::cin >> c[i];
    }
    
    Task1::solve();
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

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

constexpr int maxn = 1005;

int n;
int a[maxn], b[maxn];

namespace Task1 {
    int f[maxn][maxn];
    
    inline void solve() {
        std::memset(f, 0x3f, sizeof f);
        
        f[0][0] = 0;
        rep (i, 0, n + 1) {
            rep (j, 0, n + 1) {
                if (a[i] != b[j]) continue;
                rep (x, 0, i - 1) rep (y, 0, j - 1) {
                    if (a[x] != b[y]) continue;
                    if (f[x][y] == 0x3f3f3f3f3f3f3f3f) continue;
                    f[i][j] = std::min(f[i][j], int(f[x][y] + (i - x) * (i - x) + (j - y) * (j - y)));
                }
            }
        }

        std::cout << f[n + 1][n + 1] << "\n";
    }
}

void solve() {
    std::cin >> n;
    rep (i, 0, n + 1) std::cin >> a[i];
    rep (i, 0, n + 1) std::cin >> b[i];

    Task1::solve();
    // Task2::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("stone")

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

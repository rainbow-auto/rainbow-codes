#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 2005;

int n, A, B;
int p[maxn], C[maxn], X[maxn];

inline bool chkmax(int &a, int b) {
    if (a < b) return (a = b), 1;
    return false;
}

namespace Task1 {
    constexpr int maxn = 205;
    int f[maxn][maxn][maxn];

    inline void solve(){
        std::memset(f, -0x3f, sizeof f);
        f[0][A][B] = 0;

        rep (i, 1, n) {
            rep (a, 0, A) rep (b, 0, B) f[i][a][b] = f[i - 1][a][b];
            rep (a, 0, A) rep (b, 0, B) {
                per (c, std::min(C[i], a), 0) {
                    if ((C[i] - c) * X[i] > b) break;
                    chkmax(f[i][a - c][b - (C[i] - c) * X[i]], f[i - 1][a][b] + p[i]);
                }
            }
        }

        int ans = 0;
        rep (a, 0, A) rep (b, 0, B) chkmax(ans, f[n][a][b]);
        std::cout << ans << "\n";
    }
}

void solve() {
	std::cin >> n >> A >> B;
    rep (i, 1, n) std::cin >> p[i] >> C[i] >> X[i];

    Task1::solve();

    lookTime
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("C")

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

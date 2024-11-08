#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 10;

int n, mg, mh;

bool g[maxn][maxn];
bool h[maxn][maxn];

int p[maxn];

int w[maxn][maxn];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    std::cin >> n;
    std::cin >> mg;

    rep (i, 1, mg) { int u, v; std::cin >> u >> v; g[u][v] = g[v][u] = true; }

    std::cin >> mh;
    rep (i, 1, mh) { int u, v; std::cin >> u >> v; h[u][v] = h[v][u] = true; }

    rep (i, 1, n) {
        rep (j, i + 1, n) { std::cin >> w[i][j]; w[j][i] = w[i][j]; }
    }   

    rep (i, 1, n) { p[i] = i; }

    i64 ans = 1e18;

    do {
        i64 ansnow = 0;
        rep (i, 1, n) {
            rep (j, 1, n) {
                ansnow += (g[p[i]][p[j]] != h[i][j]) * w[i][j];
            }
        }
        ansnow >>= 1;
        
        ans = std::min (ans, ansnow);
    } while (std::next_permutation (p + 1, p + n + 1));

    std::cout << ans << "\n";

	return 0;
}

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

constexpr int maxn = 55;

int n, m;
int k;
std::pair<int, int> ns[maxn];

f64 dis[maxn][maxn];

inline void init() {
    rep (i, 1, k) {
        rep (j, 1, k) {
            auto x = ns[i];
            auto y = ns[j];
            dis[i][j] = std::sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
        }
    }
}

constexpr f64 eps = 1e-10;

inline bool chk(int a, int b, int c, int d) {
    f64 r1 = dis[a][b];
    if (ns[a].first + r1 > n) return false;
    if (ns[a].first - r1 < 0) return false;
    if (ns[a].second + r1 > m) return false;
    if (ns[a].second - r1 < 0) return false;
    
    f64 r2 = dis[c][d];
    if (ns[c].first + r2 > n) return false;
    if (ns[c].first - r2 < 0) return false;
    if (ns[c].second + r2 > m) return false;
    if (ns[c].second - r2 < 0) return false;

    f64 dt = dis[a][c] + r2 - r1;
    if (std::fabs(dt) < eps) return false;

    if (dt < 0) return true;
    return false;
}

void solve() {
    std::cin >> k;
    std::cin >> n >> m;

    rep (i, 1, k) std::cin >> ns[i].first >> ns[i].second;

    init();
    
    int ans = 0;
    rep (a, 1, k) 
    rep (b, 1, k) if (b != a) 
    rep (c, 1, k) if (c != a and c != b) 
    rep (d, 1, k) if (d != a and d != b and d != c) {
        ans += chk(a, b, c, d);
    }
    std::cout << ans << "\n";

    lookTime
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("circle")

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

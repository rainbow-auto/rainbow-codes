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

constexpr int maxn = 20005;
constexpr int maxk = 12;

int n, m, k;
struct Edge {
    int u, v;
    int w;
};

int c[maxn];
int a[maxk][maxn];
std::vector<Edge> es;

struct DSU {
    int fa[maxn], siz[maxn];
    inline int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    inline void mrg(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        if (siz[u] < siz[v]) std::swap(u, v);
        siz[u] += siz[v];
        fa[v] = u;
    }

    inline void init() {
        rep (i, 1, n + k) fa[i] = i;
        rep (i, 1, n + k) siz[i] = 1;
    }
} dsu;

std::vector<Edge> es0, es1;

inline i64 calc(int S) {
    i64 res = 0;
    es1 = es0;

    rep (i, 1, k) if (S & (1 << (i - 1))) {
        res += c[i];
        rep (j, 1, n) {
            es1.push_back({n + i, j, a[i][j]});
        }
    }

    std::sort(es1.begin(), es1.end(), [&](Edge x, Edge y) -> bool {
        return x.w < y.w;
    });

    dsu.init();
    for (auto [u, v, w] : es1) {
        if (dsu.find(u) == dsu.find(v)) continue;
        dsu.mrg(u, v);
        res += w;
    }

    return res;
}

void solve() {
    std::cin >> n >> m >> k;
    rep (i, 1, m) {
        int u, v; std::cin >> u >> v;
        int w; std::cin >> w;
        es0.push_back({u, v, w});
    }

    bool flg = true;
    rep (i, 1, k) {
        std::cin >> c[i];
        flg &= (c[i] == 0);
        rep (j, 1, n) std::cin >> a[i][j];
    }

    std::sort(es.begin(), es.end(), [&](Edge x, Edge y) -> bool {
        return x.w < y.w;
    });

    dsu.init();
    for (auto [u, v, w] : es) {
        if (dsu.find(u) == dsu.find(v)) continue;
        dsu.mrg(u, v);
        es0.push_back({u, v, w});
    }

    // if (flg) {
    //     std::cout << calc((1 << k) - 1) << "\n";        
    // } else {
    //     i64 ans = 1e18;
    
    //     rep (S, 0, (1 << k) - 1) {
    //         ans = std::min(ans, calc(S));
    //     }
    
    //     std::cout << ans << "\n";
    // }

    lookTime
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("road")

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

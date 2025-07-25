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
// constexpr int mod = 998244353;
constexpr int mod = 1e9 + 7;

inline i64 ksm(i64 a, i64 b) {
    i64 res = 1;
    for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
    return res;
}

int n, m, H;

using Edge = std::pair<std::pair<int, int>, i64>;
std::vector<Edge> es;

inline int id(int x, int y) {
	return (x - 1) * m + y;
}

struct DSU {
    int fa[maxn];
    int siz[maxn];
    i64 f[maxn], h[maxn];

    inline void init() {
        rep (i, 1, n) fa[i] = i;
        rep (i, 1, n) h[i] = 0;
        rep (i, 1, n) f[i] = 1;
    }

    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    inline void mrg(int u, int v, i64 w) {
        // db << "mrg " << u << " " << v << "\n";
        u = find(u); v = find(v);
        if (u == v) return;
        f[u] = 1ll * (f[v] + w - h[v]) % mod * (f[u] + w - h[u]) % mod;
        fa[v] = u;
        h[u] = w;
    }
} dsu;

namespace Solution {
    inline void solve() {
		n = n * m;

        std::sort(es.begin(), es.end(), [&](Edge u, Edge v) -> bool {
            return u.second < v.second;
        });

        dsu.init();
		for (auto e : es) {
            dsu.mrg(e.first.first, e.first.second, e.second);
        }

        i64 ans = 1;
        rep (i, 1, n) {
            if (dsu.fa[i] == i) (ans *= (dsu.f[i] + H - dsu.h[i])) %= mod;
        }

        std::cout << ans << "\n";
    }
}

void solve() {
	std::cin >> n >> m >> H;

    // rep (i, 1, m) {
    //     int u, v, d; std::cin >> u >> v >> d;
    //     es[i] = { { u, v }, d };
    // }

	rep (i, 1, n) {
		rep (j, 1, m - 1) {
			int c; std::cin >> c;
			es.push_back(Edge {{id(i, j), id(i, j + 1)}, c});
		}
	}
	
	rep (i, 1, n - 1) {
		rep (j, 1, m) {
			int c; std::cin >> c;
			es.push_back(Edge {{id(i, j), id(i + 1, j)}, c});
		}
	}
    
    Solution::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("rain")

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

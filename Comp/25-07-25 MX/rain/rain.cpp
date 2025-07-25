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

constexpr int maxn = 200005;
constexpr int mod = 998244353;

inline i64 ksm(i64 a, i64 b) {
    i64 res = 1;
    for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
    return res;
}

int n, m, H;

std::pair<std::pair<int, int>, i64> es[maxn];

struct DSU {
    int fa[maxn];
    int siz[maxn];
    inline void init() {
        rep (i, 1, n) fa[i] = i;
        rep (i, 1, n) siz[i] = 1;
    }

    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    inline void mrg(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        fa[v] = u;
        siz[u] += siz[v];
    }
} dsu;

namespace Task1 {
    inline void solve() {
        db << "Task1\n";

        dsu.init();
        rep (i, 1, m) {
            if (es[i].second == 1) continue;
            dsu.mrg(es[i].first.first, es[i].first.second);
        }

        i64 ans = 1;
        rep (i, 1, n) {
            if (dsu.fa[i] == i) (ans *= 2ll) %= mod;
        }
        std::cout << ans << "\n";
    }
}

namespace Task2 {
    inline void solve() {
        dsu.init();
        i64 d = 0;
        rep (i, 1, m) {
            dsu.mrg(es[i].first.first, es[i].first.second);
            d = es[i].second;
        }   

        i64 ans = 1ll;
        rep (i, 1, n) {
            if (dsu.fa[i] != i) continue;
            dbg(dsu.siz[i]);
            (ans *= (ksm(H - d, dsu.siz[i]) + ksm(d + 1, dsu.siz[i])) % mod) %= mod;
        }

        std::cout << ans << "\n";
    }
}

void solve() {
	std::cin >> n >> m >> H;

    bool flg2 = true;
    rep (i, 1, m) {
        int u, v, d; std::cin >> u >> v >> d;
        es[i] = { { u, v }, d };
        if (i > 1) flg2 &= (es[i].second == es[i - 1].second);
    }
    
    if (H == 1) return Task1::solve(), void(0);
    if (flg2) return Task2::solve(), void(0);
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("rain")

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

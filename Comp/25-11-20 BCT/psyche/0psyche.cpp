#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
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

constexpr int maxn = 50005;

int n;
int p[maxn];

using Edge = std::pair< i64, std::pair<int, int> >;
struct DSU {
    int fa[maxn], siz[maxn];
   
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
        if (siz[v] > siz[u]) std::swap(u, v);
        fa[v] = u;
        siz[u] += siz[v];
    }
} dsu;

namespace Sol {
    int pr[maxn];

    std::vector<std::pair<unsigned short, unsigned short>> vs[maxn];
    inline void solve() {
        int B = sqrt(n);
        rep (i, 1, n) rep (j, i + 1, std::min(i + B, n)) {
            if ((j - i) * std::abs(p[j] - p[i]) <= n) vs[(j - i) * std::abs(p[j] - p[i])].push_back({i, j});
        }

        rep (i, 1, n) pr[p[i]] = i;

        rep (i, 1, n) rep (j, i + 1, std::min(i + B, n)) {
            if (std::abs(pr[i] - pr[j]) <= B) continue;
            if ((j - i) * std::abs(pr[j] - pr[i]) <= n) vs[(j - i) * std::abs(pr[j] - pr[i])].push_back({pr[i], pr[j]});
        }

        dsu.init();

        int tot = 0;
        i64 ans = 0;

        for (int w = 1; ; w++) {
            for (auto _ : vs[w]) {
                int u = _.first;
                int v = _.second;
    
                if (dsu.find(u) == dsu.find(v)) continue;
                
                dsu.mrg(u, v);
                tot++;
    
                ans += w;
                if (tot >= n - 1) break;
            }
            if (tot >= n - 1) break;
        }

        std::cout << ans << "\n";
    }
}

void solve() {
    std::cin >> n;
    rep (i, 1, n) std::cin >> p[i];

    Sol::solve();
    // Task2::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("psyche4")

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

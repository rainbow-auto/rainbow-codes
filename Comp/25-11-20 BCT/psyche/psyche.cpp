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

namespace Task1 {
    inline void solve() {
        lookTime

        std::vector< std::pair< i64, std::pair<int, int> > > es;
        rep (i, 1, n) {
            rep (j, i + 1, n) {
                es.push_back({1ll * (j - i) * std::abs(p[j] - p[i]), {i, j}});
            }
        }
        lookTime
        
        dsu.init();
        std::sort(es.begin(), es.end());

        lookTime

        int tot = 0;
        i64 ans = 0;
        for (auto _ : es) {
            i64 w = _.first;
            int u = _.second.first;
            int v = _.second.second;

            if (dsu.find(u) == dsu.find(v)) continue;
            
            dsu.mrg(u, v);
            tot++;

            ans += w;
            if (tot >= n - 1) break;
        }

        lookTime
        
        std::cout << ans << "\n";
    }
}

namespace Task2 {
    std::vector<Edge> es[maxn];

    inline void solve() {
        std::priority_queue< std::pair<i64, std::pair<int, int>> > q;
        rep (len, 1, n - 1) {
            rep (i, 1, n - len + 1) {
                int j = i + len - 1;
                es[len].push_back({1ll * (j - i) * std::abs(p[j] - p[i]), {i, j}});
            }
            std::sort(es[len].begin(), es[len].end());
            q.push(std::pair< i64, std::pair<int, int> >{-es[len].front().first, {len, 0}});
        }
    
        lookTime

        dsu.init();

        int tot = 0;
        i64 ans = 0;
        while (tot < n - 1) {
            i64 w = -q.top().first;
            int len = q.top().second.first;
            int pos = q.top().second.second;
            int u = es[len][pos].second.first;
            int v = es[len][pos].second.second;
            q.pop();

            if (pos + 1 < (int) es[len].size()) {
                q.push({-es[len][pos + 1].first, {len, pos + 1}});
            }

            if (dsu.find(u) == dsu.find(v)) continue;
            dsu.mrg(u, v);
            tot++;
            ans += w;
        }

        std::cout << ans << "\n";
    }
}

void solve() {
    std::cin >> n;
    rep (i, 1, n) std::cin >> p[i];

    Task1::solve();
    // Task2::solve();

    lookTime
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("psyche")

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

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

constexpr int maxn = 305;
constexpr int maxq = 500005;

int n, q;
using Graph = std::vector<std::vector<i64>>;

i64 ans[maxq];

struct Query {
    int s, t;
    int id;
};
std::vector<Query> qs[maxn];

// namespace Task1 {
//     Graph g;

//     inline void calc(int u) {
//         g = a;
//         rep (k, 1, n) {
//             if (k == u) continue;
//             rep (i, 1, n) {
//                 rep (j, 1, n) {
//                     g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
//                 }
//             }
//         }
     
//         for (auto [s, t, id] : qs[u]) {
//             ans[id] = g[s][t];
//         }
//     }

//     inline void solve() {
//         rep (i, 1, n) {
//             if (not qs[i].size()) continue;
//             calc(i);
//         }
        
//         rep (id, 1, q) std::cout << ans[id] << "\n";
//     }
// }

void solve(int l, int r, Graph g) {
    if (l == r) {
        for (auto [s, t, id] : qs[l]) {
            ans[id] = g[s][t];
        }
        return;
    }
    
    int mid = (l + r) >> 1;
    
    auto gR = g;
    rep (u, mid + 1, r) rep (i, 1, n) rep (j, 1, n) gR[i][j] = std::min(gR[i][j], gR[i][u] + gR[u][j]);
    solve(l, mid, gR);
    
    rep (u, l, mid) rep (i, 1, n) rep (j, 1, n) g[i][j] = std::min(g[i][j], g[i][u] + g[u][j]);
    solve(mid + 1, r, g);
}
    
void solve() {
    std::cin >> n >> q;
    Graph a(n + 1, std::vector<i64>(n + 1));
    rep (i, 1, n) rep (j, 1, n) std::cin >> a[i][j];
    
    rep (id, 1, q) {
        int s, t; std::cin >> s >> t;
        int p; std::cin >> p;
        qs[p].push_back({s, t, id});
    }
    
    solve(1, n, a);
    rep (id, 1, q) std::cout << ans[id] << "\n";

    // Task1::solve();
    // Task2::solve();

    lookTime
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("distance")

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

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

constexpr int maxn = 1000005;

int n, m;
std::vector<int> a[maxn];
std::vector<int> b[maxn];

inline int id(int x, int y) {
    return (x - 1) * m + y;
}

struct DSU {
    int fa[maxn];
    int L[maxn], R[maxn];
    void init() {
        rep (i, 1, n) rep (j, 1, m) {
            fa[id(i, j)] = id(i, j);
            L[id(i, j)] = R[id(i, j)] = i;
        }
    }

    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    inline void mrg(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        fa[v] = u;
        R[u] = std::max(R[u], R[v]);
        L[u] = std::min(L[u], L[v]);
    }
} dsu;

std::pair<int, int> to[maxn];
std::vector<std::pair<int, int>> del[maxn], add[maxn];
inline void init() { 
    rep (i, 1, n) rep (j, 1, m) if (dsu.find(id(i, j)) == id(i, j)) {
        del[dsu.L[id(i, j)]].push_back({R[id(i, j)], id(i, j)});
        add[dsu.R[id(i, j)]].push_back({R[id(i, j)], id(i, j)});
    }

    std::set<std::pair<int,int>> cur;
    per (i, n, 1) {
        for (auto x : add) cur.insert(x);
        to[i] = *cur.begin();
        for (auto x : del) cur.erase(x);
    }
}

inline void calc(int u, int v) {
    while (dsu.R[u] < v) {
        if (dsu.R[u]  dsu.R[to[i].second]) 
    }
}   

void solve() {
    std::cin >> n >> m >> q;

    dsu.init();
    rep (i, 1, n) rep (j, 1, m - 1) {
        char c; std::cin >> c;
        if (c == '1') mrg(id(i, j), id(i, j + 1));
    }

    rep (i, 1, n - 1) rep (j, 1, m) {
        char c; std::cin >> c;
        if (c == '1') mrg(id(i, j), id(i + 1, j));
    }

    init();

    while (q--) {
        int t; std::cin >> t;
        int ux, uy; std::cin >> ux >> uy;
        int vx, vy; std::cin >> vx >> vy;
        int bu = dsu.find(id(ux, uy));
        int bv = dsu.find(id(vx, vy));

        if (bu == bv) {
            std::cout << "0\n"; continue;
        }

        std::cout << calc(bu, bv) + 1 << "\n";
    }
}

bool MemED;
int main() {
	fastread
	// lookMem	

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

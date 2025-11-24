#include<bits/stdc++.h>

#define rep(_id, _st, _ed) for (int _id = (_st); _id <= (_ed); _id++) 
#define per(_id, _st, _ed) for (int _id = (_st); _id >= (_ed); _id--) 
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s used\n";

using i64 = long long;

constexpr int maxn = 1005;

std::vector<int> g[maxn];
std::vector<int> ug[maxn];

namespace Sol {
    std::bitset<maxn> vis;
    std::vector<std::pair<int, int>> ans;

    int status[maxn];
    void dfs(int now) {

    }

    void getans(int now) {

    }

    inline void solve() {
        rep (i, 1, n) {
            if (vis[i]) continue;
        }   

    }
}

inline void solve() {
    std::cin >> n >> m;
    rep (i, 1, n) {
        int u, v; std::cin >> u >> v;
        g[u].push_back(v);

        ug[u].push_back(v);
        ug[v].push_back(u);
    }
    
    Sol::solve();
}

int main() {
    fastread

    solve();

    return 0;
}
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

int n, m;

std::vector<int> g[maxn];
std::vector<int> ug[maxn];

namespace Sol {
    std::bitset<maxn> vis;
    std::vector<std::pair<int, int>> ans;

    std::vector<int> p;
    int col[maxn];
    bool dfs(int now, int st) {
        col[now] = 1;
        for (auto t : g[now]) {
            if (t == st) continue;
            if (not col[t]) {
                if (not dfs(t, st)) return false;
            } else if (col[t] == 1) {
                return false;
            }
        }
        col[now] = 2;
        p.push_back(now);
        return true;
    }

    std::vector<int> vec;
    void getvec(int now) {
        if (vis[now]) return;
        vis[now] = true;
        for (auto t : ug[now]) {
            getvec(t);
        }
        vec.push_back(now);
    }

    inline bool chk(int st) {
        std::exchange(p, {});
        for (auto x : vec) col[x] = 0;

        for (auto t : vec) {
            if (t == st) continue;
            if (col[t]) continue;
            if (not dfs(t, st)) return false;
        }

        return true;
    }

    inline void solve() {
        rep (i, 1, n) {
            if (vis[i]) continue;
            std::exchange(vec, {});
            getvec(i);

            // for (auto x : vec) db << x << " "; dbendl;

            if (chk(-1)) {
                rep (k, 1, (int) p.size() - 1) {
                    ans.push_back({p[k - 1], p[k]});
                }
            } else {
                bool flg = false;
                for (auto ex : vec) {
                    if (chk(ex)) {
                        p.push_back(ex);
                        ans.push_back({p.back(), p.front()});
                        rep (k, 1, (int) p.size() - 1) ans.push_back({p[k - 1], p[k]});
                        flg = true;
                        break;
                    }
                }
                if (not flg) return std::cout << "-1\n", void(0);
            }
        }   

        std::cout << ans.size() << "\n";
        for (auto [u, v] : ans) {
            std::cout << u << " " << v << "\n";
        }
    }
}

inline void solve() {
    std::cin >> n >> m;
    rep (i, 1, m) {
        int u, v; std::cin >> u >> v;
        g[v].push_back(u);

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
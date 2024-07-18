#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using i64 = long long;

const int maxn = 4000005;

int n, m, b;

struct Edge {
    int u, v;
};
std::vector<Edge> es;

std::vector<int> g[maxn];

bool vis[maxn];

int ind[maxn], otd[maxn];

std::vector<int> euler;
void dfs (int now, int eid) {
    for (auto t : g[now]) { // g[now] 中编号一定是单增的
        if (not vis[t]) {
            vis[t] = true;
            dfs (es[t].v, t);
        }
    }
    euler.push_back (eid);
}

inline bool chk (std::string s) {
    int last = -1;
    for (int i = 0; i < s.size (); i++) {
        if (s[i] == '1') {
            if (last == -1) { last = i; continue; }
            if (i - last != m) { return false; }
            last = i;
        }
    }

    int len = 0;
    for (int i = 0; i < s.size (); i++) {
        if (s[i] == '1') {
            len = 0;
        } else {
            len++;
            if (len > m - 1) { return false; }
        }
    }

    return true;
} 

int main () {

    freopen ("card.in", "r", stdin);
    freopen ("card.out", "w", stdout);

    std::ios::sync_with_stdio (false);

    std::cin >> n >> m >> b;

    for (int i = 1; i <= n; i++) {
        std::string s; std::cin >> s;
     
        if (not chk (s)) { std::cout << -1 << "\n"; return 0; }
     
        int pos = 0;
        for (auto c : s) { if (c == '1') { break; } pos ++; }

        int u = (b - pos + m) % m;
        int v = (u + s.size ()) % m;

        otd[u] ++;
        ind[v] ++;

        es.push_back (Edge { u, v }); 
        g[u].push_back (es.size () - 1);
    }

    for (int i = 0; i < m; i++) { if (ind[i] != otd[i]) { std::cout << -1 << "\n"; return 0; } }

    dfs (0, -1);

    std::reverse (euler.begin (), euler.end ());

    if (euler.size () != n + 1) { std::cout << -1 << "\n"; return 0; }

    for (auto now : euler) {
        if (now == -1) { continue; }
        std::cout << now + 1 << " "; 
    }

    return 0;
}
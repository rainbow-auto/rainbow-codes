#include <iostream>
#include <set>

const int maxn = (1 << 5) + 5;

i64 n, m, k;

int g[maxn][maxn];

inline void 

inline void addEdge (int u, int v) { g[u][v] = 1; }

inline int popcount (int S) {
    int res = 0;
    while (S) { res += (S & 1); S >>= 1; }
    return res;
}

std::set <int> ns; // 点集

int main () {

    std::cin >> n;
    std::cin >> m >> k;

    for (int S = 0; S < (1 << m); S ++) {
        if (popcount (S) > k) { continue; }
        ns.insert (S);
    }

    for (auto u : ns) {
        if (ns.count (u << 1)) { addEdge (u, u << 1); }
        if (ns.count (u << 1 | 1)) { addEdge (u, u << 1 | 1); }
    }

    return 0;
}
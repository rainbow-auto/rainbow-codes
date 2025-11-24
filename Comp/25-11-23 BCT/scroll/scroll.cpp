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

constexpr int maxn = 15;

int n, m;
int mod;

int p[maxn], f[maxn], g[maxn];
int ans[maxn][maxn];

inline void solve() {
    std::cin >> n >> m >> mod;
    rep (i, 1, n * m) p[i] = i;

    do {
        int up = 0, dn = 0;
        rep (i, 1, n * m) {
            f[i] = g[i] = 1;
            rep (j, 1, i) {
                if (p[j] < p[i]) f[i] = std::max(f[i], f[j] + 1);
                if (p[j] > p[i]) g[i] = std::max(g[i], g[j] + 1);
            }
            up = std::max(up, f[i]);
            dn = std::max(dn, g[i]);
        }

        if (up == n and dn == m) {
            rep (a, 1, n * m) ans[a][p[a]]++;
        }
    } while (std::next_permutation(p + 1, p + n * m + 1));

    rep (i, 1, n * m) {
        rep (j, 1, n * m) {
            std::cout << ans[i][j] << " ";
        }
        std::cout << "\n";
    }
}   

int main() {
    fastread

    solve();

    return 0;
}
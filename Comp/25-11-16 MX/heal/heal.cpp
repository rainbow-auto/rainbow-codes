#include <bits/stdc++.h>
#define rep(_id, _st, _ed) for (int (_id) = (_st); (_id) <= (_ed); (_id)++)
#define per(_id, _st, _ed) for (int (_id) = (_st); (_id) >= (_ed); (_id)--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

using i64 = long long;
using u64 = unsigned long long;

constexpr int maxn = 200005;
constexpr int mod = 998244353;

int n;
int a[maxn];

inline int op(int x, int y) {
    int res = 0;
    rep (b, 0, 26) {
        if (((x >> b) & 1) and not ((y >> b) & 1)) res |= (1 << b);
    }
    return res;
}

namespace Task0 {
    int dfs(std::vector<int> s) {
        if (s.size() == 1) return s.front();

        int res = 0;
        rep (i, 0, (int) s.size() - 1) {
            auto nxt = s;
            int x = nxt[i];
            nxt.erase(nxt.begin() + i);
            rep (j, 0, (int) nxt.size() - 1) {
                auto nnxt = nxt;
                int y = nxt[j];
                nnxt.erase(nnxt.begin() + j);
                nnxt.push_back(op(x, y));

                res = std::max(res, dfs(nnxt));
            }
        }

        return res;
    }

    inline void solve() {
        int ans = 0;
        rep (i, 1, n) rep (j, i, n) {
            std::vector<int> s;
            rep (k, i, j) s.push_back(a[k]);
            (ans += dfs(s) % mod) %= mod;
        }
        std::cout << ans << "\n";
    }
}

namespace TaskA {
    inline int choose2(int n) {
        return 1ll * n * (n - 1) / 2 % mod;
    }

    inline void solve() {
        int ans = 0;

        rep (i, 1, n) (ans += a[i]) %= mod;
        rep (i, 1, n - 1) (ans += std::max(op(a[i], a[i + 1]), op(a[i + 1], a[i])) % mod) %= mod;
        
        rep (i, 1, n) {
            int cur = std::max(a[i], a[i + 1]);
            rep (j, i + 2, n) {
                cur = std::max(cur, a[j]);
                (ans += cur % mod) %= mod;
            }
        }

        std::map<int, std::vector<int>> poss;
        rep (i, 1, n) poss[-a[i]].push_back(i);

        std::set<int> pre;
        pre.insert(0);
        pre.insert(n + 1);
        for (auto [_v, pos] : poss) {
            int v = -_v;
            
            int cnt = 0;
            
            int lst = -1;
            for (auto p : pos) {
                auto it = pre.upper_bound(p);
                (cnt += (n - (*it)) * (p - (*std::prev(it)))) %= mod;
                pre.insert(p);
            }

            (ans += 1ll * cnt * v % mod) %= mod;
        }
        
        rep (i, 1, n - 1) (((ans -= std::max(a[i], a[i + 1]) % mod) %= mod) += mod) %= mod;

        std::cout << ans << "\n";
    }
}

inline void solve() {
    std::cin >> n;
    rep (i, 1, n) {
        std::cin >> a[i];
    }

    if (n <= 4) return Task0::solve(), void(0);
    TaskA::solve();
}

int main() {
    fastread

    file("heal3");

    solve();
    
    return 0;
}
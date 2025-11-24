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

constexpr int maxn = 10;

int n, m;
int a[maxn], b[maxn];

namespace Task0 {
    struct Node {
        int to;
        int ord;
    } ops[maxn];

    inline void solve() {
        rep (k, 1, n) {
            std::vector<int> p(n + 1);
            rep (i, 1, n) p[i] = i;
            do {
                std::vector<int> p1(n + 1);
                rep (i, 1, k) p1[i] = i;
                do {
                    rep (i, 1, k) ops[i].to = p[i];
                    rep (i, 1, k) ops[i].ord = p1[i];
                } while (std::next_permutation(p1.begin(), p1.end()));
            } while (std::next_permutation(p.begin() + 1, p.begin() + n + 1));
        }
    }
}

inline void solve() {
    std::cin >> n >> m;
    std::cout << "-1\n";
}

int main() {
    fastread

    file("catapult")

    solve();

    return 0;
}
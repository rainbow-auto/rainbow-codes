#include <bits/stdc++.h>
#define rep(_id, _st, _ed) for (int _id = (_st); _id <= (_ed); _id++) 
#define per(_id, _st, _ed) for (int _id = (_st); _id >= (_ed); _id--) 
#define db std::cerr
#define dbg(x) std::cerr << (#x) << " : " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);
#define file(x) std::freopen(x".in", "w", stdout);

using i64 = long long;

inline void solve() {
    file("ex_sequence5")

    int n = 3000000, k = 3000000;

    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

    std::cout << "0\n";
    std::cout << n << " " << k << "\n";
    rep (i, 1, n) std::cout << (rng() % k + 1) << " ";
}

int main() {
    fastread

    solve();

    return 0;
}
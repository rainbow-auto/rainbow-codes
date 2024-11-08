#include <iostream>
#include <set>
#include <cmath>

using i64 = long long;

const int maxn = 200005;

int T;

int n, q;
int a[maxn];

int log_2[maxn];
inline void init_log_2 () {
    log_2[1] = 0;
    for (int i = 2; i <= 200000; i++) { log_2[i] = log_2[i / 2] + 1; }
}

struct Node {
    int val;
    int pos;

    friend bool operator < (Node x, Node y) { return x.val < y.val; }
};

Node mx[maxn][21];
Node mn[maxn][21];

inline void build () {
    for (int i = 1; i <= n; i++) { mx[i][0] = mn[i][0] = Node { a[i], i }; }

    for (int len = 1; len <= 20; len ++) {
        for (int i = 1; i + (1 << len) - 1 <= n; i++) {
            mx[i][len] = std::max (mx[i][len - 1], mx[i + (1 << (len - 1))][len - 1]);
            mn[i][len] = std::min (mn[i][len - 1], mn[i + (1 << (len - 1))][len - 1]);
        }
    }
}

inline std::pair <Node, Node> query (int l, int r) {
    int len = log_2[r - l + 1];
    Node res_mx = std::max (mx[l][len], mx[r - (1 << len) + 1][len]);
    Node res_mn = std::min (mn[l][len], mn[r - (1 << len) + 1][len]);

    return { res_mx, res_mn };
}

int main () {

    std::cin >> T;

    init_log_2 ();

    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

        build ();   

        std::cin >> q;

        while (q--) {
            int l, r; std::cin >> l >> r;

            auto res = query (l, r);
            if (res.first.val == res.second.val) { std::cout << "-1 -1\n"; }
            else { std::cout << res.first.pos << " " << res.second.pos << "\n"; }
        }

        std::cout << "\n";
    }

    return 0;
}

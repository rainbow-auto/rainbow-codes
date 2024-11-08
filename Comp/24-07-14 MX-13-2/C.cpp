#include <iostream>
#include <algorithm>

using i64 = long long;

const int maxn = 300005;

const i64 mod = 998244353;

int n, T;
i64 a[maxn], b[maxn];

struct Node {
    int rnk;
    int id;
    
    i64 val;
}; 

Node a1[maxn], b1[maxn];

bool sort_by_id (Node x, Node y) {
    return x.id < y.id;
}

bool sort_by_val (Node x, Node y) {
    return x.val < y.val;
}

int pos[maxn];

int main () {

    freopen ("sequence.in", "r", stdin);
    freopen ("sequence.ans", "w", stdout);

    std::cin >> n >> T;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; a1[i] = Node { 0, i, a[i] }; }
    for (int i = 1; i <= n; i++) { std::cin >> b[i]; b1[i] = Node { 0, i, b[i] }; }

    std::sort (a1 + 1, a1 + n + 1, sort_by_val);
    std::sort (b1 + 1, b1 + n + 1, sort_by_val);

    for (int i = 1; i <= n; i++) { a1[i].rnk = i; pos[i] = a1[i].id; }
    for (int i = 1; i <= n; i++) { b1[i].rnk = i; }

    i64 res = 0;
    for (int i = 1; i <= n; i++) { 
        res += (((a1[i].val % mod - b1[i].val % mod) % mod) * ((a1[i].val % mod - b1[i].val % mod) % mod)) % mod;
        res %= mod; 
    }

    std::cout << res << " ";

    if (T == 0) { return 0; }

    std::sort (a1 + 1, a1 + n + 1, sort_by_id);
    std::sort (b1 + 1, b1 + n + 1, sort_by_id);

    int res_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a1[i].rnk == b1[i].rnk) { continue; }

        a1[pos[b1[i].rnk]].rnk = a1[i].rnk;
        pos[a1[i].rnk] = pos[b1[i].rnk];
        pos[b1[i].rnk] = i;
        a1[i].rnk = b1[i].rnk;

        res_cnt ++;
    }

    std::cout << res_cnt << "\n";

    return 0;
}
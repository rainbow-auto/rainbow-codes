#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 500005;

using i64 = long long;

i64 n, k;
struct Node {
    i64 val;
    int id;

    i64 ans;

    friend bool operator < (Node a, Node b) { return a.val < b.val; }
} a[maxn];

inline bool sort_by_id (Node x, Node y) { return x.id < y.id; }

i64 sum[maxn];

inline i64 query (int l, int r) { return sum[r] - sum[l - 1]; }

inline int f (int x) {
    return n - (std::upper_bound (a + 1, a + n + 1, Node { x, 0, 0 }) - a - 1) + 1;
}

inline int g (int x) {
    return n - (std::lower_bound (a + 1, a + n + 1, Node { x, 0, 0 }) - a - 1);
}

int main () {

    freopen ("rank.in", "r", stdin);
    freopen ("rank.out", "w", stdout);

    int c; std::cin >> c;

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) { int x; std::cin >> x; a[i] = Node { x, i, 0 }; }
    
    std::sort (a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) { sum[i] = sum[i - 1] + a[i].val; }

    int start = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].val != a[i - 1].val) { start = i; }
        
        if (f (a[i].val) > k) {
            i64 l = 0, r = 1e10;
            i64 res = 0;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (f (a[i].val + mid) <= k) { res = mid; r = mid - 1; }
                else { l = mid + 1; }
            }
            a[i].ans = res;
        } else if (g (a[i].val) < k) {
            i64 d = k - g (a[i].val); 
            a[i].ans = d * a[i].val - query ((start - 1) - d + 1, (start - 1));
        }
    }

    std::sort (a + 1, a + n + 1, sort_by_id);
    for (int i = 1; i <= n; i++) { std::cout << a[i].ans << "\n"; }

    return 0;
}
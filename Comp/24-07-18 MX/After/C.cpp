#include <iostream>
#include <algorithm>
#include <queue>

using i64 = long long;

const int maxn = 100005;
const i64 inf = 1e17;

int n, k;

struct Node {
    i64 x, y;
    friend bool operator < (Node a, Node b) {
        return a.y < b.y;
    }
} ns[maxn];

i64 abs (i64 x) { return (x > 0) ? x : -x; }

i64 pre[maxn];
i64 suf[maxn];

int main () {

    freopen ("dating.in", "r", stdin);
    freopen ("dating.out", "w", stdout);

    std::cin >> n >> k;

    for (int i = 1; i <= n; i++) { std::cin >> ns[i].x >> ns[i].y; }

    std::sort (ns + 1, ns + n + 1);

    i64 ans = inf;
    for (int i = 1; i <= n; i++) {
        i64 X = ns[i].x;

        i64 up_sum = 0;
        std::priority_queue <i64> q;
        for (int j = 1; j <= n; j++) {
            i64 now = abs (X - ns[j].x) - ns[j].y;
            q.push (now);
            up_sum += now;

            if (q.size () > (k >> 1)) { up_sum -= q.top (); q.pop (); }

            if (q.size () >= (k >> 1)) { pre[j] = up_sum; }
            else { pre[j] = inf; } // 不能取 (ns[j] 不是中位数) (最后取不到 k 个)
        }

        i64 down_sum = 0;
        while (not q.empty ()) { q.pop (); }
        for (int j = n; j >= 1; j--) {
            i64 now = abs (X - ns[j].x) + ns[j].y;
            q.push (now);
            down_sum += now;

            if (q.size () > (k >> 1)) { down_sum -= q.top (); q.pop (); }

            if (q.size () >= (k >> 1)) { suf[j] = down_sum; }
            else { suf[j] = inf; } // 不能取 (ns[j] 不是中位数) (最后取不到 k 个)
        }
        
        i64 res = inf;
        if (k & 1) {
            for (int j = 2; j <= n - 1; j++) { res = std::min (res, pre[j - 1] + abs (X - ns[j].x) + suf[j + 1]); }
        } else {
            for (int j = 1; j <= n - 1; j++) { res = std::min (res, pre[j] + suf[j + 1]); }
        }
        ans = std::min (ans, res);

    }   

    std::cout << ans << "\n";

    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 1000005;

int n, m;
int a[maxn];

struct Query {
    int l, r;
    int id;
    int ans;

    friend bool operator < (Query x, Query y) {
        return x.r < y.r;
    }
};

std::vector <Query> qs;

inline bool sort_by_id (Query x, Query y) { return x.id < y.id; }

int tr[maxn];
inline int lowbit (int x) { return x & (-x); }

inline void _add (int pos, int val) { for (int i = pos; i <= n; i += lowbit (i)) { tr[i] += val; } }
inline void add (int l, int r, int val) { _add (l, val); _add (r + 1, -val); }

inline int query (int pos) { int res = 0; for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; } return res; }

int pre[maxn];

int main () {
	fastread
	
    std::cin >> n;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    std::cin >> m;

    for (int i = 1; i <= m; i++) {
        int l, r; std::cin >> l >> r;
        qs.push_back (Query { l, r, i, 0 });
    }

    std::sort (qs.begin (), qs.end ());

    int last_r = 0;

    for (auto& now : qs) {
        for (int i = last_r + 1; i <= now.r; i++) {
            add (pre[a[i]] + 1, i, 1);
            pre[a[i]] = i;
        }
        last_r = now.r;

        now.ans = query (now.l);
    }

    std::sort (qs.begin (), qs.end (), sort_by_id);

    for (auto now : qs) { std::cout << now.ans << "\n"; }

    return 0;
}

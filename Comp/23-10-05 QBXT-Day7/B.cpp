#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100005;

int n, Q;

int v[maxn], a[maxn];

struct Query {
    int V, r, t;    
    int id;
    
    friend bool operator < (Query a, Query b) {
        return a.r < b.r;
    }
};
vector<Query> qs;

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

namespace Task1 {

    const int maxn_task1 = 1005;

    Query curr;

    bool vis[maxn_task1];
    void dfs (int now, int sum) {
        if (sum + v[now] > curr.V) { cout << now << endl; return; }
        if (a[now] == 0) { cout << now << endl; return;  }

        vis[now] = true;

        vector<int> sons;

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (vis[t]) { continue; }
            sons.push_back (t);
        }
        sort (sons.begin(), sons.end());

        int t = sons[a[now] - 1];
        dfs (t, sum + v[now]);
    }   

    inline void solve () {
        for (auto now : qs) {
            curr = now;
            
            memset (vis, 0, sizeof(vis));
            int old_a = a[curr.r];
            
            a[curr.r] = curr.t;
            dfs (curr.r, 0);
            a[curr.r] = old_a;
        }
    }

}

// namespace Task2 {
//     int sum[maxn];

//     int chain[maxn], tot;

//     inline void buildChain () {
//         int start = 0;
//         for (int u = 1; u <= n; u++) {
//             int deg = 0;
//             for (int i = last[u]; i; i = es[i].pre) {
//                 int t = es[i].v;
//                 deg ++;
//             }

//             if (deg == 1) { start = u; break; }
//         }

//         int fa = 0, now = start, nxt = 0;
//         while (now) {
//             chain[++tot] = now;
//             nxt = 0;
//             for (int i = last[now]; i; i = es[i].pre) {
//                 int t = es[i].v;
//                 if (t == fa) { continue; }
//                 nxt = t;
//             }
//             fa = now;
//             now = nxt;
//         }
//     }

//     int sum[maxn];
//     inline void preProcess () {
//         for (int i = 1; i <= tot; i++) {
//             sum[i] = sum[i - 1] + a[chain[i]];
//         }
//     }

//     int ans[maxn];
//     inline void solve () {
//         buildChain ();
//         preProcess ();

//         sort (qs.begin(), qs.end());

//         int curr = 1;
//         int pos0 = 0; // 0的位置

//         for (auto q : qs) {
//             // 判断方向
//             bool flag = 0;
//             if (q.t == 1) {
//                 if (chain[q.r - 1] < chain[q.r + 1]) {
//                     flag = 0; // 左
//                 } else {
//                     flag = 1;
//                 }
//             } else if (q.t == 2) {
//                 if (chain[q.r - 1] < chain[q.r + 1]) {
//                     flag = 1; // 右
//                 } else {
//                     flag = 0;
//                 }
//             } else {
//                 ans[q.id] = q.t;
//                 continue;
//             }

//             if (flag) { continue; } // 现在只处理向左的

//             while (curr <= q.r) {
//                 if (a[chain[curr]] == 0) { pos0 = curr; }
//                 curr ++;
//             }   

//             int l = 1, r = q.tot;
//             int res = 0;
//             while (l <= r) {
//                 int mid = (l + r) >> 1;

//                 if (sum[q.r] - sum[mid - 1] == q.v) {
//                     res = mid;
//                     break;
//                 } else if (sum[q.r] - sum[mid - 1] > q.V) {
//                     l = mid + 1;
//                 } else {
//                     r = mid - 1;
//                 }
//             }

//             ans[q.id] = max (pos0, res);
//         }
    
//         curr = n;
//         pos0 = 0;
//         for (auto q : qs) {
//             bool flag = 0;
//             if (q.t == 1) {
//                 if (chain[q.r - 1] < chain[q.r + 1]) {
//                     flag = 0; // 左
//                 } else {
//                     flag = 1; // 右
//                 }
//             } else if (q.t == 2) {
//                 if (chain[q.r - 1] < chain[q.r + 1]) {
//                     flag = 1; // 右
//                 } else {
//                     flag = 0; // 左
//                 }
//             }

//             if (not flag) { continue; }

//             while (curr >= q.r) {
//                 if (a[chain[curr]] == 0) { pos0 = curr; }
//                 curr --;
//             }

//             int l = q.r, r = tot;
//             int res = 0;
//             while (l <= r) {

//             }
//         }
//     }

// }

int main () {

    cin >> n >> Q;

    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        addEdge (u, v);
        addEdge (v, u);
    }

    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> a[i];
    }

    while (Q--) {
        int V, r, t; cin >> V >> r >> t;
        qs.push_back ( Query { V, r, t } );
    }

    // if (n <= 1000 and Q <= 1000) {
        Task1::solve ();
    // } else {
    //     Task2::solve ();
    // }


    return 0;
} 
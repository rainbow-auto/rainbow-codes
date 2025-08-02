#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 105;
constexpr int maxm = (maxn * maxn) << 3;

int n, m;
int sx, sy, tx, ty;

bool a[maxn][maxn];

f64 req;

struct Edge {
    int u, v; 
    int pre; 
    f64 w;
} es[maxm];

int last[maxm], cnt;

inline void addEdge(int u, int v, f64 w) {
    es[++cnt] = Edge { u, v, last[u], w };
    last[u] = cnt;
}

struct Node {
    int id;
    f64 dis;

    friend bool operator < (Node a, Node b) {
        return a.dis > b.dis;
    }
};

f64 dis[maxm];
std::bitset<maxm> vis;
f64 dij(int S, int T) {
    std::fill(dis, dis + maxm, 1e18); dis[S] = 0;
    std::priority_queue<Node> q; q.push(Node { S, dis[S] });
    vis.reset();

    while (not q.empty()) {
        int now = q.top().id; q.pop();
        if (vis[now]) continue;
        vis.set(now);

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (dis[t] > dis[now] + es[i].w) {
                dis[t] = dis[now] + es[i].w;
                q.push(Node { t, dis[t] });
            }
        }
    }

    return dis[T];
}

namespace Task0 {
    inline int id(int i, int j) {
        return (i - 1) * m + j;
    }

    constexpr f64 eps = 1e-5;

    int llast[maxm];
    inline f64 chk(f64 w) {
        // db << "chk " << w << "\n";

        int ccnt = cnt;
        std::memcpy(llast, last, sizeof last);

        rep (i, 1, n) rep (j, 1, n) {
            if (a[i][j]) continue;
            if (not a[i + 1][j]) addEdge(id(i, j), id(i + 1, j), w);
            if (not a[i - 1][j]) addEdge(id(i, j), id(i - 1, j), w);
        }

        f64 dis = dij(id(sx, sy), id(tx, ty));

        // dbg(dis);

        std::memcpy(last, llast, sizeof last);
        cnt = ccnt;

        return dis;
    }

    inline void solve() {
        rep (i, 1, n) {
            rep (j, 1, n) {
                if (a[i][j]) continue;
                if (not a[i][j + 1]) addEdge(id(i, j), id(i, j + 1), 1);
                if (not a[i][j - 1]) addEdge(id(i, j), id(i, j - 1), 1);
            }
        }   

        f64 l = 0, r = 1e5;
        f64 ans = -1;
        while (r - l > eps) {
            f64 mid = (l + r) / 2;
            f64 dis = chk(mid);
            if (std::fabs(dis - req) < eps) {
                ans = mid;
                r = mid;
            } else if (dis > req) {
                ans = mid;
                r = mid;
            } else {
                l = mid;
            }
        }

        std::cout << std::fixed << std::setprecision(3) << ans << "\n";
    }
}

void solve() {
    std::cin >> n >> m;
    
    std::cin >> sx >> sy >> tx >> ty;

    std::memset(a, 1, sizeof a);
    rep (i, 1, n) rep (j, 1, m) {
        std::cin >> a[i][j];
    }

    std::cin >> req;

    Task0::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("msg")

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}

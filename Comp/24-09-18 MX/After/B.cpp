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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 1000005;
const i64 inf = 0x3f3f3f3f3f3f3f3f;

int n, m, A, B;

struct Edge {
    int u, v; 
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

inline void clear () {
    rep (i, 1, n) { last[i] = 0; }
    cnt = 0;
}

struct Node {
    int id;
    int dis;

    friend bool operator < (Node a, Node b) {
        return a.dis > b.dis;
    }
};

i64 w[maxn];

i64 lim[maxn];
i64 f[maxn];

bool vis[maxn];

void dij () {
    rep (i, 1, n) { memset (f + i, 0x3f, sizeof (f[i])); vis[i] = false; }
    f[1] = 0;
    std::priority_queue <Node> q;
    q.push (Node { 1, f[1] });

    int tot = 0;

    while (not q.empty ()) {
        int now = q.top ().id; q.pop ();

        if (vis[now]) { continue; }
        vis[now] = true;

        if (tot < f[now]) { f[now] = inf; continue; }
        ++tot;

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            
            i64 curr {0};
            if (A <= B) {
                curr = (f[now] + 1 <= lim[t]) ? f[now] + 1 : inf;
            } else {
                curr = std::max (f[now] + 1, lim[t]);
            }

            if (f[t] > curr) {
                f[t] = curr;
                q.push (Node { t, f[t] });
            }
        }
    }
}

inline i64 div_ceil (i64 x, i64 y) {
    return x / y + (x % y != 0); 
}

inline void solve () {
	std::cin >> n >> m >> A >> B;

    rep (i, 1, m) { 
        int u, v; std::cin >> u >> v; 
        addEdge (u, v); addEdge (v, u); 
    }

    rep (i, 1, n) { std::cin >> w[i]; w[i] += (i != 1) * B; }

    if (A > B) {
        rep (i, 1, n) { 
            if (w[i] < w[1]) { lim[i] = 1; }
            else { lim[i] = (w[i] - w[1]) / (A - B) + 2; }
        }
    } else if (A == B) {
        rep (i, 1, n) {
            lim[i] = w[i] < w[1] ? inf : 0;
        }
    } else {
        rep (i, 1, n) {
            if (w[1] > w[i]) {
                lim[i] = (w[1] - w[i] - 1) / (B - A) + 1;
            } else {
                lim[i] = 0;
            }
        }
    }

    dij ();
    if (f[n] == inf) { std::cout << "-1\n"; }
    else { std::cout << f[n] << "\n"; }

    clear ();
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    // freopen ("monster.in", "r", stdin);
    // freopen ("monster.out", "w", stdout);

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve ();
	}

	return 0;
}

#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

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

constexpr int maxn = 300005;

int n, m;

struct Edge {
    int u, v;
    int w;
    int pre;
} es[maxn << 1];
int last[maxn], cnt;

int deg[maxn];

inline void addEdge(int u, int v) {
    es[++cnt] = Edge { u, v, w, last[u] };
    last[u] = cnt;
    deg[v]++;
}

constexpr int inf = 0x3f3f3f3f;

struct Query {
    int s, t;
    int id;
} qs[maxn];

namespace Task2 {
    int T;
    int ans[maxn]

    std::pair<int, int> f[maxn];
    void dfs(int now, int fa) {
        if (deg[now] == 1) {
            f[now] = { 0, now };
            return;
        }

        f[now] = { inf, 0 };
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) continue;
            dfs(t, now);
            f[now] = std::min(f[now], {f[t].first + es[i].w, f[t].second});
        }
    }

    inline void solve(int _T) {
        rep (i, 1, n) ans[i] = 0;
        T = _T;
        dfs(T, 0);
        rep (i, 1, n) ans[f[now].second]++;
    }
}

namespace Task1 {
    inline void solve() {
        int lst = -1;
        rep (t, 1, q) {
            auto [s, t] = qs[t];
            if (t != lst) Task2::solve(lst = t);
            std::cout << Task2::ans[s] << "\n";
        }
    }
}

void solve() {
    std::cin >> n;
    rep (i, 1, n - 1) {
        int u, v; std::cin >> u >> v;
        int w; std::cin >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    std::cin >> q;
    rep (id, 1, q) {
        int s, t; std::cin >> s >> t;
        qs[t] = { s, t, id };
    }
}

bool MemED;
int main() {
	fastread
	// lookMem	

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

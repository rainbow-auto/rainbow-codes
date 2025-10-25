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

constexpr int maxn = 500005;

int n;
struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

std::pair<int, int> f[maxn];
void dfs1(int now, int fa) {
    f[now] = { 0, now };

    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa) continue;
        dfs1(t, now);
        f[now] = std::max(f[now], { f[t].first + 1, f[t].second });
    }
}

int ans[maxn];

void dfs2(int now, int fa) {
    ans[now] = f[now].second;
    
    // dbg(now);

    std::multiset<std::pair<int, int>> fts;
    fts.insert({0, now});
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        // dbg(t);
        fts.insert({f[t].first + 1, f[t].second});
    }

    // for (auto [x, y] : fts) db << x << " " << y << "\n";

    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa) continue;
        
        auto ft = f[t];
        auto fnow = f[now];

        fts.erase(fts.find({f[t].first + 1, f[t].second}));
        f[now] = *fts.rbegin();
        f[t] = std::max(f[t], {f[now].first + 1, f[now].second});
        dfs2(t, now);
        f[t] = ft;
        fts.insert({ft.first + 1, ft.second});
        f[now] = fnow;
    }
}

void solve() {
	std::cin >> n;
    rep (i, 1, n - 1) {
        int u, v; std::cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    dfs1(1, 0);
    // db << "init:\n";
    // rep (i, 1, n) db << f[i].first << " " << f[i].second << "\n";

    dfs2(1, 0);

    rep (i, 1, n) std::cout << ans[i] << "\n";
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

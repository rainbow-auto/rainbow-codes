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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 100005;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

int n, m;

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

std::vector<int> s[maxn];
int col[maxn], tot;
void dfs(int now) {
    s[tot].push_back(now);
    col[now] = tot;
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (col[t]) continue;
        dfs(t);
    }
}

inline void clr() {
    rep (i, 1, tot) s[i].clear();
    tot = 0;
    rep (i, 1, n) col[i] = 0;
    cnt = 0;
    rep (i, 1, n) last[i] = 0;
}

inline i64 dis(int x, int c) {
    auto it = std::lower_bound(s[c].begin(), s[c].end(), x);
    i64 res = inf;
    if (it != s[c].end()) res = std::min(res, i64((*it) - x));
    if (it != s[c].begin()) res = std::min(res, i64(x - (*std::prev(it))));
    return res * res;
}

void solve() {
    std::cin >> n >> m;
    rep (i, 1, m) {
        int u, v; std::cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }   
    
    rep (i, 1, n) {
        if (not col[i]) {
            tot++;
            dfs(i);
            std::sort(s[tot].begin(), s[tot].end());
        }
    }

    if (col[1] == col[n]) return std::cout << "0\n", void(0);

    i64 ans = inf;
    rep (c, 1, tot) {
        i64 dis1 = inf, disn = inf;
        for (auto x : s[c]) {
            dis1 = std::min(dis1, dis(x, col[1]));
            disn = std::min(disn, dis(x, col[n]));
        }

        ans = std::min(ans, dis1 + disn);
    }

    std::cout << ans << "\n";
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
        clr();
	}

	return 0;
}

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

constexpr int maxn = 200005;
constexpr int maxm = 1000005;

int n, k;

struct Edge {
    int u, v;
    i64 w;
    int pre;
} es[maxn << 1];
int last[maxn], cnt;

inline void addEdge(int u, int v, i64 w) {
    es[++cnt] = Edge { u, v, w, last[u] };
    last[u] = cnt;
}

int rt;
bool rmv[maxn];

int siz[maxn];
int mx[maxn];

int tot;
void get_rt(int now, int fa) {
    siz[now] = 1;
	mx[now] = 0;
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa) continue;
        if (rmv[t]) continue;
        get_rt(t, now);
        siz[now] += siz[t];
        mx[now] = std::max(mx[now], siz[t]);
    }
    mx[now] = std::max(mx[now], tot - siz[now]);
    if (mx[now] < mx[rt]) rt = now;
}

std::vector<std::pair<i64, int>> dis;
void dfs(int now, int fa, i64 disnow, int cntnow) {
	if (disnow > k) return;
    dis.push_back({disnow, cntnow});
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa) continue;
        if (rmv[t]) continue;
        dfs(t, now, disnow + es[i].w, cntnow + 1);
    }
}

std::vector<int> del;
int f[maxm];

int ans;
inline void calc(int now) {
    f[0] = 0;

    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (rmv[t]) continue;

        dfs(t, now, es[i].w, 1);
        for (auto [d, c] : dis) ans = std::min(ans, f[k - d] + c);

        for (auto [d, c] : dis) {
			f[d] = std::min(f[d], c);
			del.push_back(d);
        }

        dis.clear();
    }

    for (auto d : del) f[d] = 0x3f3f3f3f;
    del.clear();
}

void divide(int now) {
    rmv[now] = true;
    calc(now);
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (rmv[t]) continue;
        tot = siz[t];
        mx[rt] = 0x3f3f3f3f;
        get_rt(t, now);
        get_rt(rt, -1);
		divide(rt);
    }
}

void solve() {
    std::cin >> n >> k;
    rep (i, 1, n - 1) {
        int u, v; std::cin >> u >> v;
		u++, v++;
        i64 w; std::cin >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    mx[rt] = 0x3f3f3f3f;
    tot = n;
    get_rt(1, -1);
    get_rt(rt, -1);

    std::memset(&ans, 0x3f, sizeof ans);
    auto inf = ans;
    std::memset(f, 0x3f, sizeof f);
    divide(rt);

    if (ans == inf) std::cout << "-1\n";
    else std::cout << ans << "\n";
}   

bool MemED;
int main() {
	fastread
	// lookMem	

	db << "ok\n";

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

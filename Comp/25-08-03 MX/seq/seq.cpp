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

int n, m; 
int a[maxn];

int pre[maxn], nxt[maxn];
std::bitset<maxn> vis;

void solve() {
	std::cin >> n >> m;
    rep (i, 1, n) std::cin >> a[i];

    std::priority_queue<std::pair<i64, std::pair<int, int>>> q;
    rep (i, 1, n - 1) q.push({a[i] + a[i + 1], { i, i + 1 }});
    q.push({a[1] + a[n], { n, 1 }});

    rep (i, 1, n) pre[i] = (i - 1 - 1) % n + 1;
    rep (i, 1, n) nxt[i] = (i + 1 - 1) % n + 1;

    int tot = n - m + 1;
    while (tot) {
        i64 w = q.top().first;
        auto [u, v] = q.top().second; q.pop();
        if (vis[u] or vis[v]) continue;
        tot--;

        if (not tot) return std::cout << w << "\n", void(0);
        
        if (a[u] < a[v]) std::swap(u, v);

        int x = pre[u], y = nxt[u];
        nxt[x] = y;
        pre[y] = x;

        vis[u] = true;

        q.push({a[x] + a[y], {x, y}});
    }
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("seq")

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

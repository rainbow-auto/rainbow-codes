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

const int maxn = 200005;

int n;
struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

i64 dp[maxn][2];
i64 a[maxn];

i64 c;

void dfs (int now, int fa) {
    i64 mxt = 0;
    i64 tot = 0;

    dp[now][0] = 0;
    dp[now][1] = a[now];
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa) { continue; }

        dfs (t, now);

        dp[now][0] += std::max (dp[t][1], dp[t][0]);
        dp[now][1] += std::max (dp[t][1] - 2 * c, dp[t][0]);
    }
}

inline void solve () {
	std::cin >> n >> c;
    rep (i, 1, n) { std::cin >> a[i]; }
    
    rep (i, 1, n - 1) {
        int u, v; std::cin >> u >> v;
        addEdge (u, v); addEdge (v, u);
    }

    dfs (1, 0);

    std::cout << std::max ({ dp[1][0], dp[1][1], 0ll}) << "\n";

    cnt = 0;
    rep (i, 1, n) { last[i] = 0; }

}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve ();
	}

	return 0;
}

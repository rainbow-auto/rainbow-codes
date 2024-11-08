#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

const int maxn = 200005;
const i64 mod = 1e9 + 7;

inline i64 ksm (i64 a, i64 b) {
	i64 res = 1; a %= mod;
	while (b) {
		if (b & 1) { res *= a; res %= mod; }
		a *= a; a %= mod; b >>= 1;
	}
	return res;
}

int n, m;

struct Edge {
	int u, v;
	int pre;
	i64 w;
} es[maxn];

int last[maxn], cnt;

inline void addEdge (int u, int v, i64 w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

std::bitset <maxn> vis;

struct Node {
	int id;
	int dis;

	friend bool operator < (Node a, Node b) { return a.dis > b.dis; }
};

i64 pathcnt[maxn];
i64 f[maxn], g[maxn];

i64 dis[maxn];
void dij () {
	vis.reset ();
	memset (dis, 0x3f, sizeof (dis)); dis[1] = 0;

	std::priority_queue <Node> q;
	q.push (Node { 1, dis[1] });

	pathcnt[1] = 1;

	while (not q.empty ()) {
		int now = q.top ().id; q.pop ();
	
		if (vis[now]) { continue; }
		vis[now] = true;

		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;

			if (dis[t] == dis[now] + es[i].w) {
				pathcnt[t] += pathcnt[now];
				f[t] += pathcnt[now] + f[now];  f[t] %= mod;
				g[t] += pathcnt[now] + 2ll * f[now] + g[now]; g[t] %= mod;
			} else if (dis[t] > dis[now] + es[i].w) {
				dis[t] = dis[now] + es[i].w;
				q.push (Node { t, dis[t] });
				pathcnt[t] = pathcnt[now];
				f[t] = pathcnt[now] + f[now] % mod; f[t] %= mod;
				g[t] = pathcnt[now] + 2ll * f[now] % mod + g[now]; g[t] %= mod;
			}
		}
	}
}

bool MemED;
int main () {
	fastread
	// lookMem

	freopen ("bob.in", "r", stdin);	
	freopen ("bob.out", "w", stdout);	

	std::cin >> n >> m;

	rep (i, 1, m) { 
		int u, v, w; std::cin >> u >> v >> w; 
		addEdge (u, v, w);
	}

	dij ();

	i64 inv2 = ksm (2, mod - 2);

	i64 ans = 0;
	rep (i, 1, n) {
		ans += (f[i] * f[i] % mod - g[i] % mod + mod) % mod * inv2 % mod;
		ans %= mod;
	}
	
	std::cout << ans << "\n";

	return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using i64 = long long;

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxn = 1000005;
const int mod = 1e9 + 7;

int n, m;

i64 ksm (i64 a, i64 b) {
	i64 base = a;
	i64 res = 1;

	while (b) {
		if (b & 1) { res *= base; res %= mod; }
		base *= base; base %= mod;
		b >>= 1;
	}

	return res;
}

struct Graph {
	struct Edge {
		int u, v;
		int pre;
	} es[maxn << 1];

	int last[maxn], cnt;

	inline void addEdge (int u, int v) {
		es[++cnt] = Edge { u, v, last[u] };
		last[u] = cnt;
	}
} g, tr;

int stk[maxn], spos, ins[maxn];
int dfn[maxn], low[maxn], dpos;

int edcc[maxn], edcc_cnt;

void tarjan (int now, int fa) {
	stk[++spos] = now;
	dfn[now] = low[now] = ++dpos;

	for (int i = g.last[now]; i; i = g.es[i].pre) {
		int t = g.es[i].v;

		if (not dfn[t]) {
			tarjan (t, now);
			low[now] = std::min (low[now], low[t]);
		} else if (t != fa) {
			low[now] = std::min (low[now], dfn[t]);
		}
	}

	if (low[now] == dfn[now]) {
		edcc_cnt ++;
		int last = -1;
		do {
			last = stk[spos--];
			edcc[last] = edcc_cnt;
		} while (last != now);
	}
}

i64 E[maxn], V[maxn];

inline void get_tree () {
	for (int i = 1; i <= n; i++) {
		if (not dfn[i]) { tarjan (i, 0); }
	}

	for (int u = 1; u <= n; u++) {
		V[edcc[u]] ++;

		for (int i = g.last[u]; i; i = g.es[i].pre) {
			int v = g.es[i].v;

			if (edcc[u] != edcc[v]) { tr.addEdge (edcc[u], edcc[v]); }
			else { E[edcc[u]] ++; }
		}
	}

	// 无向边在E中会被计算两次
	for (int i = 1; i <= edcc_cnt; i++) { E[i] >>= 1; }
}

i64 ed[maxn]; // 子树中原图边总数
void dfs (int now, int fa) {
	ed[now] = E[now];
	for (int i = tr.last[now]; i; i = tr.es[i].pre) {
		int t = tr.es[i].v;

		if (t == fa) { continue; }	
		dfs (t, now);
		ed[now] += ed[t] + 1; 
	}
}

i64 f[maxn][2];

i64 ans;

void dp (int now, int fa) {
	for (int i = tr.last[now]; i ; i = tr.es[i].pre) {
		int t = tr.es[i].v;

		if (t == fa) { continue; }

		dp (t, now);

		// 此处使用的 f[now][0] 都是加入新子树之前的情况, 故后更新 f[now][0]
		f[now][1] = ((f[now][1] * ((f[t][0] * 2ll % mod + f[t][1]) % mod)) % mod  + (f[now][0] * f[t][1]) % mod) % mod;
		f[now][0] = (f[now][0] * ((2ll * f[t][0]) % mod)) % mod;
	}

	if (now == 1) { ans += f[now][1]; ans %= mod; }
	else { ans += f[now][1] * ksm (2, ed[1] - ed[now] - 1); ans %= mod; } // -1 : 不能选到父亲的边
}

int main () {
	fastread
	
	std::cin >> n >> m;

	for (int i = 1; i <= m; i++) { 
		int u, v; std::cin >> u >> v; 
		g.addEdge (u, v); g.addEdge (v, u); 
	}

	get_tree ();

	dfs (1, 0);

	for (int i = 1; i <= n; i++) {
		f[i][0] = ksm (2, E[i]); 
		f[i][1] = ksm (2, V[i] + E[i]) - f[i][0];
	}

	dp (1, 0);

	std::cout << ans << "\n";

	return 0;
}

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

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

struct FenwickTree {
	i64 tr[maxn];
	int siz;

	inline int lowbit (int x) { return x & (-x); }

	inline i64 query (int pos) { i64 res = 0; for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; } return res; }
	inline void modify (int pos, i64 val) { for (int i = pos; i <= siz; i += lowbit (i)) { tr[i] += val; } }
	inline void modify (int l, int r, i64 val) { modify (l, val); modify (r + 1, -val); }
} tr;

int n, q;
int val[maxn];

int dfn[maxn], dpos;
int dep[maxn], siz[maxn];
void dfs (int now, int fa) {
	dfn[now] = ++dpos;
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }

		dep[t] = dep[now] + 1;		
		dfs (t, now);
		siz[now] += siz[t];
	}
} 

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n >> q;
	rep (i, 1, n) { std::cin >> val[i]; }

	rep (i, 1, n - 1) { int u, v; std::cin >> u >> v; addEdge (u, v); addEdge (v, u); }

	dep[1] = 1;
	dfs (1, 0);
	tr.siz = dpos;

	while (q--) {
		int op; std::cin >> op;
		if (op == 1) {
			int u; std::cin >> u;
			i64 val; std::cin >> val;
			tr.modify (dfn[u], dfn[u] + siz[u] - 1, ((dep[u] & 1) ? -1ll : 1ll) * val);
		} else {
			int u; std::cin >> u;
			std::cout << val[u] + ((dep[u] & 1) ? -1ll : 1ll) * tr.query (dfn[u]) << "\n";
		}
	}

	return 0;
}

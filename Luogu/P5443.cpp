#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#define dbtest(x) if (not (x)) { std::cerr << "assertion " << (#x) << "failed\n"; }
#else
#define db(x) void (0);
#define dbline() void (0);
#define dbtest(x) void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 200005;

int n, m, q;
struct Edge {
	int t;

	int u, v;
	int w;

	int id;

	friend bool operator < (Edge x, Edge y) { return x.w > y.w; }
};
std::vector <Edge> es;

struct DSU {
	int fa[maxn];
	int siz[maxn];
	std::stack <int> stk;
	inline void init () { 
		rep (i, 1, n) { fa[i] = i; siz[i] = 1; } 
		while (not stk.empty ()) { stk.pop (); }
	}

	int find (int x) { return x == fa[x] ? x : find (fa[x]); }

	inline void merge (int u, int v) {
		u = find (u); v = find (v);
		if (u == v) { return; }
		if (siz[u] > siz[v]) { std::swap (u, v); }
		fa[u] = v; // 把 u 合并到 v 上
		siz[v] += siz[u];
		stk.push (u);
	}

	inline void pop () {
		int curr = stk.top (); stk.pop ();
		siz[fa[curr]] -= siz[curr]; fa[curr] = curr;
	}

	inline void back (int t) {
		while (stk.size () > t) { pop (); }
	}
} dsu;

int belong[maxn], tot;
inline void init () {
	int B = (int) sqrt (q) + 1;
	rep (i, 1, q) { belong[i] = (int) i / B + 1; }
	tot = belong[q];
}

struct Query {
	int t;
	int x, y;
};
std::vector <Query> ops[maxn][2];

int pos[maxn];

int ans[maxn];
inline void solve (int id) {
	std::sort (ops[id][1].begin (), ops[id][1].end (), [](Query a, Query b) -> bool { return a.y > b.y; });

	std::bitset <maxn> vis;
	std::map <int, std::vector <Edge>> curr_e;

	for (int i = 0; i < es.size (); i++) { pos[es[i].id] = i; }
	
	for (auto now : ops[id][0]) { 
		vis[now.x] = true; 
		if (not curr_e.count (now.x)) { curr_e[now.x].push_back (es[pos[now.x]]); }
		curr_e[now.x].push_back (Edge { now.t, es[pos[now.x]].u, es[pos[now.x]].v, now.y, now.x });
	}

	dsu.init ();

	int epos = 0;
	for (auto q : ops[id][1]) { // O (B)
		while (epos < es.size () and es[epos].w >= q.y) {
			if (not vis[es[epos].id]) { dsu.merge (es[epos].u, es[epos].v); }
			epos ++;
		}

		int last = dsu.stk.size ();

		// 均摊 O (B)
		for (auto now : curr_e) {
			if (now.second.empty ()) { continue; }
			int eid = now.first;
			Edge curr = now.second.front ();
			for (auto e : now.second) {
				if (q.t > e.t) { curr = e; }
			}
			if (curr.w >= q.y) { dsu.merge (curr.u, curr.v); }
		}
		
		ans[q.t] = dsu.siz[dsu.find (q.x)];

		dsu.back (last);
	}

	// modify
	for (auto now : ops[id][0]) { es[pos[now.x]].w = now.y; }
	std::sort (es.begin (), es.end ());
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n >> m;

	rep (i, 1, m) {
		int u, v, w; std::cin >> u >> v >> w;
		es.push_back (Edge { 0, u, v, w, i - 1 });
	}
	std::sort (es.begin (), es.end ());

	std::cin >> q;

	init ();
	rep (t, 1, q) {
		int op, x, y; std::cin >> op >> x >> y;
		if (op == 1) {
			ops[belong[t]][0].push_back (Query { t, x - 1, y });
		} else {
			ops[belong[t]][1].push_back (Query { t, x, y });
		}
	}

	rep (b, 1, tot) { solve (b); }

	// assert (0);

	rep (i, 1, q) { if (ans[i]) { std::cout << ans[i] << "\n"; } } 

	return 0;
}

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
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 500005;

int n, m, q;

bool ans[maxn];

struct Info {
	int a, b;

	inline void upd (Info rhs) {
		if (rhs.a > a) { a = rhs.a; }
		if (rhs.b > b) { b = rhs.b; }
	}

	friend bool operator < (Info x, Info y) {
		return x.a < y.a;
	}

	friend bool operator == (Info x, Info y) {
		return x.a == y.a and x.b == y.b;
	}
};

struct Query {
	Info info;
	int u, v;

	int id;

	friend bool operator < (Query x, Query y) { return x.info < y.info; } 

} qs[maxn];

struct DSU {
	Info mx[maxn];
	int fa[maxn];

	inline void init () {
		rep (i, 1, n) { fa[i] = i; mx[i] = Info { -1, -1 }; }
	}

	int find (int x) {
		if (fa[x] == x) { return x; }
		else { return fa[x] = find (fa[x]); }
	}

	inline void merge (int u, int v, Info info) {
		u = find (u); v = find (v);
		if (u != v) {
			fa[u] = v;
			mx[v].upd (mx[u]);
		}
		mx[v].upd (info);
	}
} dsu;

std::vector < std::pair <int, Info> > g[maxn];

struct Edge {
	int u, v;
	Info w;

	friend bool operator < (Edge x, Edge y) { return x.w < y.w; }
} es[maxn];

int e_belong[maxn], tot;
int R[maxn];
std::vector <Query> block_q[maxn];

inline void blocking () {
	int B = (double) 1.5 * m / sqrt (q) + 1;
	rep (i, 1, m) { 
		e_belong[i] = i / B + 1; 
		R[e_belong[i]] = es[i].w.a;
	}
	tot = e_belong[m];

	rep (i, 1, q) {
		int b = (std::upper_bound (R + 1, R + tot + 1, qs[i].info.a) - R);
		block_q[b].push_back (qs[i]);

		// int b = 1;
		// while (b + 1 <= tot and qs[i].info.a <= R[b]) { b ++; }
		// block_q[b].push_back (qs[i]);
	}
}

std::bitset <maxn> vis;
Info block_mx;
void dfs (int now) {
	// db (now);
	vis.set (now);
	block_mx.upd (dsu.mx[now]);
	for (auto t : g[now]) {
		block_mx.upd (t.second);
		if (vis[t.first]) { continue; }
		dfs (t.first);
	}
}

inline void solve (int id) {
	dsu.init ();

	std::vector <Edge> curr_e;
	std::vector <Edge> pre_e;
	rep (i, 1, m) {
		if (e_belong[i] > id) { break; }
		if (e_belong[i] == id) { curr_e.push_back (es[i]); }
		else { pre_e.push_back (es[i]); }
	}

	std::sort (pre_e.begin (), pre_e.end (), [](Edge x, Edge y) -> bool { return x.w.b < y.w.b; });
	std::sort (block_q[id].begin (), block_q[id].end (), [](Query x, Query y) -> bool { return x.info.b < y.info.b; });

	// for (auto e : pre_e) { std::cerr << e.u << " " << e.v << " " << e.w.a << " " << e.w.b << "\n"; }

	int epos = 0;
	for (auto qnow : block_q[id]) {
		// std::cerr << "id: " << id << "\n";
		// std::cerr << qnow.u << " " << qnow.v << " (" << qnow.info.a << ", " << qnow.info.b << ")" << "\n";
		std::set <int> nodes;

		while (epos < pre_e.size () and pre_e[epos].w.b <= qnow.info.b) {
			dsu.merge (pre_e[epos].u, pre_e[epos].v, pre_e[epos].w);
			// std::cerr << "merge " << pre_e[epos].u << " " << pre_e[epos].v << "\n";
			epos ++;
		}

		int curr_u = dsu.find (qnow.u);
		int curr_v = dsu.find (qnow.v);

		nodes.insert (curr_u);
		nodes.insert (curr_v);

		for (auto e : curr_e) {
			if (not (e.w.a <= qnow.info.a and e.w.b <= qnow.info.b)) { continue; }

			int u = dsu.find (e.u); nodes.insert (u);
			int v = dsu.find (e.v); nodes.insert (v);

			g[u].push_back (std::pair { v, e.w });
			g[v].push_back (std::pair { u, e.w });
		}

		vis.reset ();
		block_mx = Info { -1, -1 };
		dfs (curr_u);
		bool connected = vis[curr_v];

		if (connected and block_mx == qnow.info) { ans[qnow.id] = true; }

		for (auto x : nodes) { g[x].clear (); }
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n >> m;
	
	rep (i, 1, m) {
		int u, v, a, b; std::cin >> u >> v >> a >> b;
		es[i] = Edge { u, v, Info { a, b } };
	}

	std::sort (es + 1, es + m + 1);

	std::cin >> q;
	rep (i, 1, q) {
		int u, v, a, b; std::cin >> u >> v >> a >> b;
		qs[i] = Query { Info { a, b }, u, v, i };
	}

	std::sort (qs + 1, qs + q + 1);

	blocking ();

	rep (b, 1, tot + 1) { solve (b); }

	rep (i, 1, q) { std::cout << (ans[i] ? "Yes": "No") << "\n"; }

	return 0;
}

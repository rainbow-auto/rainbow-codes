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

const int maxn = 100005;

int n, m;
i64 a[maxn], b[maxn];

int fa[maxn];
inline void init () {
	rep (i, 1, n) { fa[i] = i; }
}

int find (int x) { return fa[x] == x ? x : fa[x] = find (fa[x]); }

inline void merge (int x, int y) {
	x = find (x); y = find (y);
	if (x == y) { return; }
	if (rand () & 1) { std::swap (x, y); }
	fa[x] = y;
}

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

std::array <int, maxn> last;
int cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

std::array <int, maxn> col;
std::set <int> ps;
std::bitset <maxn> vis;

bool dfs (int now, int colnow) {
	col[now] = colnow;
	ps.insert (now);

	bool res = true;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (vis[t]) {
			if (col[t] == colnow) { res = false; }
			continue;
		}
		vis.set (t);

		bool t_res = dfs (t, colnow * -1);
		res &= t_res;
	}

	return res;
}

std::array <i64, maxn> w;

inline void solve () {

	std::cin >> n >> m;
	rep (i, 1, n) { std::cin >> a[i]; }
	rep (i, 1, n) { std::cin >> b[i]; }

	// clear
	col.fill (0); w.fill (0);
	cnt = 0;
	rep (i, 1, n) { last[i] = 0; }
	vis.reset ();
	init ();

	std::vector <std::pair <int, int>> op1s;

	rep (i, 1, m) {
		int op, x, y; std::cin >> op >> x >> y;
		
		if (op == 1) {
			op1s.push_back ({ x, y });
		} else {
			merge (x, y);
		}
	}

	rep (i, 1, n) { w[find (i)] += a[i] - b[i]; }

	for (auto x : op1s) {
		int u = find (x.first);
		int v = find (x.second);
		addEdge (u, v);
		addEdge (v, u);
	}

	int tot = 0;
	rep (i, 1, n) {
		if (fa[i] != i) { continue; }
		if (vis[i]) { continue; }

		vis.set (i);

		ps.clear ();

		bool chk = dfs (i, 1);

		if (chk) {
			i64 lsum = 0, rsum = 0;
			for (auto x : ps) {
				lsum += 1ll * (col[x] == 1)  * w[x];
				rsum += 1ll * (col[x] == -1) * w[x];
			}

			if (lsum != rsum) { std::cout << "NO\n"; return; }
		} else {
			i64 sum = 0;
			for (auto x : ps) {
				sum += w[x];
			}

			if (sum & 1) { std::cout << "NO\n"; return; }
		}
	}

	std::cout << "YES\n";
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

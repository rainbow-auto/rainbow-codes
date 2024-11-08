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

const int maxn = 10005;

int n;
int a[maxn];

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
} org; 

namespace Task0 {
	std::bitset <maxn> added;

	bool g[maxn][maxn];

	inline int popcount (int S) {
		int res = 0; while (S) { res += bool (S & 1); S >>= 1; }
		return res;
	}

	struct Set {
		int fa[maxn];

		Set (int siz) { 
			rep (i, 1, siz) { fa[i] = i; }
		}	

		int find (int x) {
			if (fa[x] == x) { return x; }
			else { return fa[x] = find (fa[x]); }
		}

		inline void merge (int x, int y) {
			fa[find (x)] = find (y);
		}
	};

	inline int calc (int siz) {
		std::vector < std::pair <int, int> > es;
		rep (i, 1, (n << 1)) { 
			rep (j, i + 1, (n << 1)) { 
				if (g[i][j]) {
					es.push_back (std::pair <int, int> { i, j });
				} 
			} 
		}

		int cnt = 0;
		rep (S, 0, (1 << es.size ())) {
			if (popcount (S) != siz - 1) { continue; }

			Set s (n << 1);

			rep (i, 0, es.size () - 1) {
				if (S & (1 << i)) {
					s.merge (es[i].first, es[i].second);
				}
			}

			bool res = true;			

			int rt = -1;
			rep (i, 1, (n << 1)) {
				if (i > n and not added[i]) { continue; }
				if (rt == -1) { rt = s.find (i); continue; }

				int curr = s.find (i);
				if (curr != rt) { res = false; break; }
			}	

			cnt += res;
		}

		return cnt;
	}

	inline void display () {
		std::cerr << "new Graph\n";
		rep (i, 1, (n << 1)) {
			rep (j, 1, (n << 1)) {
				if (g[i][j]) {
					if (i > n) { std::cerr << i - n << "' "; }
					else { std::cerr << i << "  "; }
					
					if (j > n) { std::cerr << j - n << "' "; }
					else { std::cerr << j << "  "; }

					std::cerr << "\n";	
				}
			}
		}
		std::cerr << "\n";
	}

	inline void solve () {
		rep (i, 1, org.cnt) {
			int u = org.es[i].u;
			int v = org.es[i].v;
			g[u][v] = true;
			g[v][u] = true;
		}

		rep (id, 1, n - 1) {
			int now = a[id];

			for (int i = org.last[now]; i; i = org.es[i].pre) {
				int t = org.es[i].v;
				if (added[t]) { 
					g[now + n][t + n] = g[t + n][now + n] = true;  
					
					g[now][t + n] = g[t + n][now] = false;
				} else {
					g[now + n][t] = g[t][now + n] = true;
				}
			}
			added.set (now);
			added.set (now + n);

			std::cout << calc (n + id) << "\n";
		}
	}
}

bool MemED;
int main () {
	fastread
	// lookMem

	freopen ("tree.in", "r", stdin);	
	freopen ("tree.out", "w", stdout);	

	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		org.addEdge (u, v); org.addEdge (v, u);
	}

	rep (i, 1, n - 1) { std::cin >> a[i]; }

	Task0::solve ();

	return 0;
}

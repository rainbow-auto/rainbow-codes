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

const int maxn = 50005;

int n;

struct Edge {
	int u, v;
	i64 w;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v, i64 w) {
	es[++cnt] = Edge { u, v, w, last[u] };
	last[u] = cnt;
}

int m;
int armycnt[maxn];

int fa[maxn][20];
i64 w[maxn][20];
void tree_init (int now) {
	rep (i, 1, 16) {
		fa[now][i] = fa[fa[now][i - 1]][i - 1];
		w[now][i] = w[now][i - 1] + w[fa[now][i - 1]][i - 1];
	}

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa[now][0]) { continue; }

		fa[t][0] = now;
		w[t][0] = es[i].w;

		tree_init (t);
	}
}

std::bitset <maxn> mark;
bool dfs (int now) {	
	if (mark[now]) { return false; } // 控制好了
	int tot = 0;
	int siz = 0;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa[now][0]) { continue; }
		tot += dfs (t);
		siz ++;
	}
	if (not siz) { return true; }
	return tot > 0;
} 

struct Node {
	int id;
	i64 val;

	friend bool operator < (Node a, Node b) { return a.val < b.val; }
};

std::map <Node, int> val;
std::map <int, int> stay[maxn];

inline bool chk (i64 lim) {
	mark.reset ();
	val.clear ();
	for (int i = last[1]; i; i = es[i].pre) {
		int t = es[i].v;
		stay[t].clear ();
	}

	rep (now, 1, n) {
		if (not armycnt[now]) { continue; }

		i64 rest = lim;
		int curr = now;
		per (i, 16, 0) {
			if (fa[curr][i] > 1 and rest - w[curr][i] >= 0) { 
				rest -= w[curr][i];
				curr = fa[curr][i]; 
			}
		}		

		if (fa[curr][0] == 1 and rest - w[curr][0] > 0) {
			rest -= w[curr][0];
			stay[curr][rest] += armycnt[now];
			val[Node { curr, rest }] += armycnt[now];
		} else { mark.set (curr); }
	}

	std::priority_queue <Node> req;
	for (int i = last[1]; i; i = es[i].pre) {
		int t = es[i].v;
		
		if (not dfs (t)) { continue; }
		req.push ({ t, es[i].w });
	}

	while (not req.empty ()) {
		auto curr = req.top (); req.pop ();
		if (val.empty ()) { return false; }

		if (stay[curr.id].size ()) {
			auto bg = (*stay[curr.id].begin ()).first;

			auto t = Node { curr.id , bg };
			val[t] --; 
			if (not val[t]) { val.erase (t); } 
			
			stay[curr.id][bg] --; // 剩余最小的留在本节点
			if (not stay[curr.id][bg]) { stay[curr.id].erase (bg); }
		
		} else {
			auto it = val.lower_bound (curr);
			if (it == val.end ()) {
				return false; 
			} else {
				auto t = (*it).first;
				stay[t.id][t.val]--; if (not stay[t.id][t.val]) { stay[t.id].erase (t.val); }
				val[t]--; if (not val[t]) { val.erase (t); }
			}
		}
	}

	return true;
}

bool MemED;
int main () {
	fastread
	// lookMem

	i64 w_sum = 0;

	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		i64 w; std::cin >> w;
		addEdge (u, v, w); addEdge (v, u, w);
		w_sum += w;
	}

	std::cin >> m;
	rep (i, 1, m) { int id; std::cin >> id; armycnt[id] ++; }

	tree_init (1);

	i64 l = 0, r = w_sum;
	i64 res = -1;
	while (l <= r) {
		i64 mid = (l + r) >> 1;
		if (chk (mid)) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	std::cout << res << "\n";
	
	return 0;
}

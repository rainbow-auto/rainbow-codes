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

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int inf = 1e9;
const int maxn = 100005;
const int maxm = 200005;

namespace NetworkSimplex {
	typedef long long ll;
	
	struct Edge {
		int u, v;
		int pre;
		int flow;
		long long cost;
	} es[maxm];

	int last[maxn], cnt = 1;

	inline void _addEdge (int u, int v, int cap, long long cost) {
		es[++cnt] = Edge { u, v, last[u], cap, cost };
		last[u] = cnt;
	}

	inline void addEdge (int u, int v, int cap, long long cost) {
		_addEdge (u, v, cap, cost);
		_addEdge (v, u, 0, -cost);
	}

	int fa[maxn], faEdge[maxn];
	int mark[maxn], curTime = 1;

	void initTree (int now) {
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (not es[i].flow) { continue; }

			if (mark[t]) { continue; }
			mark[t] = 1;

			fa[t] = now;
			faEdge[t] = i;
			initTree (t);
		}
	}

	long long piCache[maxn];
	long long pi (int now) {
		if (mark[now] == curTime) { return piCache[now]; }
		mark[now] = curTime;
		return piCache[now] = es[faEdge[now]].cost +  pi(fa[now]);
 	}

	inline long long pushFlow (int eid) {
		++curTime; // 更新时间
		
		int root = es[eid].u; // 找根
		while (root) { mark[root] = curTime; root = fa[root]; }

		int lca = es[eid].v; // 找lca
		while (mark[lca] != curTime) { mark[lca] = curTime; lca = fa[lca]; }

		int minFlow = es[eid].flow;
		int delNode = 0;
		int flag = 2;
		vector <int> circle;

		for (int now = es[eid].u; now != lca; now = fa[now]) {
			int nowEdge = faEdge[now];
			circle.push_back (nowEdge);
			
			if (minFlow > es[nowEdge].flow) {
				minFlow = es[nowEdge].flow;
				flag = 0;
				delNode = now;
			}
		}

		for (int now = es[eid].v; now != lca; now = fa[now]) {
			int nowEdge = faEdge[now] ^ 1;
			circle.push_back (nowEdge);
			
			if (minFlow > es[nowEdge].flow) {
				minFlow = es[nowEdge].flow;
				flag = 1;
				delNode = now;
			}
		}
		
		circle.push_back (eid);

		long long cost = 0;
		for (auto now : circle) {
			es[now].flow -= minFlow;
			es[now ^ 1].flow += minFlow;
			cost += (long long)minFlow * es[now].cost;
		}

		if (flag == 2) { return cost; }
	
		eid = eid ^ flag;
		int u = es[eid].u;
		int v = es[eid].v;

		int lastNode = v;
		int lastEdge = eid;
		int nextNode = 0;
		for (int now = u; lastNode != delNode; now = nextNode) {
			nextNode = fa[now];
			mark[now] --;

			lastEdge ^= 1;
			swap (lastEdge, faEdge[now]);
			
			fa[now] = lastNode;
			lastNode = now;
		}

		return cost;
	}

	struct MCMF {
		int minCost, maxFlow;
	};

	inline MCMF simplex (int S, int T) {
		addEdge (T, S, inf, -inf);
		
		initTree (T);
		mark[T] = ++curTime;
		fa[T] = 0;

		long long cost = 0;
		while (true) {
			bool flag = false;

			for (int i = 2; i <= cnt; i++) {
				if (es[i].flow and (long long)es[i].cost + pi(es[i].u) - pi(es[i].v) < 0) {
					flag = true;
					cost += pushFlow (i);
				}
			}

			if (not flag) { break; }
		}

		int maxFlow = es[cnt].flow;
		int minCost = (long long)es[cnt].flow * inf + cost;

		return MCMF { minCost, maxFlow };
	}

	inline void clear () {
		cnt = 1; memset (last, 0, sizeof(last));
		curTime = 1; memset (mark, 0, sizeof(mark));
		memset (piCache, 0, sizeof(piCache));
	}
}

int n, A, B;
double p;
int m; // 离散化过的时间

struct Plane {
	int x;
	int s, t;
} a[maxn];

int pid[maxn], tid[maxn]; // 飞机节点 | 时间节点
int S, T;

int tot;
inline int newNode () { return ++tot; }

inline void buildGraph () {
	tot = 0;
	for (int i = 1; i <= m + 1; i++) { tid[i] = newNode (); }
	for (int i = 1; i <= n; i++) { pid[i] = newNode (); }
	S = newNode (), T = newNode ();

	for (int i = 1; i <= m; i++) { NetworkSimplex::addEdge (tid[i], tid[i + 1], A, 0); } // 只能挺A架
	
	for (int i = 1; i <= n; i++) { NetworkSimplex::addEdge (S, tid[a[i].s], 1, 0); }
	for (int i = 1; i <= n; i++) { NetworkSimplex::addEdge (pid[i], T, 1, 0); }
	
	for (int i = 1; i <= n; i++) {
		NetworkSimplex::addEdge (tid[a[i].s], pid[i], 1, a[i].x); // 没有在登机桥
		NetworkSimplex::addEdge (tid[a[i].t], pid[i], 1, 0); // 一直占用登机桥
		NetworkSimplex::addEdge (tid[a[i].s + 1], pid[i], 1, (int)floor(p * a[i].x + 1e-6)); // 登机的下一时刻离开登机桥
	}
}


inline void descrete () {
	vector <int> temp;
	for (int i = 1; i <= n; i++) {
		temp.push_back (a[i].s);
		temp.push_back (a[i].t);
	}
	sort (temp.begin (), temp.end ());
	m = unique (temp.begin (), temp.end ()) - temp.begin();

	for (int i = 1; i <= n; i++) {
		a[i].s = lower_bound (temp.begin (), temp.begin() + m, a[i].s) - temp.begin() + 1;
		a[i].t = lower_bound (temp.begin (), temp.begin() + m, a[i].t) - temp.begin() + 1;
	}
}

int sum[maxn];

bool check () {
	memset (sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++) {
		sum[a[i].s] ++;
		sum[a[i].t] --; // 左闭右开
	}
	for (int i = 1; i <= m; i++) { sum[i] += sum[i - 1]; }

	for (int i = 1; i <= m; i++) {
		if (sum[i] > A + B) { return false; }
	}

	return true;
}

int main () {
	fastread

	int c; cin >> c;
	while (c--) {
		NetworkSimplex::clear ();

		cin >> n >> A >> B;
		cin >> p;
		
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].s >> a[i].t;
		}
		
		descrete ();

		if (not check ()) { cout << "impossible" << endl; continue; }

		buildGraph ();

		auto res = NetworkSimplex::simplex (S, T);
		cout << res.minCost << endl;
	}

	return 0;
}

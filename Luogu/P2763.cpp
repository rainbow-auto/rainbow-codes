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

const int maxn = 1005;
const int maxk = 25;
const int maxm = 42045;

namespace Net {
	struct Edge {
		int u, v;
		int pre;
		int flow;
	} es[maxm];

	int last[maxn], cur[maxn], cnt;
	int S, T;

	inline void _addEdge (int u, int v, int cap) {
		es[++cnt] = Edge { u, v, last[u], cap };
		last[u] = cnt;
	}

	inline void addEdge (int u, int v, int cap) {
		_addEdge (u, v, cap);
		_addEdge (v, u, cap);
	}

	inline void clear () {
		cnt = 1;
		memset (last, 0, sizeof(last));
	}

	int dep[maxn];
	inline bool bfs () {
		memset (dep, 0, sizeof(dep)); dep[S] = 1;
		queue<int> q; q.push(S);

		while (not q.empty()) {
			int now = q.front(); q.pop();

			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				if (not es[i].flow) { continue; }
				if (dep[t]) { continue; }
				
				dep[t] = dep[now] + 1;
				q.push(t);
			}
		}

		return dep[T];
	}

	int dfs (int now, int now_flow) {
		if (now == T or not now_flow) { return now_flow; }

		int res = 0;
		for (int &i = cur[now]; i; i = es[i].pre) {
			int t = es[i].v;

			if (not es[i].flow) { continue; }
			if (dep[t] != dep[now] + 1) { continue; }
			
			int t_flow = dfs (t, min (now_flow, es[i].flow));
			if (t_flow) {
				es[i].flow -= t_flow;
				es[i ^ 1].flow += t_flow;
				now_flow -= t_flow;
				res += t_flow;

				if (not now_flow) { break; }				
			}
		}

		return res;
	}

	int dinic (int _s, int _t) {
		S = _s, T = _t;

		int max_flow = 0;
		while (bfs ()) {
			memcpy (cur, last, sizeof(last));

			max_flow += dfs (S, 0x3f3f3f3f);
		}

		return max_flow;
	}
}

int n, k;
vector<int> a[maxn]; // 每个问题对应的类型
int b[maxk]; // 每种类型需要的题的数量

int tot;
inline int newNode () { return ++tot; }

int S, T;
int pid[maxn], tid[maxk]; // problem id | type id
inline void buildGraph () {
	tot = 0;
	S = newNode (); T = newNode ();
	
	for (int i = 1; i <= n; i++) { pid[i] = newNode (); }
	for (int i = 1; i <= k; i++) { tid[i] = newNode (); }

	for (int i = 1; i <= n; i++) { Net::addEdge (S, pid[i], 1); }
	for (int i = 1; i <= k; i++) { Net::addEdge (tid[i], T, b[i]); }

	for (int i = 1; i <= n; i++) {
		for (auto t : a[i]) {
			Net::addEdge (pid[i], tid[t], 1);
		}
	}
}

inline void output () {
	vector<int> res[maxk]; // 每个类型对应题的编号 (结果)
	for (int u = 1; u <= n; u++) {
		for (int i = Net::last[pid[u]]; i; i = Net::es[i].pre) {
			int v = Net::es[i].v;
			if (Net::es[i].flow) { continue; }
			if (v >= tid[1] and v <= tid[k]) { res[v - tid[1] + 1].push_back(u); } // 是某种类型
		}
	}

	for (int i = 1; i <= k; i++) {
		cout << i << ": ";
		for (auto x : res[i]) { cout << x << " "; } cout << endl;
	}
}

int main () {
	fastread
	
	cin >> k >> n;

	int m = 0;
	for (int i = 1; i <= k; i++) { cin >> b[i]; m += b[i]; }

	for (int i = 1; i <= n; i++) {
		int p; cin >> p; 
		for (int j = 1; j <= p; j++) { int x; cin >> x; a[i].push_back(x); }
	}

	buildGraph ();
	int max_flow = Net::dinic(S, T);
	
	if (max_flow == m) { // 满流 (有解)
		output();
	} else {
		cout << "No Solution!" << endl;
	}

	return 0;
}

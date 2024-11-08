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

const int maxn = 55;
const int maxm = 885; // (20 * 20 + 20 + 20) * 2

int n, m;

namespace Net {
	struct Edge {
		int u, v;
		int pre;
		int flow;
	} es[maxm];

	int last[maxn], cur[maxn], cnt;
	int S, T;

	inline void init () {
		memset (last, 0, sizeof (last));
		cnt = 1;
	}

	inline void _addEdge (int u, int v, int cap) {
		es[++cnt] = Edge {u, v, last[u], cap};
		last[u] = cnt;
	}

	inline void addEdge (int u, int v, int cap) {
		_addEdge (u, v, cap);
		_addEdge (v, u, 0);
	}

	int dep[maxn];
	inline bool bfs () {
		queue<int> q; q.push(S);
		memset (dep, 0, sizeof (dep)); dep[S] = 1;

		while (not q.empty()) {
			int now = q.front(); q.pop();

			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				if (not dep[t] and es[i].flow) {
					dep[t] = dep[now] + 1;
					q.push(t);
				}
			}
		}

		return dep[T];
	}

	int dfs (int now, int now_flow) {
		if (now == T or not now_flow) { return now_flow; }

		int res = 0;
		for (int &i = cur[now]; i; i = es[i].pre) {
			int t = es[i].v;
			
			if (dep[t] != dep[now] + 1) { continue; }
			if (not es[i].flow) { continue; }

			int t_flow = dfs (t, min (es[i].flow, now_flow));

			if (t_flow) {
				es[i].flow -= t_flow;
				es[i ^ 1].flow += t_flow;
				now_flow -= t_flow;
				res += t_flow;
			}
		}

		return res;
	}

	void dinic (int _s, int _t) {
		S = _s, T = _t;
		while (bfs ()) {
			memcpy (cur, last, sizeof (cur));
			dfs (S, 0x3f3f3f3f);	
		}
	}
}

int Matrix[maxn][maxn];
inline void output (int curr) {
	memset (Matrix, 0, sizeof(Matrix));
	for (int u = 1; u <= n; u++) {
		for (int i = Net::last[u]; i; i = Net::es[i].pre) {
			int v = Net::es[i].v;
			if (v >= n and v <= n + m) {
				Matrix[u][v - n] = (19 - Net::es[i].flow) + 1; // 我们把 1~20 转化为了 0~19 所以要 +1
			}
		}
	}

	cout << "Matrix " << curr << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main () {
	fastread

	int T; cin >> T;
	int curr = 0;

	while (T--) {
		Net::init();
		
		cin >> n >> m;

		int S = n + m + 1, T = S + 1;
		int last;
		last = 0;
		for (int i = 1; i <= n; i++) {
			int now; cin >> now; 
			Net::addEdge (S, i, (now - last) - m);
			last = now;
		}

		last = 0;
		for (int i = 1; i <= m; i++) {
			int now; cin >> now;
			Net::addEdge (i + n, T, (now - last) - n);
			last = now;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				Net::addEdge (i, j + n, 19);
			}
		}

		Net::dinic (S, T);
		output (++curr);
	}

		
	return 0;
}

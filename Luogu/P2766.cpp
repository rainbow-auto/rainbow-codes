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
const int maxm = 50205;

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
		_addEdge (v, u, 0);
	}

	inline void clear () {
		cnt = 1;
		memset (last, 0, sizeof(last));
	}

	int dep[maxn];
	inline bool bfs () {
		memset (dep, 0, sizeof (dep)); dep[S] = 1;
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
		
			int t_flow = dfs (t, min(now_flow, es[i].flow));
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
		int ans = 0;
		while (bfs ()) {
			memcpy (cur, last, sizeof (last));
			ans += dfs (S, 0x3f3f3f3f);
		}
		return ans;
	}
}

struct Node {
	int x, y;
} ids[maxn];
int S, T;

int tot;
inline int newNode () { return ++tot; }

int n;
int a[maxn];
int dp[maxn];

inline void buildGraph (int s, bool flag = false) {
	tot = 0;
	for (int i = 1; i <= n; i++) { ids[i].x = newNode(); ids[i].y = newNode(); }
	S = newNode(), T = newNode();

	for (int i = 1; i <= n; i++) {
		Net::addEdge (ids[i].x, ids[i].y, (flag and (i == 1 or i == n)) ? 0x3f3f3f3f : 1);
	}

	for (int i = 1; i <= n; i++) {
		if (dp[i] == 1) { Net::addEdge (S, ids[i].x, (flag and (i == 1 or i == n)) ? 0x3f3f3f3f : 1); }
		if (dp[i] == s) { Net::addEdge (ids[i].y, T, (flag and (i == 1 or i == n)) ? 0x3f3f3f3f : 1); }
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] <= a[i] and dp[i] == dp[j] + 1) { Net::addEdge (ids[j].y, ids[i].x, 1); }
		}
	}
}

int main () {
	fastread

	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> a[i]; }

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] <= a[i]) { dp[i] = max(dp[i], dp[j] + 1); }
		}
	}

	int s = 0;
	for (int i = 1; i <= n; i++) { s = max (s, dp[i]); }
	cout << s << endl;

	if (s == 1) {
		cout << n << endl;
		sort (a + 1, a + n + 1);
		int ans = unique (a + 1, a + n + 1) - a - 1;
		cout << ans << endl;
		return 0;
	}

	Net::clear();
	buildGraph (s);
	int ans2 = Net::dinic(S, T);
	cout << ans2 << endl;

	Net::clear();
	buildGraph (s, true);
	int ans3 = Net::dinic(S, T);
	cout << ans3 << endl;

	return 0;
}

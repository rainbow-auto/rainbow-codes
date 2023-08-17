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

#define int long long

using namespace std;

const int maxn = 505;
const int maxm = 400005;
const int inf = 1e9;

int n, m;
int L, R;
int sumH[maxn], sumL[maxn];
int a[maxn][maxn];

inline void preProcess () {
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= m; j++) {
			sumH[i] += a[i][j];	
			sumL[j] += a[i][j];
		}		
	}
}

namespace Net {
	struct Edge {
		int u, v;
		int flow;
		int pre;
	} es[maxm];

	int S, T;	
	int in[maxn], out[maxn];
	int last[maxn], cur[maxn], cnt;

	inline void clear () {
		memset (in, 0, sizeof(in));
		memset (out, 0, sizeof(out));
		memset (last, 0, sizeof(last));
		cnt = 1;
	}

	inline void _addEdge (int u, int v, int cap) { 
		cnt ++;
		es[cnt] = Edge{u, v, cap, last[u]};
		last[u] = cnt;
	}

	inline void addEdge (int u, int v, int L, int R) {
		L = max (0ll, L);
		_addEdge(u, v, R - L); in[v] += L;
		_addEdge(v, u, 0); out[u] += L;
	}

	inline int Blance () {
		int outS = 0;
		for (int i = 1; i <= n + m + 1 + 1; i++) {
			int w = in[i] - out[i];
			if (w > 0) { addEdge(S, i, 0, in[i] - out[i]); outS += in[i] - out[i]; }
			else if (w < 0) { addEdge(i, T, 0, out[i] - in[i]); }
		}
		return outS;
	}

	int dep[maxn];
	inline bool bfs () {
		queue<int> q; q.push(S);
		memset(dep, 0, sizeof(dep)); dep[S] = 1;

		while (not q.empty()) {
			int now = q.front(); q.pop();
			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				if (es[i].flow and not dep[t]) {
					dep[t] = dep[now] + 1;
					q.push(t);
				}
			}
		}

		return dep[T];
	}

	int dfs (int now, int now_flow) {
		if (now == T) { return now_flow; }
		
		int res = 0;
		for (int &i = cur[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (not es[i].flow) { continue; }
			if (dep[t] != dep[now] + 1) { continue; }

			int t_flow = dfs (t, min(now_flow, es[i].flow));
			
			if (t_flow) {
				es[i].flow -= t_flow;
				es[i ^ 1].flow += t_flow;
				res += t_flow;
				now_flow -= t_flow;
				if (not now_flow) { return res; }
			}
		}

		return res;
	}

	inline bool Exist (int s, int t, int ss, int tt) {
		S = ss;
		T = tt;
		addEdge (t, s, 0, inf);
		int ans = Blance();
		
		while (bfs()) {
			memcpy (cur, last, sizeof(last));
			ans -= dfs(S, inf);
		}

		return ans == 0;
	}
}


bool check (int mid) {
	Net::clear();
	
	int s = n + m + 1, t = s + 1, ss = t + 1, tt = ss + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			Net::addEdge (i, j + n, L, R);
		}
	}

	for (int i = 1; i <= n; i++) { Net::addEdge (s, i, sumH[i] - mid, sumH[i] + mid); }
	for (int i = 1; i <= m; i++) { Net::addEdge (i + n, t, sumL[i] - mid, sumL[i] + mid); }

	return Net::Exist(s, t, ss, tt);
}

signed main () {
	fastread

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	preProcess();

	cin >> L >> R;
	
	int l = 0, r = 1e8;

	int ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	cout << ans << endl;

	return 0;
}

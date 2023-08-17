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

const int maxn = 105;
const int maxm = 2 * (105 * 105 + 5);

int n, m;

namespace Net {
	struct Edge {
		int u, v;
		int pre;
		int flow;
	} es[maxm];

	int cur[maxn], last[maxn], cnt;

	inline void _addEdge (int u, int v, int cap) {
		cnt ++;
		es[cnt] = Edge {u, v, last[u], cap};
		last[u] = cnt;
	}

	inline void addEdge (int u, int v, int cap) {
		_addEdge(u, v, cap);
		_addEdge(v, u, 0);
	}

	inline void clear () {
		cnt = 1;
		memset (last, 0, sizeof(last));
	}

	int S, T;

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
		if (now == T or now_flow == 0) { return now_flow; }
		int res = 0;
		for (int &i = cur[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (dep[t] != dep[now] + 1) { continue; }
			if (not es[i].flow) { continue; }

			int t_flow = dfs (t, min(now_flow, es[i].flow));
			if (t_flow) {
				es[i].flow -= t_flow;
				es[i ^ 1].flow += t_flow;
				now_flow -= t_flow;
				res += t_flow;
				
				if (not now_flow) { return res; }
			}
		}
		return res;
	}

	int dinic (int _s, int _t) {
		S = _s, T = _t;

		int ans = 0;
		while (bfs ()) {
			memcpy (cur, last, sizeof(last));
			ans += dfs (S, 0x3f3f3f3f);
		}

		return ans;
	}

	inline void output () {
		for (int i = 1; i <= m; i++) { if (dep[i]) { cout << i << " "; } } cout << endl;
		for (int i = 1; i <= n; i++) { if (dep[i + m]) { cout << i << " "; } } cout << endl;
	}
}

int main () {
	fastread
	
	Net::clear();

	cin >> m >> n;

	int S = m + n + 1, T = S + 1;
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		int w; cin >> w;
		Net::addEdge (S, i, w);
		sum += w;

		char tools[10000];
		memset(tools,0,sizeof tools);
		cin.getline(tools,10000);
		int ulen=0,tool;
		while (sscanf(tools+ulen,"%d",&tool)==1)//之前已经用scanf读完了赞助商同意支付该实验的费用
		{//tool是该实验所需仪器的其中一个      
			Net::addEdge (i, m + tool, 0x3f3f3f3f);
			//这一行，你可以将读进来的编号进行储存、处理，如连边。
			if (tool==0) 
				ulen++;
			else {
				while (tool) {
					tool/=10;
					ulen++;
				}
			}
			ulen++;
		}
	}

	for (int i = 1; i <= n; i++) {
		int e; cin >> e;
		Net::addEdge(i + m, T, e);
	}

	int ans = sum - Net::dinic(S, T);
	Net::output();
	cout << ans << endl;	

	return 0;
}

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

using std::cin;
using std::cout;

#define fastread std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

const int maxn = 20005;
const int maxm = 100005;

int n, m;

struct Edge {
	int u, v;
	int pre;
} es[maxm << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

inline void clear () {
	cnt = 0;
	memset (last, 0, sizeof (last));
}

int low[maxn], dfn[maxn], dpos;
bool cut[maxn];
void tarjan (int now, int fa) {
	low[now] = dfn[now] = ++dpos;
	
	int son = 0;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;

		if (not dfn[t]) {
			son ++;
			
			tarjan (t, now);
			low[now] = std::min (low[now], low[t]);
			
			if (low[t] >= dfn[now]) { cut[now] = true; }
		} else if (t != fa) {
			low[now] = std::min (low[now], dfn[t]);
		}
	}

	if (fa == 0 and son < 2) { cut[now] = false; }
}

int main () {
	fastread

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;

		addEdge (u, v);
		addEdge (v, u);
	}

	for (int i = 1; i <= n; i++) {
		if (not dfn[i]) { tarjan (i, 0); }
	}

	int tot = 0;
	for (int i = 1; i <= n; i++) { tot += cut[i]; }

	cout << tot << endl;
	for (int i = 1; i <= n; i++) { if (cut[i]) { cout << i << " "; } }

	return 0;
}

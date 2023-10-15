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

const int maxn = 2000005;

int n, m;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int low[maxn], dfn[maxn], dpos;
int stk[maxn], spos;
bool ins[maxn];

int scc[maxn], scc_cnt;

void tarjan (int now) {
	low[now] = dfn[now] = ++dpos;
	stk[++spos] = now;
	ins[now] = true;

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;

		if (not dfn[t]) {
			tarjan (t);
			low[now] = std::min (low[now], low[t]);
		} else if (ins[t]) {
			low[now] = std::min (low[now], dfn[t]);
		}
	}

	if (low[now] == dfn[now]) {
		scc_cnt ++;

		int last = 0;
		while (last != now) {
			int top = stk[spos--];
			ins[top] = false;
			scc[top] = scc_cnt;	
			
			last = top;
		}
	}
}

bool check () {
	for (int i = 1; i <= n; i++) {
		if (scc[i] == scc[i + n]) { return false; }
	}
	return true;
}

int main () {
	fastread

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int a, va; cin >> a >> va;
		int b, vb; cin >> b >> vb;

		// a : a 取 0
		// a + n : a 取 1

		if (va == 0 and vb == 0) {
			addEdge (a + n, b);
			addEdge (b + n, a);
		} else if (va == 0 and vb == 1) {
			addEdge (a + n, b + n);
			addEdge (b, a);
		} else if (va == 1 and vb == 0) {
			addEdge (a, b);
			addEdge (b + n, a + n);
		} else if (va == 1 and vb == 1) {
			addEdge (a, b + n);
			addEdge (b, a + n);
		}
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (not dfn[i]) { tarjan (i); }
	}

	if (not check ()) { cout << "IMPOSSIBLE" << endl; return 0; }

	cout << "POSSIBLE" << endl;
	for (int i = 1; i <= n; i++) {
		if (scc[i] > scc[i + n]) { cout << 1 << " "; }
		else { cout << 0 << " "; }
	}

	return 0;
}

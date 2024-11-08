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

const int maxn = 32005;
const int maxm = 168005;

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
			scc[top] = scc_cnt;
			ins[top] = false;

			last = top;
		}
	}
}

inline bool check () {
	for (int i = 1; i <= (n << 1); i++) {
		if (scc[i] == scc[i + 2 * n]) { return false; }
	}
	return true;
}

int main () {
	fastread
	
	cin >> n >> m;

	// 钦定:
	// a : 在
	// a + 2 * n : 不在

	for (int i = 1; i <= n; i++) {
		int a = 2 * i;
		int b = 2 * i - 1;

		addEdge (a + 2 * n, b);
		addEdge (b + 2 * n, a);
		addEdge (a, b + 2 * n);
		addEdge (b, a + 2 * n);
	}

	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;

		addEdge (a, b + 2 * n);
		addEdge (b, a + 2 * n);
	}

	for (int i = 1; i <= (n << 2); i++) {
		if (not dfn[i]) { tarjan (i); }
	}

	if (not check ()) { cout << "NIE" << endl; return 0; }

	for (int i = 1; i <= (n << 1); i++) {
		if (scc[i] < scc[i + 2 * n]) { cout << i << endl; }
	}

	return 0;
}

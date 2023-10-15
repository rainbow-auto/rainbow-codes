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

const int maxn = 205;
const int maxm = 2005;

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

bool check () {
	for (int i = 1; i <= n; i++) {
		if (scc[i] == scc[i + n]) { return false; }
	}
	return true;
}

int main () {
	fastread

	int K; cin >> K;

	while (K--) {
		clear ();

		memset (dfn, 0, sizeof (dfn)); dpos = 0;
		scc_cnt = 0;

		cin >> n >> m;

		for (int i = 1; i <= m; i++) {
			char x; cin >> x;
			int xid; cin >> xid;

			char y; cin >> y;
			int yid; cin >> yid;

			// 钦定:
			// m : 0 : 1 ~ n
			// h : 1 : n + 1 ~ 2n

			if (x == 'm' and y == 'm') {
				addEdge (xid + n, yid);
				addEdge (yid + n, xid);
			} else if (x == 'm' and y == 'h') {
				addEdge (xid + n, yid + n);
				addEdge (yid, xid);
			} else if (x == 'h' and y == 'm') {
				addEdge (xid, yid);
				addEdge (yid + n, xid + n);
			} else if (x == 'h' and y == 'h') {
				addEdge (xid, yid + n);
				addEdge (yid, xid + n);
			}
		}

		for (int i = 1; i <= (n << 1); i++) {
			if (not dfn[i]) { tarjan (i); }
		}

		if (check ()) { cout << "GOOD" << endl; }
		else { cout << "BAD" << endl; }
	}	


	return 0;
}

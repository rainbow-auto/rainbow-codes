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

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 200005;

int C, T;

int n, m;

struct Edge {
	int u, v; 
	int w;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v, int w) {
	es[++cnt] = Edge { u, v, w, last[u] };
	last[u] = cnt;
}

int val[maxn];
int Tval, Fval, Uval;

inline bool isConstant (int x) { return x == Tval or x == Fval or x == Uval; }

int val_try[maxn];
int belong[maxn], tot;

int siz[maxn];
bool erase[maxn];

void dfs (int now) {
	belong[now] = tot;
	siz[belong[now]] ++;

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (belong[t]) { continue; }

		val_try[t] = val_try[now] * es[i].w;
		dfs (t);
	}
}

int eqcnt[maxn];
int all[maxn];

inline void clear () {
	cnt = 0;
	memset (last, 0, sizeof (last));
	tot = 0;
	memset (belong, 0, sizeof (belong));
	memset (siz, 0, sizeof (siz));
	memset (erase, 0, sizeof (erase));
	memset (val_try, 0, sizeof (val_try));

	memset (eqcnt, 0, sizeof (eqcnt));
	memset (all, 0, sizeof (all));

	for (int i = 1; i <= n; i++) { val[i] = i; }

	Tval = n + 1;
	Fval = -Tval;
	Uval = 0;
}

int main () {
	fastread
	
	std::cin >> C >> T;

	while (T--) {
		std::cin >> n >> m;

		clear ();

		for (int i = 1; i <= m; i++) {
			char c; std::cin >> c;
			if (c == 'T') { int x; std::cin >> x; val[x] = Tval; }
			if (c == 'F') { int x; std::cin >> x; val[x] = Fval; }
			if (c == 'U') { int x; std::cin >> x; val[x] = Uval; }
			if (c == '+') { int x, y; std::cin >> x >> y; val[x] = val[y]; }
			if (c == '-') { int x, y; std::cin >> x >> y; val[x] = -val[y]; }
		}

		for (int i = 1; i <= n; i++) {
			if (isConstant (val[i])) { continue; }

			if (val[i] > 0) { addEdge (i, val[i], 1); addEdge (val[i], i, 1); }
			if (val[i] < 0) { addEdge (i, -val[i], -1); addEdge (-val[i], i, -1); }
		}
		
		for (int i = 1; i <= n; i++) {
			if (not belong[i]) { tot ++; val_try[i] = Tval; dfs (i); }
		}

		for (int i = 1; i <= n; i++) {
			if (val[i] == Uval) { erase[belong[i]] = true; }
		}

		for (int now = 1; now <= n; now ++) {
			if (isConstant (val[now])) { continue; }

			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				if (val_try[t] != val_try[now] * es[i].w) { erase[belong[now]] = true; break; }
			}
		}

		for (int i = 1; i <= n; i++) {
			if (not isConstant (val[i])) { continue; }
			if (val[i] == Uval) { continue; }

			if (val_try[i] == val[i]) { eqcnt[belong[i]] ++; }
			all[belong[i]] ++;
		}

		for (int i = 1; i <= tot; i++) {
			if (eqcnt[i] != 0 and eqcnt[i] != all[i]) { erase[i] = true; }
		}

		int ans = 0;
		for (int i = 1; i <= tot; i++) {
			if (erase[i]) { ans += siz[i]; }
		}

		std::cout << ans << "\n";
	}	

	return 0;
}

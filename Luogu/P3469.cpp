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

const int maxn = 100005;
const int maxm = 500005;

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

unsigned long long ans[maxn];

int low[maxn], dfn[maxn], dpos;

int tarjan (int now, int fa) { // 返回siz
	low[now] = dfn[now] = ++dpos;

	int sons = 0;
	std::vector<int> cut_siz;
	int siz = 1;

	bool cut = false;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;

		if (not dfn[t]) {
			sons ++;

			int t_siz = tarjan (t, now);
			low[now] = std::min (low[now], low[t]);

			siz += t_siz;

			if (low[t] >= dfn[now]) {
				cut = true;
				cut_siz.push_back (t_siz);
			}
		} else if (t != fa) {
			low[now] = std::min (low[now], dfn[t]);
		}
	}

	if (fa == 0 and sons < 2) { cut = false; }

	if (cut) {
		ans[now] = 0ull;

		int siz_sum = 0;
		for (auto i : cut_siz) { siz_sum += i; }
		cut_siz.push_back ( (n - 1) - siz_sum );

		for (auto i : cut_siz) { ans[now] += 1ull * i * ((n - 1) - i); }
		ans[now] += 2 * (n - 1);

	} else {
		ans[now] = 2 * (n - 1); // 有序对 * 2
	}

	return siz;
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

	for (int i = 1; i <= n; i++) { cout << ans[i] << endl; }
	
	return 0;
}

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

#include <bitset>

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 10005;

int n, m;

struct Query {
	int k;
	bool ans;
};

std::vector<Query> qs;

struct Edge {
	int u, v;
	int pre;
	int w;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v, int w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

int sum;
std::bitset<maxn> removed;

int root;
int maxpart[maxn];
int siz[maxn];

void getRoot (int now, int fa) {
	siz[now] = 1; 
	maxpart[now] = 0;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }
		if (removed[t])	{ continue; }

		getRoot (t, now);
		siz[now] += siz[t];
		maxpart[now] = std::max (maxpart[now], siz[t]);
	}
	maxpart[now] = std::max (maxpart[now], sum - siz[now]);
	if (maxpart[now] < maxpart[root]) { root = now; }
}

int disStack[maxn], dpos;
int removeStack[maxn], rpos;

int dis[maxn];
void getDis (int now, int fa) {
	disStack[++dpos] = dis[now];
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }
		if (removed[t]) { continue; }
		
		dis[t] = dis[now] + es[i].w;
		getDis (t, now);
	}
}

const int maxv = 100000005;
std::bitset<maxv> exist;

void solve (int now) {
	exist[0] = true;

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (removed[t]) { continue; }

		dis[t] = es[i].w;
		getDis (t, now);

		for (int j = 1; j <= dpos; j++) {
			for (auto &q : qs) {
				if (q.k - disStack[j] >= 0) { q.ans |= exist[q.k - disStack[j]]; }
			}
		}

		while (dpos) {
			int top = disStack[dpos--];
			exist[top] = true;
			removeStack[++rpos] = top;
		}
	}

	while (rpos) {
		int top = removeStack[rpos--];
		exist[top] = false;
	}
}

inline void divide (int now) {
	removed[now] = true;
	solve (now);

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (removed[t]) { continue; }



		sum = siz[t];
		maxpart[root] = 0x3f3f3f3f;
		getRoot (t, now);
		getRoot (root, now); // 实际上在getSiz

		divide (root);
	}
}

int main () {
	fastread

	std::cin >> n >> m;
	for (int i = 1; i <= n - 1; i++) {
		int u, v, w; std::cin >> u >> v >> w;
		addEdge (u, v, w); addEdge (v, u, w);
	}

	while (m--) {
		int k; std::cin >> k;
		qs.push_back ( Query { k, 0 } );
	}

	sum = n;
	maxpart[root] = 0x3f3f3f3f;
	getRoot (1, 0);
	getRoot (root, 0);

	divide (root);

	for (auto now : qs) { std::cout << (now.ans ? "AYE" : "NAY") << "\n"; }

	return 0;
}

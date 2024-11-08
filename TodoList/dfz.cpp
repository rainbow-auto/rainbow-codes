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

const int maxn = 40005;

struct Query {
	int ans;
	int k;
};

std::vector<Query> qs;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int sum;
std::bitset<maxn> removed;

int maxpart[maxn];
int siz[maxn];

int root;
void getRoot (int now, int fa) {
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (removed[t]) { continue; }
		if (t == fa) { continue; }

		getRoot (t, now);
		siz[now] += siz[t];

		maxpart[now] = std::max (maxpart[now], siz[now]);
	}
	
	maxpart[now] = std::max (maxpart[now], sum - siz[now]);

	if (maxpart[now] < maxpart[root]) { now = root; }
}

struct BIT {
	int tr[maxn];

	inline int lowbit (int now) { return x & (-x); }
	
	inline void add (int pos, int val) { for (int i = pos; i <= n; i += lowbit (i)) { tr[i] += val; } }
	inline void query (int pos) { int res = 0; for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; } }
} tr[maxn];

int main () {
	fastread
	
	return 0;
}

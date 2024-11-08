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

const int maxn = 10005;

int n, m;

struct Query {
	int k;
	int ans;
};

vector<Query> qs;

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

int sum; // 不算removed的 (当前处理的) 点数
bool removed[maxn];

int root;

int siz[maxn];
int maxpart[maxn];
void getRoot (int now, int fa) { // 找根 (重心)
	siz[now] = 1;
	maxpart[now] = 0;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (removed[t]) { continue; }
		if (t == fa) { continue; }

		getRoot (t, now);
		siz[now] += siz[t];

		maxpart[now] = max (maxpart[now], siz[t]);
	}

	maxpart[now] = max (maxpart[now], sum - siz[now]);
	if (maxpart[root] > maxpart[now]) { root = now; }
}

int removeStack[maxn], rtot;
int disStack[maxn], dtot;

int dis[maxn];
void getDis (int now, int fa) { // getDis (u) : 计算 u 为根的dis
	disStack[++dtot] = dis[now];
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;

		if (removed[t]) { continue; }
		if (t == fa) { continue; }

		dis[t] = dis[now] + es[i].w;
		getDis (t, now);
	}
}

const int maxv = 100000005;
bool exist[maxv];

void solve (int now) {
	exist[0] = true;

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (removed[t]) { continue; }
				
		dis[t] = es[i].w; // getdis 之前的初始化
		getDis (t, now);

		for (int j = 1; j <= dtot; j++) { // 枚举子树中的点
			for (auto &q : qs) {
				if (q.k - disStack[j] >= 0) { q.ans |= exist[q.k - disStack[j]]; }
			}
		}

		while (dtot) {
			int top = disStack[dtot--];
			exist[top] = true; // 标记
			removeStack[++rtot] = top; // 方便以后删除 (不用memset 1e8 大小的数组)
		}
	}

	// 删除exist
	while (rtot) {
		int top = removeStack[rtot--];
		exist[top] = false;
	}
}

void divide (int now) { // 分治..
	removed[now] = true;
	solve (now);

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (removed[t]) { return; }

		sum = siz[t];
		maxpart[root] = 0x3f3f3f3f; // 确保换根
		getRoot (t, now);
		getRoot (root, now); // 实际上是在 getSize

		divide (root);
	}
}

int main () {
	fastread

	cin >> n >> m;

	for (int i = 1; i <= n - 1; i++) {
		int u, v, w; cin >> u >> v >> w;
		addEdge (u, v, w);
		addEdge (v, u, w);
	}

	while (m --) {
		int k; cin >> k;
		qs.push_back ( Query { k, 0 } );
	}	

	sum = n;
	maxpart[root] = 0x3f3f3f3f;
	getRoot (1, 0);
	getRoot (root, 0); // 实际上是在 getSize

	divide (root);

	for (auto now : qs) {
		cout << (now.ans ? "AYE" : "NAY") << endl;
	}

	return 0;
}

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

const int maxn = 200005;

int n, m;

int to[maxn], pre[maxn], last[maxn];
int cnt;

inline void addEdge (int u, int v) {
	cnt ++;
	to[cnt] = v;
	pre[cnt] = last[u];
	last[u] = cnt;
}

namespace LCA {

	int siz[maxn], fa[maxn], son[maxn], dep[maxn];
	void tree_build (int now) {
		siz[now] = 1;
		son[now] = -1;

		int siz_t = 0;
		for (int i = last[now]; i; i = pre[i]) {
			int t = to[i];
			if (t == fa[now]) continue;
			
			fa[t] = now;
			dep[t] = dep[now] + 1;
			
			tree_build (t);

			siz[now] += siz[t];
			if (siz_t < siz[t]) {
				siz_t = siz[t];
				son[now] = t;
			}
		}
	}

	int top[maxn];
	void tree_decomp (int now, int topnow) {
		top[now] = topnow;

		if (son[now] == -1) {
			return;
		}

		tree_decomp (son[now], topnow);

		for (int i = last[now]; i; i = pre[i]) {
			int t = to[i];
			if (t == son[now]) continue;
			if (t == fa[now]) continue;

			tree_decomp (t, t);
		}
	}	

	inline int lca (int a, int b) {
		while (top[a] != top[b]) {
			if (dep[top[a]] > dep[top[b]]) {
				a = fa[top[a]];
			} else {
				b = fa[top[b]];
			}
		}
		return dep[a] < dep[b] ? a : b;
	}

	inline void init () {
		tree_build (1);
		tree_decomp (1, 1);	
	}
}

namespace SegTree {

	struct Data {
		int cnt;
		int id;
		
		friend bool operator < (Data a, Data b) {
			if (a.cnt != b.cnt) {
				return a.cnt < b.cnt;
			} else {
				return a.id > b.id; // 相同数量选最小编号的
			}
		}
	};

	struct Node {
		int lc, rc;
		Data val;
	};

	int root[maxn];

	Node tr[maxn * 70]; // 这里需要奇妙的空间复杂度分析
	int cnt = 0;

	void change (int& now, int l, int r, int pos, Data val) {
		if (not now) {
			now = ++cnt;
		}
		
		if (l == r) {
			tr[now].val.cnt += val.cnt;
			tr[now].val.id = val.id;
			return ;
		}
		
		int mid = (l + r) >> 1;
		if (pos <= mid) {
			change (tr[now].lc, l, mid, pos, val); 
		} else {
			change (tr[now].rc, mid + 1, r, pos, val);
		}
		
		tr[now].val = max (tr[tr[now].lc].val, tr[tr[now].rc].val);
	}

	void merge (int& x, int y, int l, int r) {
		if (not x or not y) {
			x |= y;
		} else if (l == r) { // 已经是叶子节点
			tr[x].val.cnt += tr[y].val.cnt;
			return ;
		} else { // 分成两半分别合并
			int mid = (l + r) >> 1;
			merge (tr[x].lc, tr[y].lc, l, mid);
			merge (tr[x].rc, tr[y].rc, mid + 1, r);
			tr[x].val = max (tr[tr[x].lc].val, tr[tr[x].rc].val);
		}
	}	
}

int ans[maxn];
void getAnswer (int now) {
	for (int i = last[now]; i; i = pre[i]) {
		int t = to[i];
		if (t == LCA::fa[now]) continue;
		
		getAnswer (t);
		
		SegTree::merge (SegTree::root[now], SegTree::root[t], 1, maxn);
	}

	ans[now] = SegTree::tr[SegTree::root[now]].val.id;
}

int main () {
	// fastread

	cin >> n >> m;

	for (int i = 1; i <= n - 1; i ++) {
		int u, v; cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
	}
	
	LCA::init();

	for (int i = 1; i <= m; i++) {
		int x, y, z; 
		cin >> x >> y >> z;

		int lca = LCA::lca (x, y);
		
		SegTree::change (SegTree::root[x], 1, maxn, z, SegTree::Data{1, z});
		SegTree::change (SegTree::root[y], 1, maxn, z, SegTree::Data{1, z});
		SegTree::change (SegTree::root[lca], 1, maxn, z, SegTree::Data{-1, z});
		SegTree::change (SegTree::root[LCA::fa[lca]], 1, maxn, z, SegTree::Data{-1, z});
	}

	getAnswer(1);

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}

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

const int maxn = 500005;
const int maxm = 1000005;

int n, q;

struct Edge {
	int u, v;
	int pre;
} es[maxm];
int last[maxn], cnt;

inline void addEdge (int u, int v) {
	cnt ++;
	es[cnt] = Edge { u, v, last[u] };
	last[u] = cnt;	
}

namespace TreeDecomp {
	int siz[maxn], fa[maxn], son[maxn], dep[maxn];
	void tree_build (int now, int father) {
		fa[now] = father;
		son[now] = -1;
		siz[now] = 1;

		int son_siz = 0;
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (t == father) { continue; }
			
			dep[t] = dep[now] + 1;
			fa[t] = now;

			tree_build(t, now);
			
			siz[now] += siz[t];
			if (son_siz < siz[t]) {
				son_siz = siz[t];
				son[now] = t;
			}
		}

		return;
	}

	int top[maxn];
	void tree_decomp (int now, int topnow) {
		top[now] = topnow;
		if (son[now] == -1) { return; }

		tree_decomp (son[now], topnow);
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (t == son[now] or t == fa[now]) { continue; }

			tree_decomp (t, t);
		} 
	}

	void init () {
		tree_build (1, 0);
		tree_decomp (1, 1);
	}

	inline int lca (int a, int b) {
		while (top[a] != top[b]) {
			// cout << "xxxxxx" << endl;
			if (dep[top[a]] > dep[top[b]]) {
				a = fa[top[a]];
			} else {
				b = fa[top[b]];
			}
		}
		return dep[a] < dep[b] ? a : b;
	}

	inline int dis (int a, int b) {
		return dep[a] + dep[b] - 2 * dep[lca(a, b)];
	}
}

int main () {
	fastread

	cin >> n >> q;

	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
	}

	TreeDecomp::init();

	while (q--) {
		int a, b, c; cin >> a >> b >> c;
		int lcas[3];
		lcas[0] = TreeDecomp::lca(a, b); // cout << "lca " << a << " " << b << " = " << lcas[0] << endl;
		lcas[1] = TreeDecomp::lca(a, c); // cout << "lca " << a << " " << c << " = " << lcas[1] << endl;
		lcas[2] = TreeDecomp::lca(b, c); // cout << "lca " << b << " " << c << " = " << lcas[2]<< endl;
	
		int t = 0;
		if (lcas[1] == lcas[2]) { t = lcas[0]; } 
		if (lcas[0] == lcas[2]) { t = lcas[1]; } 
		if (lcas[0] == lcas[1]) { t = lcas[2]; }
		
		int dis = TreeDecomp::dis(a, t) + TreeDecomp::dis(b, t) + TreeDecomp::dis(c, t);

		cout << t << " " << dis << endl;
	}

	return 0;
}

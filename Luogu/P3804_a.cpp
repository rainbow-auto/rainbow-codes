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

const int maxn = 2000005;
const int maxm = 2000005;

struct Graph {
	struct Edge {
		int u, v;
		int pre;
	} es[maxm << 1];

	int last[maxn], cnt;

	Graph () { cnt = 0; memset (last, 0, sizeof (last)); }

	inline void addEdge (int u, int v) {
		es[++cnt] = Edge { u, v, last[u] };
		last[u] = cnt;
	}
};

Graph tr;

struct SAM {
	struct Node {
		int ch[26];
		int fa;
		int len;
	} ns[maxn];

	int last, root, tot;
	
	// 附加信息
	i64 cnt[maxn];

	SAM () { last = root = tot = 1; memset (cnt, 0, sizeof (cnt)); }

	inline void add (int c) {
		int p = last;
		int np = last = ++tot;

		ns[np].len = ns[p].len + 1;
		cnt[np] = 1;

		for (; p and not ns[p].ch[c]; p = ns[p].fa) { ns[p].ch[c] = np; }

		if (not p) { ns[np].fa = root; }
		else {
			int q = ns[p].ch[c];

			if (ns[q].len == ns[p].len + 1) { ns[np].fa = q; }
			else {
				int nq = ++tot;
				ns[nq] = ns[q]; ns[nq].len = ns[p].len + 1;
				ns[q].fa = ns[np].fa = nq;

				for (; p and ns[p].ch[c] == q; p = ns[p].fa) { ns[p].ch[c] = nq; }
			}
		}
	}	

	inline void getParentTree (Graph& tr) {
		for (int i = 2; i <= tot; i++) { tr.addEdge (ns[i].fa, i); }
	}
};

SAM sam;

i64 ans = 0ll;
void dfs (int now) {
	for (int i = tr.last[now]; i; i = tr.es[i].pre) {
		int t = tr.es[i].v;
		dfs (t);
		sam.cnt[now] += sam.cnt[t];
	}

	if (sam.cnt[now] != 1) { ans = std::max (ans, 1ll * sam.cnt[now] * sam.ns[now].len); }
}

int main () {
	fastread

	std::string s; std::cin >> s;
	for (auto c : s) { sam.add (c - 'a'); }
	sam.getParentTree (tr);

	dfs (sam.root);

	std::cout << ans << "\n";

	return 0;
}

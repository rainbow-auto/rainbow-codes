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
using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

const int maxn = 2000005;
const int maxm = 2000005;


struct Graph {
	struct Edge {
		int u, v;
		int pre;
	} es[maxm << 1];

	Graph () { cnt = 0; memset (last, 0, sizeof (last)); }

	int last[maxn], cnt;

	inline void addEdge (int u, int v) {
		es[++cnt] = Edge { u, v, last[u] };
		last[u] = cnt;
	}
};

Graph tr;

struct SAM {
	struct Node {
		int ch[26];
		int len, fa;
		
		Node () { len = fa = 0; memset (ch, 0, sizeof (ch)); }
	};

	SAM () { last = root = tot = 1; memset (cnt, 0, sizeof (cnt)); }

	Node ns[maxn];
	int root;
	int last, tot;
	i64 cnt[maxn];

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
				int nq = ++tot; // clone
				ns[nq] = ns[q]; ns[nq].len = ns[p].len + 1; 
				ns[q].fa = ns[np].fa = nq;

				for (; p and ns[p].ch[c] == q; p = ns[p].fa) { ns[p].ch[c] = nq; }
			}
		}
	}

	inline void buildParentTree (Graph& tr) {
		for (int i = 2; i <= tot; i++) { tr.addEdge (ns[i].fa, i); }
	}
};

SAM sam;

i64 ans = 0;
void dfs (int now) {
	for (int i = tr.last[now]; i; i = tr.es[i].pre) {
		int t = tr.es[i].v;
		dfs (t);
		sam.cnt[now] += sam.cnt[t];
	}

	if (sam.cnt[now] != 1) { ans = std::max (ans, 1ll * sam.ns[now].len * sam.cnt[now]); }
}		

int main () {
	fastread

	std::string s; cin >> s;
	for (auto c : s) { sam.add (c - 'a'); }
	sam.buildParentTree (tr);

	dfs (sam.root);

	cout << ans << endl;

	return 0;
}

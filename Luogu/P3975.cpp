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

const int maxn = 1000005;
const int maxm = 1000005;

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
} tr;

struct SAM {
	struct Node {
		int ch[26];
		int fa;
		int len;
	} ns[maxn];

	int last, tot, root;
	int cnt[maxn]; // 过点u的子串数
	int siz[maxn]; // endpos[u] 的 siz

	SAM () {
		last = tot = root = 1;
		memset (cnt, 0, sizeof (cnt));
		memset (siz, 0, sizeof (siz));
	}

	inline void add (int c) {
		int p = last;
		int np = last = ++tot;

		ns[np].len = ns[p].len + 1;
		cnt[np] = siz[np] = 1;

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

	inline void buildParentTree (Graph& tr) {
		for (int i = 2; i <= tot; i++) { tr.addEdge (ns[i].fa, i); }
	}
};

SAM sam;

void getSiz (int now) {
	for (int i = tr.last[now]; i; i = tr.es[i].pre) {
		int t = tr.es[i].v;
		getSiz (t);
		sam.siz[now] += sam.siz[t];
	}
}

bool vis[maxn];
void getCnt (int now) {
	if (vis[now]) { return; }
	vis[now] = true;

	for (int i = 0; i < 26; i++) {
		if (not sam.ns[now].ch[i]) { continue; }
		int t = sam.ns[now].ch[i];
		getCnt (t);
		sam.cnt[now] += sam.cnt[t];
	}
}

void query (int now, int k) {
	if (sam.cnt[now] < k) { std::cout << "-1\n"; return; }
	if (k - sam.siz[now] > 0) { k -= sam.siz[now]; }
	else { return; }

	for (int i = 0; i < 26; i++) {
		if (not sam.ns[now].ch[i]) { continue; }
		int t = sam.ns[now].ch[i];

		if (k - sam.cnt[t] > 0) { k -= sam.cnt[t]; }
		else { std::cout << char ('a' + i); query (t, k); return; }
	}
}

int main () {
	fastread

	std::string s; std::cin >> s;
	for (auto c : s) { sam.add (c - 'a'); }
	sam.buildParentTree (tr);
	
	int T, k; std::cin >> T >> k;
	if (T) { getSiz (sam.root); }
	else { for (int i = 1; i <= sam.tot; i++) { sam.siz[i] = 1; } }

	for (int i = 1; i <= sam.tot; i++) { sam.cnt[i] = sam.siz[i]; }
	
	sam.siz[sam.root] = sam.cnt[sam.root] = 0;
	getCnt (sam.root);

	query (sam.root, k);

	return 0;
}

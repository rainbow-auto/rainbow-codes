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

const int maxn = 30005;

int n, q;

struct Node {
	int sum, val;
	int ch[2], fa;
	bool tag;
} tr[maxn];

inline bool chk (int x) { return x == tr[tr[x].fa].ch[1]; }
inline bool notRoot (int x) { return x == tr[tr[x].fa].ch[0] or x == tr[tr[x].fa].ch[1]; }

inline void pushUp (int now) { tr[now].sum = tr[tr[now].ch[0]].sum + tr[tr[now].ch[1]].sum + tr[now].val; }

inline void rev (int now) { std::swap (tr[now].ch[0], tr[now].ch[1]); tr[now].tag ^= 1; }
inline void pushDown (int now) {
	if (not tr[now].tag) { return; }
	if (tr[now].ch[0]) { rev (tr[now].ch[0]); }
	if (tr[now].ch[1]) { rev (tr[now].ch[1]); }
	tr[now].tag = false;
}

void pushAll (int now) {
	if (notRoot (now)) { pushAll (tr[now].fa); }
	pushDown (now);
}

inline void connect (int f, int s, int p) { tr[f].ch[p] = s; tr[s].fa = f; }

inline void rotate (int x) {
	int f = tr[x].fa, ff = tr[f].fa, p = chk (x), pp = chk (f);
	pushDown (f); pushDown (x);
	if (notRoot (f)) { connect (ff, x, pp); }
	else { tr[x].fa = ff; }
	connect (f, tr[x].ch[p ^ 1], p); connect (x, f, p ^ 1);
	pushUp (f); pushUp (x);
}

inline void splay (int x) {
	pushAll (x);
	for (; notRoot (x); rotate (x)) {
		if (notRoot (tr[x].fa)) { rotate (chk (tr[x].fa) == chk (x) ? tr[x].fa : x); }
	}
	pushUp (x);
}

inline void access (int x) {
	int pre = 0;
	while (x) {
		splay (x); tr[x].ch[1] = pre; pushUp (x);
		x = tr[pre = x].fa;
	}
}

inline void makeRoot (int x) { access (x); splay (x); rev (x); }
inline void split (int x, int y) { makeRoot (x); access (y); splay (y); }

inline int findRoot (int x) {
	access (x); splay (x);
	pushDown (x); while (tr[x].ch[0]) { x = tr[x].ch[0]; pushDown (x); }
	splay (x); return x;
}

inline void link (int x, int y) { makeRoot (x); tr[x].fa = y; }

int main () {
	fastread

	std::cin >> n;

	for (int i = 1; i <= n; i++) { std::cin >> tr[i].val; }

	std::cin >> q;

	for (int i = 1; i <= q; i++) {
		std::string op; std::cin >> op;
		int u, v; std::cin >> u >> v;

		if (op[0] == 'b') {
			if (findRoot (u) == findRoot (v)) { std::cout << "no\n"; }
			else { std::cout << "yes\n"; link (u, v); }
		} else if (op[0] == 'p') {
			splay (u); tr[u].val = v; pushUp (u);
		} else if (op[0] == 'e') {
			if (findRoot (u) != findRoot (v)) { std::cout << "impossible\n"; }
			else { split (u, v); std::cout << tr[v].sum << "\n"; }
		}
	}

	return 0;
}

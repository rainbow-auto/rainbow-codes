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

const int maxn = 100005;

int n, m;
int a[maxn];

struct Node {
	int sum, val;
	int ch[2];
	int fa;
	bool tag;
} tr[maxn];

inline bool chk (int now) { return now == tr[tr[now].fa].ch[1]; }
inline bool notRoot (int now) { return now == tr[tr[now].fa].ch[0] or now == tr[tr[now].fa].ch[1]; }

inline void pushUp (int now) { tr[now].sum = tr[tr[now].ch[0]].sum xor tr[tr[now].ch[1]].sum xor tr[now].val; }

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

inline void connect (int fa, int x, int p) { tr[fa].ch[p] = x; tr[x].fa = fa; }

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
	access (x); splay (x); pushDown (x);
	while (tr[x].ch[0]) { x = tr[x].ch[0]; pushDown (x); }
	splay (x); return x;
}

inline void link (int x, int y) { 
	makeRoot (x); 
	if (x == findRoot (y)) { return; } 
	tr[x].fa = y;
}

inline void cut (int x, int y) { 
	split (x, y); 
	if (tr[y].ch[0] != x or tr[x].ch[0] != tr[x].ch[1]) { return; }
	tr[y].ch[0] = tr[x].fa = 0; 
	pushUp (y);
}

int main () {
	fastread
	
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { std::cin >> tr[i].val; }

	for (int i = 1; i <= m; i++) {
		int op, x, y; std::cin >> op >> x >> y;
		if (op == 0) { split (x, y); std::cout << tr[y].sum << "\n"; }
		if (op == 1) { link (x, y); }
		if (op == 2) { cut (x, y); }
		if (op == 3) { splay (x); tr[x].val = y; pushUp (x); }
	}	

	return 0;
}

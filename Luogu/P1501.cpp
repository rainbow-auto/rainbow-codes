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
const i64 mod = 51061;

int n, q;

struct Node {
	i64 val, sum;
	i64 add, mul;
	bool rev;

	int siz;

	int ch[2];
	int fa;

	Node () { val = 0; sum = 0; add = 0; mul = 1; rev = false; ch[0] = ch[1] = 0; fa = 0; }
} tr[maxn];

inline bool chk (int now) { return now == tr[tr[now].fa].ch[1]; }
inline bool notRoot (int now) { return now == tr[tr[now].fa].ch[0] or now == tr[tr[now].fa].ch[1]; }

inline void pushUp (int now) {
	tr[now].sum = tr[tr[now].ch[0]].sum + tr[tr[now].ch[1]].sum + tr[now].val; tr[now].sum %= mod;
	tr[now].siz = tr[tr[now].ch[0]].siz + tr[tr[now].ch[1]].siz + 1;
} 

inline void exec (int now, i64 k, i64 b) { // val => k * val + b
	tr[now].val = k * tr[now].val % mod + b % mod; tr[now].val %= mod;
	tr[now].sum = k * tr[now].sum % mod + b * tr[now].siz % mod; tr[now].sum %= mod;
	tr[now].add = k * tr[now].add % mod + b % mod; tr[now].add %= mod;
	tr[now].mul = k * tr[now].mul; tr[now].mul %=mod;
}

inline void rev (int now) {
	tr[now].rev ^= 1;
	std::swap (tr[now].ch[0], tr[now].ch[1]);
}

inline void pushDown (int now) {
	if (tr[now].rev) {
		if (tr[now].ch[0]) { rev (tr[now].ch[0]); }
		if (tr[now].ch[1]) { rev (tr[now].ch[1]); }
		tr[now].rev = false;
	}
	
	if (tr[now].mul != 1 or tr[now].add != 0) {
		if (tr[now].ch[0]) { exec (tr[now].ch[0], tr[now].mul, tr[now].add); }
		if (tr[now].ch[1]) { exec (tr[now].ch[1], tr[now].mul, tr[now].add); }
		tr[now].mul = 1; tr[now].add = 0;
	}
}

void pushAll (int now) {
	if (notRoot (now)) { pushAll (tr[now].fa); }
	pushDown (now);
}

inline void connect (int f, int s, int p) { tr[f].ch[p] = s; tr[s].fa = f; }

inline void rotate (int x) {
	int f = tr[x].fa, ff = tr[f].fa, p = chk (x), pp = chk (f);
	pushDown (f); pushDown (x);
	if (notRoot (f)) { connect (ff, x, pp); } else { tr[x].fa = ff; }
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
inline void cut (int x, int y) { split (x, y); tr[y].ch[0] = tr[x].fa = 0; pushUp (y); }

inline void displayTree () {
	std::cerr << "tree: \n";
	for (int i = 1; i <= n; i++) { std::cerr << tr[i].ch[0] << " " << tr[i].ch[1] << " " << tr[i].fa << "\n"; }
	std::cerr << "\n";
}

inline void displayValue () {
	std::cerr << "val: \n";
	for (int i = 1; i <= n; i++) { std::cerr << tr[i].val << " " << tr[i].sum << " " << tr[i].add << " " << tr[i].mul << "\n"; } 
	std::cerr << "\n";
}

int main () {
	fastread

	std::cin >> n >> q;

	for (int i = 1; i <= n; i++) { tr[i].val = 1; tr[i].siz = 1; }

	for (int i = 1; i <= n - 1; i++) { int u, v; std::cin >> u >> v; link (u, v); }

	for (int i = 1; i <= q; i++) {
		char op; std::cin >> op;
		int u, v; std::cin >> u >> v;
		if (op == '+') { i64 c; std::cin >> c; split (u, v); exec (v, 1, c); pushUp (v); }
		if (op == '-') { int u2, v2; std::cin >> u2 >> v2; cut (u, v); link (u2, v2); }
		if (op == '*') { i64 c; std::cin >> c; split (u, v); exec (v, c, 0); pushUp (v); }
		if (op == '/') { split (u, v); std::cout << tr[v].sum << "\n"; }
	}

	return 0;
}

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

#include <random>
#include <chrono>

using i64 = unsigned long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 100005;

int n, m;

struct Node {
	int ls, rs;
	int val;
	i64 key;
	int siz;

	bool tag;
} tr[maxn];

int tot, root;

std::mt19937 rnd (std::chrono::steady_clock::now().time_since_epoch().count());

inline int newNode (int val) {
	tr[++tot] = Node { 0, 0, val, rnd (), 1, false };
	return tot;
}

inline void pushUp (int now) {
	tr[now].siz = tr[tr[now].ls].siz + tr[tr[now].rs].siz + 1;
} 

inline void pushDown (int now) {
	if (tr[now].tag) { 
		std::swap (tr[now].ls, tr[now].rs); // 左儿子实际表示前, 右儿子实际表示后
		tr[tr[now].ls].tag ^= 1; tr[tr[now].rs].tag ^= 1;
		tr[now].tag = false;
	}
}

void split (int now, int siz, int& x, int& y) {
	if (not now) { x = 0; y = 0; return; }

	pushDown (now);

	if (siz <= tr[tr[now].ls].siz) {
		y = now; split (tr[now].ls, siz, x, tr[now].ls);
		pushUp (now);
	} else {
		x = now; split (tr[now].rs, siz - tr[tr[now].ls].siz - 1, tr[now].rs, y);
		pushUp (now);
	}
}

int merge (int x, int y) {
	if (not x or not y) {
		return x | y;
	} else if (tr[x].key < tr[y].key) {
		pushDown (x);
		tr[x].rs = merge (tr[x].rs, y);
		pushUp (x);
		return x;
	} else {
		pushDown (y);
		tr[y].ls = merge (x, tr[y].ls);
		pushUp (y);
		return y;
	}
}

inline void rev (int l, int r) {
	int x, y, z;
	split (root, r, x, z);
	split (x, l - 1, x, y);
	tr[y].tag ^= 1;	
	root = merge (merge (x, y), z);
}

void output (int now) {
	if (not now) { return; }

	pushDown (now);
	
	output (tr[now].ls);
	std::cout << tr[now].val << " ";
	output (tr[now].rs);
}

int main () {
	fastread

	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { root = merge (root, newNode (i)); }

	for (int i = 1; i <= m; i++) {
		int l, r; std::cin >> l >> r;
		rev (l, r);
	}
	
	output (root);

	return 0;
}

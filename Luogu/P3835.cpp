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

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 500005;

struct Node {
	int val;
	int ls, rs;
	int siz;

	unsigned long long key;
} tr[maxn * 50];

std::mt19937 rnd (std::chrono::steady_clock::now ().time_since_epoch ().count ());

int tot, root[maxn];

inline int newNode (Node old) {
	tr[++tot] = old;
	return tot;
}

inline void pushUp (int now) { tr[now].siz = tr[tr[now].ls].siz + tr[tr[now].rs].siz + 1; }

void split (int now, int val, int& x, int& y) {
	if (not now) { x = y = 0; return; }

	if (tr[now].val <= val) {
		int id = newNode (tr[now]);
		x = id; split (tr[id].rs, val, tr[id].rs, y);
		pushUp (id);
	} else {
		int id = newNode (tr[now]);
		y = id; split (tr[id].ls, val, x, tr[id].ls);
		pushUp (id);
	}
}

int merge (int x, int y) {
	if (not x or not y) { return x | y; }

	if (tr[x].key <= tr[y].key) {
		int id = newNode (tr[x]);
		tr[id].rs = merge (tr[id].rs, y);
		pushUp (id);
		return id;
	} else {
		int id = newNode (tr[y]);
		tr[id].ls = merge (x, tr[id].ls);
		pushUp (id);
		return id;
	}
}

inline void insert (int val, int i, int old) {
	root[i] = root[old];
	int x, y; split (root[i], val, x, y);
	root[i] = merge (merge (x, newNode ({ val, 0, 0, 1, rnd () })), y);
}

inline void remove (int val, int i, int old) {
	root[i] = root[old];
	int x, y; split (root[i], val, x, y);
	int z; split (x, val - 1, x, z);
	z = merge (tr[z].ls, tr[z].rs);
	root[i] = merge (merge (x, z), y);
}

inline int getRank (int val, int i, int old) {
	root[i] = root[old];
	int x, y; split (root[i], val - 1, x, y);
	int rank = tr[x].siz + 1;
	root[i] = merge (x, y);
	return rank;
}

inline int getNum (int rank, int i, int old) {
	root[i] = root[old];
	int now = root[i];
	while (now) {
		if (tr[tr[now].ls].siz + 1 == rank) { return tr[now].val; }

		if (rank <= tr[tr[now].ls].siz) { now = tr[now].ls; }
		else { rank -= tr[tr[now].ls].siz + 1; now = tr[now].rs; }
	}
}

inline int pre (int val, int i, int old) {
	root[i] = root[old];
	int x, y; split (root[i], val - 1, x, y);
	
	int now = x;
	while (tr[now].rs) { now = tr[now].rs; }
	root[i] = merge (x, y);
	return now ? tr[now].val : -2147483647;
}

inline int nxt (int val, int i, int old) {
	root[i] = root[old];
	int x, y; split (root[i], val, x, y);
	
	int now = y;
	while (tr[now].ls) { now = tr[now].ls; }
	root[i] = merge (x, y);
	return now ? tr[now].val : 2147483647;
}

int main () {
	fastread
	
	int q; std::cin >> q;

	for (int i = 1; i <= q; i++) {
		int old, op, x; std::cin >> old >> op >> x;

		if (op == 1) { insert (x, i, old); }
		if (op == 2) { remove (x, i, old); }
		if (op == 3) { std::cout << getRank (x, i, old) << "\n"; }
		if (op == 4) { std::cout << getNum (x, i, old) << "\n"; }
		if (op == 5) { std::cout << pre (x, i, old) << "\n"; }
		if (op == 6) { std::cout << nxt (x, i, old) << "\n"; }
	}	

	return 0;
}

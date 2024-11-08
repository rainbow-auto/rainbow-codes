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

#include <chrono>
#include <random>

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 1100005;

int n, m;

struct Node {
	int ls, rs;
	int val;
	int siz;

	unsigned long long key;
} tr[maxn];

int tot, root;

inline void pushUp (int now) { tr[now].siz = tr[tr[now].ls].siz + tr[tr[now].rs].siz + 1; }

std::mt19937 rnd (std::chrono::steady_clock::now ().time_since_epoch ().count ());

inline int newNode (int val) {
	tr[++tot] = Node { 0, 0, val, 1, rnd () };
	return tot;
}

void split (int now, int val, int& x, int& y) {
	if (not now) { x = y = 0; return; }
	
	if (tr[now].val <= val) {
		x = now; split (tr[now].rs, val, tr[now].rs, y); pushUp (now);
	} else {
		y = now; split (tr[now].ls, val, x, tr[now].ls); pushUp (now);
	}
}

int merge (int x, int y) {
	if (not x or not y) { return x | y; }

	if (tr[x].key < tr[y].key) {
		tr[x].rs = merge (tr[x].rs, y); pushUp (x);
		return x;
	} else {
		tr[y].ls = merge (x, tr[y].ls); pushUp (y);
		return y;
	}
}

inline void insert (int val) {
	int x, y; split (root, val, x, y);
	root = merge (merge (x, newNode (val)), y);
}

inline void remove (int val) {
	int x, y, z; 
	split (root, val, x, y); 
		split (x, val - 1, x, z);
	z = merge (tr[z].ls, tr[z].rs);
	root = merge (merge (x, z), y);
}

inline int getRank (int val) {
	int x, y; split (root, val - 1, x, y);
	int rank = tr[x].siz + 1;
	root = merge (x, y);
	return rank;
}

inline int getNum (int rank) {
	int now = root;
	while (now) {
		if (tr[tr[now].ls].siz + 1 == rank) { return tr[now].val; }
		else if (rank <= tr[tr[now].ls].siz) { now = tr[now].ls; }
		else { rank -= tr[tr[now].ls].siz + 1; now = tr[now].rs;  }
	}
}

inline int pre (int val) {
	int x, y; split (root, val - 1, x, y);
	int now = x;
	while (tr[now].rs) { now = tr[now].rs; }
	root = merge (x, y);
	return tr[now].val;
}	

inline int nxt (int val) {
	int x, y; split (root, val, x, y);
	int now = y;
	while (tr[now].ls) { now = tr[now].ls; }
	root = merge (x, y);
	return tr[now].val;
}

int main () {
	fastread

	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { int x; std::cin >> x; insert (x); }

	int ans = 0;

	int lastans = 0;
	while (m--) {
		int op, x; std::cin >> op >> x;
		x ^= lastans;

		if (op == 1) { insert (x); }		
		if (op == 2) { remove (x); }
		if (op == 3) { lastans = getRank (x); ans ^= lastans; }
		if (op == 4) { lastans = getNum (x); ans ^= lastans; }
		if (op == 5) { lastans = pre (x); ans ^= lastans; }
		if (op == 6) { lastans = nxt (x); ans ^= lastans; }
	}

	std::cout << ans << "\n";

	return 0;
}

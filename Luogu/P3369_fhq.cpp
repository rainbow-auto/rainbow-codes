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

const int maxn = 100005;

struct Node {
	int ls, rs;
	int val;
	int siz;
	unsigned long long key;
} tr[maxn];

int tot, root;

std::mt19937 rnd (std::chrono::steady_clock::now().time_since_epoch().count());

inline int newNode (int val) {
	tr[++tot] = Node { 0, 0, val, 1, rnd () };
	return tot;
}

inline void update (int now) {
	tr[now].siz = tr[tr[now].ls].siz + tr[tr[now].rs].siz + 1;
}

void split (int now, int val, int& x, int& y) {
	if (not now) { 
		x = 0; y = 0; 
	} else if (tr[now].val <= val) {
		x = now; split (tr[now].rs, val, tr[now].rs, y); update (now);
	} else {
		y = now; split (tr[now].ls, val, x, tr[now].ls); update (now);
	}
}

int merge (int x, int y) {
	if (not x or not y) { 
		return x | y; 
	} else if (tr[x].key < tr[y].key) {
		tr[x].rs = merge (tr[x].rs, y);
		update (x);
		return x;
	} else {
		tr[y].ls = merge (x, tr[y].ls);
		update (y);
		return y;
	}
}

inline void insert (int val) {
	int x, y; split (root, val, x, y);
	x = merge (x, newNode (val));
	root = merge (x, y);
}

inline void remove (int val) {
	int x, y, z;
	split (root, val, x, y);
	split (x, val - 1, x, z);
	z = merge (tr[z].ls, tr[z].rs);
	root = merge (merge (x, z), y);
}

inline int pre (int val) {
	int x, y;
	split (root, val - 1, x, y);
	
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
		else if (tr[tr[now].ls].siz >= rank) { now = tr[now].ls; }
		else { rank -= tr[tr[now].ls].siz + 1; now = tr[now].rs; }
	}

	return -1;
}

int main () {
	fastread
	
	int Q; std::cin >> Q;

	while (Q--) {
		int op, x; std::cin >> op >> x;

		if (op == 1) {
			insert (x);
		} else if (op == 2) {
			remove (x);
		} else if (op == 3) {
			std::cout << getRank (x) << "\n";
		} else if (op == 4) {
			std::cout << getNum (x) << "\n";
		} else if (op == 5) {
			std::cout << pre (x) << "\n";
		} else if (op == 6) {
			std::cout << nxt (x) << "\n";
		}
	}

	return 0;
}

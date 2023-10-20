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

const int maxn = 100005;

std::mt19937 rnd (std::chrono::steady_clock::now().time_since_epoch().count());

template <int maxn, typename val_t> 
struct FhqTreap {
	struct Node {
		int ls, rs;
		val_t val;
		unsigned long long key;
		int size;
	} tr[maxn];

	FhqTreap () { tot = 0; }
	

	int tot, root;
	inline int newNode (val_t val) {
		tr[++tot] = Node { 0, 0, val, rnd(), 1 };
		return tot;
	}

	inline void update (int now) {
		tr[now].size = tr[tr[now].ls].size + tr[tr[now].rs].size + 1;
	}

	void split (int now, val_t val, int &x, int &y) {
		if (not now) {
			x = y = 0; 
		} else if (tr[now].val <= val) {
			x = now; split (tr[now].rs, val, tr[now].rs, y);
			update (now);
		} else {
			y = now; split (tr[now].ls, val, x, tr[now].ls);
			update (now);
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
	
	inline void insert (val_t val) {
		int x, y; split (root, val, x, y);
		root = merge (merge (x, newNode (val)), y);
	}

	inline void remove (val_t val) {
		int x, y, z;
		split (root, val, x, y);
		split (x, val - 1, x, z);
		z = merge (tr[z].ls, tr[z].rs);
		root = merge (merge (x, z), y);
	}
	
	inline val_t pre (val_t val) {
		int x, y; split (root, val - 1, x, y);

		int now = x;
		while (tr[now].rs) { now = tr[now].rs; }
		
		root = merge (x, y);

		return tr[now].val;
	}

	inline val_t nxt (val_t val) {
		int x, y; split (root, val, x, y);

		int now = y;
		while (tr[now].ls) { now = tr[now].ls; }

		root = merge (x, y);

		return tr[now].val;
	}

	inline int get_rank (val_t val) {
		int x, y; split (root, val - 1, x, y);
		int res = tr[x].size + 1;
		root = merge (x, y);
		return res;
	}

	inline val_t get_val (int rank) {
		int now = root;
		while (now) {
			if (tr[tr[now].ls].size + 1 == rank) { return tr[now].val; }
			else if (tr[tr[now].ls].size >= rank) { now = tr[now].ls; }
			else { rank -= tr[tr[now].ls].size + 1; now = tr[now].rs; }
		}
		return -1;
	}
};

FhqTreap<maxn, int> tr;

int main () {
	fastread

	int n;
	std::cin >> n;

	while (n--) {
		int op, x; std::cin >> op >> x;

		if (op == 1) { tr.insert (x); }
		if (op == 2) { tr.remove (x); }
		if (op == 3) { std::cout << tr.get_rank (x) << "\n"; }
		if (op == 4) { std::cout << tr.get_val (x) << "\n"; }
		if (op == 5) { std::cout << tr.pre (x) << "\n"; }
		if (op == 6) { std::cout << tr.nxt (x) << "\n"; }
	}

	return 0;
}

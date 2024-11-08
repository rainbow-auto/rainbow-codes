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

const int maxn = 80005;
const int mod = 1000000;

std::mt19937 rnd (std::chrono::steady_clock::now ().time_since_epoch ().count ());

struct Tree {
	struct Node {
		int val;
		int ls, rs;
		int siz;
		unsigned long long key;
	} tr[maxn];

	int root, tot;


	inline int newNode (int val) {
		tr[++tot] = Node { val, 0, 0, 1, rnd () };
		return tot;
	}

	inline void pushUp (int now) { tr[now].siz = tr[tr[now].ls].siz + tr[tr[now].rs].siz + 1; }

	void split (int now, int val, int& x, int& y) {
		if (not now) { x = y = 0; return; }

		if (tr[now].val <= val) {
			x = now; split (tr[now].rs, val, tr[now].rs, y);
			pushUp (now);
		} else {
			y = now; split (tr[now].ls, val, x, tr[now].ls);
			pushUp (now);
		}
	}

	int merge (int x, int y) {
		if (not x or not y) { return x | y; }

		if (tr[x].key <= tr[y].key) {
			tr[x].rs = merge (tr[x].rs, y);
			pushUp (x);
			return x;
		} else {
			tr[y].ls = merge (x, tr[y].ls);
			pushUp (y);
			return y;
		}
	}

	inline void insert (int val) {
		int x, y; split (root, val, x, y);
		root = merge (merge (x, newNode (val)), y);
	}

	inline std::pair<int, int> pre (int val) {
		int x, y; split (root, val, x, y); // x : 小于等于
		int now = x;
		while (tr[now].rs) { now = tr[now].rs; }
		root = merge (x, y);
		return { tr[now].val, now };
	}

	inline std::pair<int, int> nxt (int val) {
		int x, y; split (root, val - 1, x, y); // y : 大于等于
		int now = y;
		while (tr[now].ls) { now = tr[now].ls; }
		root = merge (x, y);
		return { tr[now].val, now };
	}

	inline int near (int val) {
		auto x = pre (val);
		auto y = nxt (val);

		if (x.second == 0) { return y.first; } 
		if (y.second == 0) { return x.first; }

		if (val - x.first <= y.first - val) { return x.first; }
		else { return y.first; }
	}

	inline void remove (int val) {
		int x, y, z;
		split (root, val, x, y);
		split (x, val - 1, x, z);
		z = merge (tr[z].ls, tr[z].rs);
		root = merge (merge (x, z), y);
	}

	inline int siz () {
		return tr[root].siz;
	}
} tr[2];

int n;

int main () {
	fastread
	
	std::cin >> n;

	int res = 0;

	while (n--) {
		int op, x; std::cin >> op >> x;

		if (tr[op].siz () == 0 and tr[!op].siz () == 0) { tr[op].insert (x); continue; }

		if (tr[op].siz () == 0) {
			int val = tr[!op].near (x);
			res += abs (x - val); res %= mod;
			tr[!op].remove (val);
		} else {
			tr[op].insert (x);
		}
	}

	std::cout << res << "\n";

	return 0;
}

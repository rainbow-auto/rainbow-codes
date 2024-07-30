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

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxn = 100005;
const double eps = 1e-10;

struct FHQ {

	struct Node {
		int val;
		int siz;
		int ls, rs;
		unsigned long long key;
	} tr[maxn];

	int tot;
	int root;

	std::mt19937 rnd;
	inline int newNode (int val) {
		tr[++tot] = Node { val, 1, 0, 0, rnd () };
		return tot;
	}

	inline void pushUp (int now) { tr[now].siz = tr[tr[now].ls].siz + tr[tr[now].rs].siz + 1; }

	void split (int now, int val, int& x, int& y) {
		if (not now) { x = y = 0; return; }	

		if (tr[now].val <= val) {
			x = now;
			split (tr[now].rs, val, tr[now].rs, y);
			pushUp (x);
		} else {
			y = now;
			split (tr[now].ls, val, x, tr[now].ls);
			pushUp (y);
		}
	}

	int merge (int x, int y) {
		if (not x or not y) { return x + y; }
		if (tr[x].key > tr[y].key) {
			tr[x].rs = merge (tr[x].rs, y);
			pushUp (x);
			return x;
		} else {
			tr[y].ls = merge (x, tr[y].ls);
			pushUp (y);
			return y;
		}
	}

	inline void ins (int val) {
		int x, y; split (root, val, x, y);
		root = merge (merge (x, newNode (val)), y);
	}

	inline void del (int val) {
		// x : < val | z : = val | y : > val 
		int x, y, z; split (root, val - 1, x, y); split (y, val, z, y);
		z = merge (tr[z].ls, tr[z].rs);
		root = merge (merge (x, z), y);
	}

	int getLeq (int val) {
		int x, y; split (root, val, x, y);
		int res = tr[x].siz;
		root = merge (x, y);
		return res;
	}

	int getGeq (int val) {
		int x, y; split (root, val - 1, x, y);
		int res = tr[y].siz;
		root = merge (x, y);
		return res;
	}

} tr[2];

struct Inq {
	int val;
	bool exist;
	int pos; // 位于哪一棵树中
} inq[maxn];

int curr;

int main () {
	fastread

	int q; std::cin >> q;

	while (q--) {
		std::string op; std::cin >> op;

		if (op == "Add") {
			double a, b, c; std::cin >> a >> b >> c;
			if (a < eps and a > -eps) { 
				if (b > c) {
					int val = -1e9;
					tr[0].ins (val);
					inq[++curr] = Inq { val, true, 0 };
				} else {
					inq[++curr] = Inq { 0, false, 0 };
				}
			} else if (a > eps) {
				int val = floor ((c - b) / a) + 1;
				tr[0].ins (val);
				inq[++curr] = Inq { val, true, 0 };

			} else if (a < -eps) {
				int val = ceil ((c - b) / a) - 1;
				tr[1].ins (val);
				inq[++curr] = Inq { val, true, 1 };
			}
		} else if (op == "Del") {
			int i; std::cin >> i;
			if (not inq[i].exist) { continue; }
			inq[i].exist = false;
			tr[inq[i].pos].del (inq[i].val);
		} else if (op == "Query") {
			int x; std::cin >> x;

			std::cout << tr[0].getLeq (x) + tr[1].getGeq (x) << "\n"; 
		}
	}

	return 0;
}

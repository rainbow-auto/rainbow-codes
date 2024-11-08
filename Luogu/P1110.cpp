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

const int maxn = 1000005;

std::mt19937 rnd (std::chrono::steady_clock::now ().time_since_epoch ().count ());

struct Tree {
	struct Node {
		int val;
		int siz;
		int ls, rs;
		unsigned long long key;		
	} tr[maxn];

	int tot, root;

	inline int newNode (int val) {
		tr[++tot] = Node { val, 1, 0, 0, rnd () };
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

	inline void remove (int val) {
		int x, y, z; split (root, val, x, y); split (x, val - 1, x, z);
		z = merge (tr[z].ls, tr[z].rs);
		root = merge (merge (x, z), y);
	}

	inline int pre (int val) { // 非严格前驱 (<=)
		int x, y; split (root, val, x, y);
		int now = x;
		while (tr[now].rs) { now = tr[now].rs; }
		root = merge (x, y);
		return tr[now].val;
	}

	inline int nxt (int val) { // 非严格后继 (>=)
		int x, y; split (root, val - 1, x, y);
		int now = y;
		while (tr[now].ls) { now = tr[now].ls; }
		root = merge (x, y);
		return tr[now].val;
	}

	inline int getMin () {
		int now = root;
		while (tr[now].ls) { now = tr[now].ls; }
		return tr[now].val;
	}
} tr1, tr2;

int n, m;

struct Range {
	int front, back;
} r[maxn];

int a[maxn];
int ans = 0x3f3f3f3f;

int main () {
	fastread
	
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; tr1.insert (a[i]); r[i].front = r[i].back = a[i]; }
	for (int i = 2; i <= n; i++) { tr2.insert (abs (r[i].front - r[i - 1].back)); }
	std::sort (a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) { ans = std::min (ans, abs (a[i] - a[i - 1])); }
	
	for (int i = 1; i <= m; i++) {
		std::string op; std::cin >> op;

		if (op == "INSERT") {
			int x, k; std::cin >> x >> k;
			
			ans = std::min (ans, std::min (abs (k - tr1.pre (k)), abs (tr1.nxt (k) - k)));
			tr1.insert (k);
			
			if (x == n) { 
				tr2.insert (abs (k - r[n].back));
				r[n].back = k;
			} else {
				tr2.remove (abs (r[x + 1].front - r[x].back));
				tr2.insert (abs (r[x + 1].front - k));
				tr2.insert (abs (k - r[x].back));
				r[x].back = k;
			}

		} else if (op == "MIN_GAP") {
			std::cout << tr2.getMin () << "\n";
		} else {
			std::cout << ans << "\n";
		}
	}

	return 0;
}

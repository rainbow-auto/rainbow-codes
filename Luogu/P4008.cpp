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

inline int read () {
	char ch = getchar (); int f = 1;
	int res = 0;
	while (ch < '0' or ch > '9') { f = ch == '-' ? -1 : 1; ch = getchar (); }
	while (ch >= '0' and ch <= '9') { res = res * 10 + ch - '0'; ch = getchar (); }
	return res;
}

const int maxn = 1024 * 1024 * 2;

struct Node {
	char val;
	int siz;
	int ls, rs;
	unsigned long long key;
} tr[maxn];

std::mt19937 rnd (std::chrono::steady_clock::now ().time_since_epoch ().count ());

int root, tot;

inline int newNode (char val) {
	tr[++tot] = Node { val, 1, 0, 0, rnd () };
	return tot;
}

inline void pushUp (int now) { tr[now].siz = tr[tr[now].ls].siz + tr[tr[now].rs].siz + 1; }

void split (int now, int siz, int& x, int& y) {
	if (not now) { x = y = 0; return; }

	if (siz <= tr[tr[now].ls].siz) {
		y = now; split (tr[now].ls, siz, x, tr[now].ls);
		pushUp (now);
	} else {
		x = now; split (tr[now].rs, siz - tr[tr[now].ls].siz - 1, tr[now].rs, y);
		pushUp (now);
	}
}

int merge (int x, int y) {
	if (not x or not y) { return x | y; }

	if (tr[x].key < tr[y].key) {
		tr[x].rs = merge (tr[x].rs, y);
		pushUp (x);
		return x;
	} else {
		tr[y].ls = merge (x, tr[y].ls);
		pushUp (y);
		return y;
	}
}

void output (int now) {
	if (not now) { return; }

	output (tr[now].ls);
	std::cout << tr[now].val;
	output (tr[now].rs);
}

int main () {
	// fastread

	int T = read ();

	int pos = 1;

	while (T--) {
		std::string op; std::cin >> op;

		if (op[0] == 'M') {
			int k = read (); pos = k + 1;
		} else if (op[0] == 'I') {
			int len = read (); 
			int x, y; split (root, pos - 1, x, y);

			for (int i = 1; i <= len; i++) { 
				char c = getchar (); 
				while (c < 32 or c > 126 or c == '\r' or c == '\n') { c = getchar (); }
				x = merge (x, newNode (c)); 
			}

			root = merge (x, y);

		} else if (op[0] == 'D') {
			int len = read ();
			int x, y, z; split (root, pos - 1, x, y); split (y, len, y, z);
			root = merge (x, z);
		} else if (op[0] == 'G') {
			int len = read ();
			int x, y, z; split (root, pos - 1, x, y); split (y, len, y, z);
			output (y); std::cout << "\n";
			root = merge (x, merge (y, z));
		} else if (op[0] == 'P') {
			pos --;
		} else if (op[0] == 'N') {
			pos ++;
		}
	}

	return 0;
}

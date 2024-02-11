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
	int val;
	int siz;
	int mn;
	bool tag;
	int ls, rs;
	unsigned long long key;
} tr[maxn];

std::mt19937 rnd (std::chrono::steady_clock::now ().time_since_epoch ().count ());

int root, tot;

inline int newNode (int val) {
	tr[++tot] = Node { val, 1, val, false, 0, 0, rnd () };
	return tot;
}

inline void pushUp (int now) {
	tr[now].siz = tr[tr[now].ls].siz + tr[tr[now].rs].siz + 1;
	tr[now].mn = tr[now].val;

	if (tr[now].ls) { tr[now].mn = std::min (tr[now].mn, tr[tr[now].ls].mn); }
	if (tr[now].rs) { tr[now].mn = std::min (tr[now].mn, tr[tr[now].rs].mn); }
}

inline void pushDown (int now) {
	if (not tr[now].tag) { return; }
	if (tr[now].ls) { tr[tr[now].ls].tag ^= 1; }
	if (tr[now].rs) { tr[tr[now].rs].tag ^= 1; }
	std::swap (tr[now].ls, tr[now].rs);
	tr[now].tag = false;
}

void split (int now, int siz, int& x, int& y) {
	if (not now) { x = y = 0; return; }

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
	if (not x or not y) { return x | y; }

	if (tr[x].key <= tr[y].key) {
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

inline void insert (int val) {
	root = merge (root, newNode (val));
}

inline int getMinPos () {
	int now = root;
	int pos = 1;

	while (true) {
		pushDown (now);
		if (tr[now].ls and tr[now].mn == tr[tr[now].ls].mn) { now = tr[now].ls; }
		else if (tr[now].rs and tr[now].mn == tr[tr[now].rs].mn) { pos += tr[tr[now].ls].siz + 1; now = tr[now].rs; }
		else { return pos + tr[tr[now].ls].siz; }
	}
}

struct Info {
	int val;
	int pos;

	friend bool operator < (Info a, Info b) {
		if (a.val != b.val) { return a.val < b.val; }
		else { return a.pos < b.pos; }
	}
};

std::vector <Info> a;
int rnk[maxn];

int n;

int main () {
	fastread

	std::cin >> n;
	for (int i = 1; i <= n; i++) { int now; std::cin >> now; a.push_back ({now, i}); }	

	std::sort (a.begin (), a.end ());
	for (int i = 1; i <= n; i++) { rnk[a[i - 1].pos] = i; }
	for (int i = 1; i <= n; i++) { insert (rnk[i]); }
	
	for (int i = 1; i <= n; i++) { 
		int pos = getMinPos ();
		std::cout << pos + i - 1 << " ";
		
		int x, y, z;
		split (root, pos, x, y);
		split (x, pos - 1, x, z);
		
		tr[x].tag ^= 1;

		root = merge (x, y);
	}

	return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <unordered_map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#include <random>
#include <chrono>

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 300205;

int n, m, q;

struct Node {
	int ls, rs;

	int siz;
	std::string val;
	unsigned long long key;
} tr[maxn];

int tot, root;

std::mt19937 rnd (std::chrono::steady_clock::now ().time_since_epoch ().count ());

inline int newNode (std::string val) {
	tr[++tot] = Node { 0, 0, 1, val, rnd () };
	return tot;
}

inline void pushUp (int now) { tr[now].siz = tr[tr[now].ls].siz + tr[tr[now].rs].siz + 1; }

void split (int now, int siz, int& x, int& y) {
	if (not now) { x = y = 0; return; }

	if (siz <= tr[tr[now].ls].siz) {
		y = now; split (tr[now].ls, siz, x, tr[now].ls); pushUp (now);
	} else {
		x = now; split (tr[now].rs, siz - tr[tr[now].ls].siz - 1, tr[now].rs, y); pushUp (now);
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

inline void insert (int pos, std::string val) {
	int x, y; split (root, pos - 1, x, y);
	root = merge (x, merge (newNode (val), y));
}

inline std::string getVal (int pos) {
	int x, y, z, node; split (root, pos - 1, x, y); split (y, 1, node, z);
	std::string val = tr[node].val;
	root = merge (x, merge (node, z));
	return val;
}

int main () {
	fastread
	
	std::cin >> n;

	for (int i = 1; i <= n; i++) { std::string s; std::cin >> s; insert (i, s); }

	std::cin >> m;

	for (int i = 1; i <= m; i++) {
		std::string s; std::cin >> s;
		int pos; std::cin >> pos; pos ++; // 转化为从1开始
		insert (pos, s);
	}

	std::cin >> q;

	for (int i = 1; i <= q; i++) {
		int pos; std::cin >> pos; pos ++;
		std::cout << getVal (pos) << "\n";
	}

	return 0;
}

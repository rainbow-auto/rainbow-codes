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

using i64 = unsigned long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 100005;

struct Line {
	int x;
	int y1, y2;
	int mark;

	friend bool operator < (Line a, Line b) {
		return a.x < b.x;
	}

} lines[maxn << 1];
int tot;

int n;

struct Node { // Segment Tree Node
	int l, r;
	
	int mark;
	int len;

	int ls, rs;
} tr[maxn << 6];

int nodeTot;
int root;

inline void pushUp (int now, int l, int r) {
	if (tr[now].mark) { tr[now].len = r - l + 1; }
	else { tr[now].len = tr[tr[now].ls].len + tr[tr[now].rs].len; }
}

void modify (int& now, int l, int r, int L, int R, int val) {
	if (not now) { now = ++nodeTot; }
	if (L <= l and r <= R) { tr[now].mark += val; pushUp (now, l, r); return; }
	
	int mid = (l + r) >> 1;
	if (L <= mid) { modify (tr[now].ls, l, mid, L, R, val); }
	if (R > mid) { modify (tr[now].rs, mid + 1, r, L, R, val); }
	pushUp (now, l, r);
}

int query () { return tr[root].len; }

int main () {
	fastread

	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;
		lines[++tot] = Line { x1, y1, y2, 1 };
		lines[++tot] = Line { x2, y1, y2, -1 };
	}

	std::sort (lines + 1, lines + tot + 1);

	i64 res = 0;
	int lastx = 0;

	for (int i = 1; i <= tot; i++) {
		int x = lines[i].x;
		res += 1ll * (x - lastx) * query ();
		lastx = x;

		// add lines
		modify (root, 0, 2e9, lines[i].y1, lines[i].y2 - 1, lines[i].mark); 
		// 边长计算时应为 y2 - y1
		// 线段树计算时为 r - l + 1
		// 将所有线的y2减去1
		// 代入得 (y2 - 1) - y1 + 1 = y2 - y1
	}

	std::cout << res << "\n";

	return 0;
}

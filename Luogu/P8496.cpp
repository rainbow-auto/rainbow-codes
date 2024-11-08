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

using i64 = long long;

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxn = 1000005;

int n, q;

struct Node {
	int ls, rs;
	i64 sum;
} tr[maxn << 6];

int rt[maxn], tot;

void modify (int& now, i64 l, i64 r, i64 pos, i64 val) {
	if (not now) { now = ++tot; }
	tr[now].sum += val;
	if (l == r) { return; }

	i64 mid = (l + r) >> 1;
	if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); }
	if (pos > mid) { modify (tr[now].rs, mid + 1, r, pos, val); }
}

std::vector <int> curr;
i64 query (i64 l, i64 r, i64 need) {
	if (l == r) {
		i64 sum = 0; for (auto x : curr) { sum += tr[x].sum; }
		return sum > need ? l : -1;
	}

	i64 lsum = 0;
	for (auto x : curr) { lsum += tr[tr[x].ls].sum; }
	
	i64 mid = (l + r) >> 1;
	if (lsum > need) { 
		for (auto& x : curr) { x = tr[x].ls; }
		return query (l, mid, need); 
	} else {
		for (auto& x : curr) { x = tr[x].rs; }
		return query (mid + 1, r, need); 
	}
}

int merge (int a, int b, i64 l, i64 r) {
	if (not a or not b) { return a + b; }
	if (l == r) {
		tr[a].sum += tr[b].sum;
		return a;
	}

	i64 mid = (l + r) >> 1;
	tr[a].ls = merge (tr[a].ls, tr[b].ls, l, mid);
	tr[a].rs = merge (tr[a].rs, tr[b].rs, mid + 1, r);
	
	tr[a].sum = tr[tr[a].ls].sum + tr[tr[a].rs].sum;
	
	return a;
}

struct ListNode {
	i64 val;
	int pre;
} ns[maxn << 2];

int last[maxn << 1], npos; 
i64 siz[maxn << 1];

int head[maxn << 1];

inline void push_back (int x, i64 val) {
	ns[++npos] = ListNode { val, last[x] };
	last[x] = npos;
	if (not siz[x]) { head[x] = npos; }
	siz[x] ++;

	modify (rt[x], 0, 1e7, val, 1);
}

inline void pop_back (int x) {
	modify (rt[x], 0, 1e7, ns[last[x]].val, -1);
	last[x] = ns[last[x]].pre;
	siz[x] --;
}

inline void display () {
	int i = 1;
	while (siz[i]) {
		std::cerr << i << ": ";
		for (int now = last[i]; now; now = ns[now].pre) {
			std::cerr << ns[now].val << " ";
		}
		std::cerr << "\n";

		i++;
	}
	std::cerr << "\n";
}

int main () {
	fastread

	std::cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		i64 len; std::cin >> len;

		for (int j = 1; j <= len; j++) {
			int val; std::cin >> val;
			push_back (i, val);
		}
	}

	while (q--) {
		int op; std::cin >> op;

		if (op == 1) {
			int x, y; std::cin >> x >> y;
			push_back (x, y);
		} else if (op == 2) {
			int x; std::cin >> x;
			pop_back (x);
		} else if (op == 3) {
			int m; std::cin >> m;

			i64 need = 0;
			while (m--) { int x; std::cin >> x; curr.push_back (rt[x]); need += siz[x]; }
			need >>= 1;
			std::cout << query (0, 1e7, need) << "\n";

			curr.clear ();
		} else if (op == 4) {
			int x1, x2, x3; std::cin >> x1 >> x2 >> x3;
		
			if (siz[x1] and siz[x2]) {
				ns[head[x2]].pre = last[x1];
				head[x3] = head[x1];
				last[x3] = last[x2];
				siz[x3] = siz[x1] + siz[x2];
				rt[x3] = merge (rt[x1], rt[x2], 0, 1e7);	
			} else if (not siz[x1]) {
				rt[x3] = rt[x2];
				head[x3] = head[x2];
				last[x3] = last[x2];	
				siz[x3] = siz[x2];
			} else if (not siz[x2]) {
				rt[x3] = rt[x1];
				head[x3] = head[x1];
				last[x3] = last[x1];	
				siz[x3] = siz[x1];
 			} 
		}
	}

	return 0;
}

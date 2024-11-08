// 啊啊啊啊啊

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

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 100005;

int n, m;
int valL, valR; // val 的 左右边界
int trL, trR; // tree 的 左右边界

struct Node {
	int ls, rs;
	int sum;
} tr[maxn * 33];

int tot, root;

void modify (int& now, int l, int r, int pos) {
	if (not now) { now = ++tot; }
	tr[now].sum ++;

	if (l == r) { return; }

	int mid = (l + r) >> 1;
	if (pos <= mid) { modify (tr[now].ls, l, mid, pos); }
	else { modify (tr[now].rs, mid + 1, r, pos); }
}

int query (int now, int l, int r, int pos) { // query_rank => 求和
	if (not tr[now].sum) { return 0; }
	if (l == r) { return 0; }

	int mid = (l + r) >> 1;
	if (pos <= mid) { return query (tr[now].ls, l, mid, pos); }
	if (pos > mid) { return query (tr[now].rs, mid + 1, r, pos) + tr[tr[now].ls].sum; }
}

int query_val (int now, int l, int r, int k) {
	if (l == r) { return l; }

	int mid = (l + r) >> 1;
	int l_cnt = std::max (0, std::min (mid, valR) - std::max (l, valL) + 1 - tr[tr[now].ls].sum);
	if (k <= l_cnt) {
		return query_val (tr[now].ls, l, mid, k);
	} else {
		return query_val (tr[now].rs, mid + 1, r, k - l_cnt);
	}
}

inline int query_rank (int v) {
	return (v - valL + 1) - query (root, trL, trR, v);
}

std::map <int, int> val; // id -> val
std::map <int, int> id; // val -> id

int main () {
	fastread

	std::cin >> n >> m;

	valL = 1; valR = n;
	trL = -100100005; trR = 100100005;

	// 我是脑残
	// for (int i = trL; i <= valL - 1; i++) { modify (root, trL, trR, i, 1); }
	// for (int i = valR + 1; i <= trR; i++) { modify (root, trL, trR, i, 1); }
	
	// 我还是脑残
	// range_modify (root, trL, trR, trL, valL - 1, 1);
	// range_modify (root, trL, trR, valR + 1, trR, 1);

	// MLE
	// for (int i = 1; i <= n; i++) { val[i] = i; }
	// for (int i = 1; i <= n; i++) { id[i] = i; }

	int lastans = 0;

	#define input(tmp) int tmp; std::cin >> (tmp); tmp -= lastans;
	#define output(tmp) std::cout << (tmp) << "\n"; lastans = (tmp);

	for (int i = 1; i <= m; i++) {
		int op; std::cin >> op;
		input (x);

		if (op == 1) {
			input (y);

			int val_now = val.count (x) ? val[x] : x;
			output (query_rank (val_now));
			
			val[y] = val_now;
			id[val_now] = y;
		} else if (op == 2) {
			int val_now = val.count (x) ? val[x] : x;
			output (query_rank (val_now)); 
				
			modify (root, trL, trR, val_now);
			id[--valL] = x;
			val[x] = valL;
		} else if (op == 3) {
			int val_now = val.count (x) ? val[x] : x;
			output (query_rank (val_now)); 
		
			modify (root, trL, trR, val_now);
			id[++valR] = x;
			val[x] = valR;
		} else if (op == 4) {
			int val_now = query_val (root, trL, trR, x);
			output (id.count (val_now) ? id[val_now] : val_now);
		}
	}

	return 0;
}

/*
解密后的输入:
1 2 11
3 11
2 3
3 5
2 4
2 7
2 6
3 9
2 11
4 1
*/
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

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 1000005;

int a[maxn];

struct Node {
	int mn, mx, sum;
	int tag; // 用于加法的懒标记
};

Node tr[maxn];

inline void push_up (int x) {
	tr[x].mn = min (tr[x << 1].mn, tr[x << 1 | 1].mn);
	tr[x].mx = min (tr[x << 1].mx, tr[x << 1 | 1].mx);
	tr[x].sum = tr[x << 1].sum + tr[x << 1 | 1].sum;
}

inline void push_down (int x, int l, int r) { // 懒标记下传
	int tag = tr[x].tag;
	tr[x << 1].mn += tag;
	tr[x << 1].mx += tag;
	tr[x << 1 | 1].mn += tag;
	tr[x << 1 | 1].mx += tag;
	tr[x << 1].sum += tag * (mid - l + 1);
	tr[x << 1 | 1].sum += tag * (r - mid);
	tr[x].tag = 0;
}

void build_tree (int now, int l, int r) {
	if (l == r) {
		tr[now].mn = a[l];
		tr[now].mx = a[l];
		tr[now].sum = a[l];
		tr[now].tag = 0;
		return;
	}

	int mid = (l + r) >> 1;

	build_tree (now << 1, l, mid);
	build_tree (now << 1, mid + 1, r);
}

void range_add (int now, int l, int r, int L, int R, int val) {
	if (L <= l and r <= R) {
		tr[now].mn += val;
		tr[now].mx += val;
		tr[now].sum += val * (r - l + 1);
		tr[now].tag += val;
	}

	int mid = (l + r) >> 1;	

	if (L <= mid) {
		range_add (now << 1, l, mid, L, R, val);
	}
	if (R > mid) {
		range_add (now << 1 | 1, mid + 1, r, L, R, val);
	}
	
	push_up (now);
} 

inline int _sqrt (int x) { return sqrt(x); }  // 很巧妙的强制类型转换

inline void range_sqrt (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) {
		if ( _sqrt(tr[now].mx) - _sqrt(tr[now].mn) == _sqrt(tr[now].mx - tr[now].mn)) {
			int delta = tr[now].mn - _sqrt(tr[now].mn);
			tr[now].mn -= delta;
			tr[now].mx -= delta;
			tr[now].tag -= delta;
			tr[now].sum -= (r - l + 1) * delta;
		}
	}
}

int main () {
	fastread
		
	return 0;
}

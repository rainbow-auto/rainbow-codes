#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

const int maxn = 100005;
const i64 mod = 1e9 + 7;

struct Node {
	i64 sum;
	i64 sum2;
	
	i64 mx, mn;

	i64 tag; // 区间覆盖
	bool cov;

	Node () {
		sum = sum2 = 0;
		mx = -2e9; mn = 2e9;
		tag = 0; cov = false;
	}

} tr[maxn << 3];

inline void pushUp (int now) {
	tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
	tr[now].sum2 = tr[now << 1].sum2 + tr[now << 1 | 1].sum2;
	tr[now].mx = std::max (tr[now << 1].mx, tr[now << 1 | 1].mx);
	tr[now].mn = std::min (tr[now << 1].mn, tr[now << 1 | 1].mn);
}

inline void apply (int now, int l, int r, i64 val) { // 区间覆盖
	tr[now].sum = val * (r - l + 1); tr[now].sum %= mod;
	tr[now].sum2 = val * val * (r - l + 1); tr[now].sum2 %= mod;
	tr[now].mx = tr[now].mn = val;
	tr[now].tag = val;	
	tr[now].cov = true;
}

inline void pushDown (int now, int l, int r) {
	if (not tr[now].cov) { return; }

	int mid = (l + r) >> 1;
	apply (now << 1, l, mid, tr[now].tag);
	apply (now << 1, mid + 1, r, tr[now].tag);
	
	tr[now].tag = 0; tr[now].cov = false;
}

void modify (int now, int l, int r, int pos, i64 val) {
	if (l == r) { 
		tr[now].sum = val; tr[now].sum %= mod; 
		tr[now].sum2 = val * val; tr[now].sum2 %= mod;
		tr[now].mx = val;
		tr[now].mn = val;
		return; 
	}

	pushDown (now, l, r);

	int mid = (l + r) >> 1;
	if (pos <= mid) { modify (now << 1, l, mid, pos, val); }
	else { modify (now << 1 | 1, mid + 1, r, pos, val); }

	pushUp (now);
}

void modify_div (int now, int l, int r, int L, int R, i64 val) {
	if (L <= l and r <= R) {
		if (tr[now].mx == tr[now].mn) {
			i64 t = ceil (tr[now].mx / val);
			apply (now, l, r, t);
			return;
		}
	}

	pushDown (now, l, r);

	int mid = (l + r) >> 1;
	if (L <= mid) { modify_div (now << 1, l, mid, L, R, val); }
	if (R > mid) { modify_div (now << 1 | 1, mid + 1, r, L, R, val); }

	pushUp (now);
}	

i64 querysum (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) { return tr[now].sum; }

	pushDown (now, l, r);

	i64 res = 0;

	int mid = (l + r) >> 1;
	if (L <= mid) { res += querysum (now << 1, l, mid, L, R); res += mod; res %= mod; } 
	if (R > mid) { res += querysum (now << 1 | 1, mid + 1, r, L, R); res += mod; res %= mod; }

	return res;
}

i64 querysum2 (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) { return tr[now].sum2; }

	pushDown (now, l, r);

	i64 res = 0;
	int mid = (l + r) >> 1;
	if (L <= mid) { res += querysum2 (now << 1, l, mid, L, R); res += mod; res %= mod; }
	if (R > mid) { res += querysum2 (now << 1 | 1, mid + 1, r, L, R); res += mod; res %= mod; }

	return res;
}

int n, m;
int a[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	

	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);

	std::cin >> n >> m;
	rep (i, 1, n) { std::cin >> a[i]; modify (1, 1, n, i, a[i]); }

	while (m--) {
		int op; std::cin >> op;
		if (op == 1) {
			int l, r; std::cin >> l >> r;
			std::cout << querysum (1, 1, n, l, r) << "\n";
		
		} else if (op == 2) {
			int l, r; std::cin >> l >> r;
			std::cout << querysum2 (1, 1, n, l, r) << "\n";
		
		} else if (op == 3) {
			int l, r; std::cin >> l >> r;
			i64 p; std::cin >> p;

			modify_div (1, 1, n, l, r, p);

		} else if (op == 4) {
			int pos; std::cin >> pos;
			i64 val; std::cin >> val;

			modify (1, 1, n, pos, val);	
		}
	}
	
	return 0;
}

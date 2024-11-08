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

const int maxn = 400005;
const i64 inf = 1e16;

int n, q;

struct SegTree {
	struct Node {
		i64 mn, mx;
		i64 tag;

		Node () { mx = -inf; mn = inf; tag = 0; }
	} tr[maxn << 2];

	inline void pushUp (int now) { 
		tr[now].mn = std::min (tr[now << 1].mn, tr[now << 1 | 1].mn); 
		tr[now].mx = std::max (tr[now << 1].mx, tr[now << 1 | 1].mx); 
	}

	inline void apply (int now, i64 val) {
		tr[now].mn += val; tr[now].mx += val;
		tr[now].tag += val; 
	}

	inline void pushDown (int now) {
		if (not tr[now].tag) { return; }
		apply (now << 1, tr[now].tag);
		apply (now << 1 | 1, tr[now].tag);
		tr[now].tag = 0;
	}

	void modify (int now, int l, int r, int pos, i64 val) {
		if (l == r) { tr[now].mx = tr[now].mn = val; return; }
		pushDown (now);
		int mid = (l + r) >> 1;
		if (pos <= mid) { modify (now << 1, l, mid, pos, val); }
		if (pos > mid) { modify (now << 1 | 1, mid + 1, r, pos, val); }
		pushUp (now);
	}

	void modify (int now, int l, int r, int L, int R, i64 val) {
		if (L <= l and r <= R) { apply (now, val); return; }
		pushDown (now);
		int mid = (l + r) >> 1;
		if (L <= mid) { modify (now << 1, l, mid, L, R, val); }
		if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val); }
		pushUp (now);
	}

	i64 querymn (int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) { return tr[now].mn; }
		pushDown (now);
		int mid = (l + r) >> 1;
		i64 res = inf;
		if (L <= mid) { res = std::min (res, querymn (now << 1, l, mid, L, R)); }
		if (R > mid) { res = std::min (res, querymn (now << 1 | 1, mid + 1, r, L, R)); }
		return res;
	}

	i64 querymx (int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) { return tr[now].mx; }
		pushDown (now);
		int mid = (l + r) >> 1;
		i64 res = -inf;
		if (L <= mid) { res = std::max (res, querymx (now << 1, l, mid, L, R)); }
		if (R > mid) { res = std::max (res, querymx (now << 1 | 1, mid + 1, r, L, R)); }
		return res;
	}

} tr[2];

i64 a[maxn];
i64 sum[maxn];

inline bool chk (int l, int r) {
	i64 L = tr[(l - 1) & 1].querymx (1, 0, n, l - 1, l - 1);
	i64 R = 0;
	rep (i, 0, 1) {
		i64 c = (i == ((l - 1) & 1) ? 1ll : -1ll); 
		if (tr[i].querymn (1, 0, n, l, r) - c * L < 0) { return false; }
		if ((r & 1) == i) { R = tr[i].querymx (1, 0, n, r, r) - c * L; }
	}
	if (R != 0) { return false; }

	return true;
}

// inline bool chk (int l, int r) {
// 	i64 L = tr[(l - 1) & 1].querymx (1, 0, n, l - 1, l - 1);
// 	i64 R = tr[r & 1].querymx (1, 0, n, r, r) - (((r - l + 1) & 1) ? -L : L);
// 	if (R != ((r - l + 1) & 1)) { return false; }

// 	if (tr[(l - 1) & 1].querymn (1, 0, n, l, r) - L < 0) { return false; }
// 	if (tr[((l - 1) & 1) ^ 1].querymn (1, 0, n, l, r) + L < 0) { return false; }

// 	return true;
// }

bool MemED;
int main () {
	fastread
	// lookMem	

	// freopen("apple.in", "r", stdin);
    // freopen("apple.out", "w", stdout);

	std::cin >> n;
	rep (i, 1, n) { std::cin >> a[i]; a[i] --; }

	rep (i, 1, n) { sum[i] = a[i] - sum[i - 1]; }
	rep (i, 0, n) { tr[i & 1].modify (1, 0, n, i, sum[i]); }

	std::cin >> q;
	while (q--) {
		int op; std::cin >> op;
		if (op == 1) {
			int l, r; std::cin >> l >> r;
			i64 k; std::cin >> k;
			l ++; r ++; // let l, r \in [1, n] instead of [0, n)
			
			tr[l & 1].modify (1, 0, n, l, r, k);

			if ((r - l + 1) & 1) {
				tr[l & 1].modify (1, 0, n, r + 1, n, k);
				tr[(l & 1) ^ 1].modify (1, 0, n, r + 1, n, -k);
			}
		} else {
			int l, r; std::cin >> l >> r;
			l ++; r ++; // let l, r \in [1, n] instead of [0, n)
			if (chk (l, r)) { std::cout << "1\n"; }
			else { std::cout << "0\n"; }
		}
	}

	return 0;
}

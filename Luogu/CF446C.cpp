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

const int maxn = 300005;

int n, m;
int a[maxn];

// 根据二次剩余计算
const i64 q1 = 691504013;
const i64 q2 = 308495997;
const i64 f_inv = 276601605;

const i64 mod = 1e9 + 9;

inline i64 ksm (i64 a, i64 b) {
	i64 base = a;
	i64 res = 1;

	while (b) {
		if (b & 1) { res = res * base % mod; }
		
		base = base * base % mod;
		b >>= 1;
	}

	return res;
}

inline i64 getMod (i64 x) {
	if (x > mod) { x -= mod; }
	else if (x < 0) { x += mod; }
	return x;
}

struct SegmentTree {
	i64 q_power[maxn];
	i64 q_inv; // 1 / (q - 1)

	inline void init (int q) {
		q_power[0] = 1ll;
		for (int i = 1; i <= n; i++) { q_power[i] = q_power[i - 1] * q % mod; }
		
		q_inv = ksm (q - 1, mod - 2);
		
		build (1, 1, n);
	}

	struct Node {
		i64 sum;
		i64 p; // 首项 (lazy tag)
		bool cov;

		int len;
	} tr[maxn << 2];

	inline void pushUp (int now) {
		tr[now].sum = getMod(tr[now << 1].sum + tr[now << 1 | 1].sum);
		tr[now].len = tr[now << 1].len + tr[now << 1 | 1].len;
	}

	inline void update (int now, i64 val) {
		tr[now].sum = (tr[now].sum + getMod(val * q_power[tr[now].len] % mod - val) * q_inv) % mod;	// 等比数列求和公式 a1 * (q^n - 1) / (q - 1) 
		tr[now].p = (tr[now].p + val) % mod;
		tr[now].cov = true;
	}

	inline void pushDown (int now, int l, int r) {
		if (not tr[now].cov) { return; }

		int mid = (l + r) >> 1;

		update (now << 1, tr[now].p);
		update (now << 1 | 1, tr[now].p * q_power[mid - l + 1] % mod);
		tr[now].p = 0; tr[now].cov = false; // 在pushdown之后标记就没用了, 直接清空
	}

	void build (int now, int l, int r) {
		if (l == r) {
			tr[now] = Node { 0, 0, false, 1 };
			return;
		}

		int mid = (l + r) >> 1;
		build (now << 1, l, mid);
		build (now << 1 | 1, mid + 1, r);

		pushUp (now);
	}

	void modify (int now, int l, int r, int L, int R, i64 p) {
		if (L <= l and r <= R) { update (now, p); return; }
		
		pushDown (now, l, r);

		int mid = (l + r) >> 1;
		if (R <= mid) { modify (now << 1, l, mid, L, R, p); pushUp (now); return; } // 全部在左侧
		if (L > mid) { modify (now << 1 | 1, mid + 1, r, L, R, p); pushUp (now); return; }

		modify (now << 1, l, mid, L, R, p);
		modify (now << 1 | 1, mid + 1, r, mid + 1, R, p * q_power[mid - L + 1] % mod); // 注意要使 L 和 p 一直保持匹配状态
		pushUp (now);
	}

	i64 query (int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) { return tr[now].sum; }

		pushDown (now, l, r);
		
		int mid = (l + r) >> 1;

		i64 res = 0;
		
		if (L <= mid) { res += query (now << 1, l, mid, L, R); res %= mod; }
		if (R > mid) { res += query (now << 1 | 1, mid + 1, r, L, R); res %= mod; }

		return res;
	}
};

SegmentTree t1, t2;

struct PrefixSum {
	i64 sum[maxn];
	
	inline void init () {
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + a[i]; sum[i] %= mod;
		}
	}

} t3;

int main () {
	fastread
	
	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

	t3.init ();
	t1.init (q1);
	t2.init (q2);

	while (m--) {
		int op, l, r; std::cin >> op >> l >> r;

		if (op == 1) {
			t1.modify (1, 1, n, l, r, q1); // 首项恰好是q1
			t2.modify (1, 1, n, l, r, q2); 
		} else {
			i64 res = (t1.query (1, 1, n, l, r) - t2.query (1, 1, n, l, r) + mod) % mod;
			res *= f_inv; res %= mod;
			res -= t3.sum[l - 1]; res %= mod; res += mod; res %= mod;
			res += t3.sum[r]; res %= mod;

			std::cout << res << "\n";
		}
	}

	return 0;
}

/*
now = 1 -159471950
now = 1 159471965
-------------
now = 1 147981965
now = 2 74512022
now = 3 73469943
now = 6 184801467
now = 1 141528393
now = 2 925487992
now = 3 -783959599
now = 6 356670459
-------------
*/
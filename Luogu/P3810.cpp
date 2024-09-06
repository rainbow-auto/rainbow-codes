#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 200005;

int n;
struct Node {
	int a, b, c;

	friend bool operator == (Node x, Node y) { return x.a == y.a and x.b == y.b and x.c == y.c; }
} a[maxn];

int k;

struct FenwickTree {
	inline int lowbit (int x) { return x & (-x); }

	struct SegTree {
		struct Node {
			int ls, rs;
			i64 sum;
		} tr[maxn << 8];

		int root[maxn], tot;

		void modify (int& now, int l, int r, int pos, int val) {
			if (not now) { now = ++tot; }
			if (l == r) { tr[now].sum += val; return; }

			int mid = (l + r) >> 1;
			if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); } 
			else { modify (tr[now].rs, mid + 1, r, pos, val); }
			tr[now].sum = tr[tr[now].ls].sum + tr[tr[now].rs].sum;
		}

		int query (int now, int l, int r, int L, int R) {
			if (not now) { return 0; }
			if (L <= l and r <= R) { return tr[now].sum; }

			int res = 0;

			int mid = (l + r) >> 1;
			if (L <= mid) { res += query (tr[now].ls, l, mid, L, R); }
			if (R > mid) { res += query (tr[now].rs, mid + 1, r, L, R); }
			
			return res;
		}
	} tr;

	inline void add (int x, int y, int v) {
		for (int i = x; i <= k; i += lowbit (i)) { tr.modify (tr.root[i], 1, k, y, v); }
	}

	inline int query (int x, int y) {
		int res = 0;
		for (int i = x; i; i -= lowbit (i)) { res += tr.query (tr.root[i], 1, k, 1, y); }
		return res;
	}
} tr;

int cnt[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n >> k;
	rep (i, 1, n) { std::cin >> a[i].a >> a[i].b >> a[i].c; }

	std::sort (a + 1, a + n + 1, [] (Node x, Node y) -> bool { 
			if (x.a != y.a) { return x.a < y.a; } 
			else if (x.b != y.b) { return x.b < y.b; }
			else { return x.c < y.c; }
		}
	);

	int same = 1; // 处理相等的会爆炸, 相等的被排序排到前面的会算少
	rep (i, 1, n) {
		if (a[i] == a[i + 1]) { same ++; continue; }
		tr.add (a[i].b, a[i].c, same);
		int curr = tr.query (a[i].b, a[i].c);
		cnt[curr] += same;
		same = 1;
	}

	rep (d, 1, n) { std::cout << cnt[d] << "\n"; }

	return 0;
}

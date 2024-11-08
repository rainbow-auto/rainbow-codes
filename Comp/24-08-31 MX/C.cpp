#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

// #define RainbowAutomatonDebugFlag

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

const int maxn = 1000005;

int n, q, v;
int a[maxn], b[maxn];

struct Query {
	int op;
	int x, y;
};
std::vector <Query> qs;

namespace Task1 {
	struct Tree {
		struct Node {
			int sum;
			int mx;
		} tr[maxn << 3];

		inline void pushUp (int now) { 
			tr[now].sum = (tr[now << 1].sum | tr[now << 1 | 1].sum); 
			tr[now].mx = std::max (tr[now << 1].mx, tr[now << 1 | 1].mx);
		}

		void modify (int now, int l, int r, int pos, int val_a, int val_b) {
			if (l == r) { tr[now].sum = val_b; tr[now].mx = val_a; return; }
			int mid = (l + r) >> 1;
			if (pos <= mid) { modify (now << 1, l, mid, pos, val_a, val_b); }
			else { modify (now << 1 | 1, mid + 1, r, pos, val_a, val_b); }
			pushUp (now);
		}

		int query (int now, int l, int r, int L, int R) {
			if (L <= l and r <= R) { return tr[now].sum; }
			
			int mid = (l + r) >> 1;
			int res = 0;
			if (L <= mid) { res |= query (now << 1, l, mid, L, R); }
			if (R > mid) { res |= query (now << 1 | 1, mid + 1, r, L, R); }
			return res;
		}

		int querymx (int now, int l, int r, int L, int R) {
			if (L <= l and r <= R) { return tr[now].mx; }
			
			int mid = (l + r) >> 1;
			int res = 0;
			if (L <= mid) { res = std::max (res, querymx (now << 1, l, mid, L, R)); }
			if (R > mid) { res = std::max (res, querymx (now << 1 | 1, mid + 1, r, L, R)); }
			return res;
		}
	} tr;

	inline int get (int st, int k) {
		int l = st + k - 1, r = n;
		int res = -1;

		while (l <= r) {
			int mid = (l + r) >> 1;
			if (tr.query (1, 1, n, st, mid) >= v) { r = mid - 1; res = mid; }
			else { l = mid + 1; }
		}
 
		return res;
	}

	inline void solve () {
		rep (i, 1, n) { tr.modify (1, 1, n, i, a[i], b[i]); }

		for (auto query : qs) {
			if (query.op == 1) {
				b[query.x] |= query.y;
				tr.modify (1, 1, n, query.x, a[query.x], b[query.x]);
			} else {
				int res = -1;
				rep (i, 1, n) {
					int r = get (i, query.x);
					if (r == -1) { continue; }

					int curr = tr.querymx (1, 1, n, i, r);
					if (res == -1) { res = curr; }
					else { res = std::min (res, curr); }
				}

				std::cout << res << "\n";
			}
		}
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen ("eternal.in", "r", stdin);
	freopen ("eternal.out", "w", stdout);

	std::cin >> n >> q >> v;
	rep (i, 1, n) { std::cin >> a[i]; }
	rep (i, 1, n) { std::cin >> b[i]; }

	while (q--) {
		int op; std::cin >> op;
		if (op == 1) { int i, x; std::cin >> i >> x; qs.push_back (Query { op, i, x }); }
		else { int k; std::cin >> k; qs.push_back (Query { op, k, 0 }); }
	}

	Task1::solve ();

	return 0;
}

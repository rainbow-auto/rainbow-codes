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

const int maxn = 100005;

struct Tree {
	struct Node {
		int ls, rs;
		int sum;
	} tr[maxn << 5];

	int rt, tot;

	inline void pushUp (int now) { tr[now].sum = tr[tr[now].ls].sum + tr[tr[now].rs].sum; }

	void modify (int& now, int l, int r, int pos, int val) {
		if (not now) { now = ++tot; }
		if (l == r) { tr[now].sum ++; return; }
		
		int mid = (l + r) >> 1;
		if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); }
		else { modify (tr[now].rs, mid + 1, r, pos, val); }

		pushUp (now);
	}

	int kth (int now, int l, int r, int k) {
		if (not now) { return -1; }
		if (l == r) { return l; }

		int mid = (l + r) >> 1;

		int lcnt = tr[tr[now].ls].sum;
		if (k <= lcnt) { return kth (tr[now].ls, l, mid, k); }
		else { return kth (tr[now].rs, mid + 1, r, k - lcnt); }
	}
} tr;

int n;
int a[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n;
	rep (i, 1, n) { std::cin >> a[i]; }

	rep (i, 1, n) {
		tr.modify (tr.rt, 0, 1e9, a[i], 1);
		if (not (i & 1)) { continue; }
		std::cout << tr.kth (tr.rt, 0, 1e9, (i >> 1) + 1) << "\n";
	}

	return 0;
}

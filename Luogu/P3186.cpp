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
		int siz;
		i64 sum;
	} tr[maxn << 6];

	int tot, root[maxn];

	int newNode (Node old) { tr[++tot] = old; return tot; }

	void modify (int& now, int old, int l, int r, int pos, i64 val) {
		now = newNode (tr[old]);
		tr[now].siz += val; tr[now].sum += val * pos;
		if (l == r) { return; }

		int mid = (l + r) >> 1;
		if (pos <= mid) { modify (tr[now].ls, tr[old].ls, l, mid, pos, val); } 
		if (pos > mid) { modify (tr[now].rs, tr[old].rs, mid + 1, r, pos, val); }
	}

	i64 query (int now, int l, int r, int k) {
		if (not now) { return 0; }
		if (l == r) { return (i64) l * k; }

		int mid = (l + r) >> 1;
		int lsiz = tr[tr[now].ls].siz;

		if (k <= lsiz) { return query (tr[now].ls, l, mid, k); }
		else { return tr[tr[now].ls].sum + query (tr[now].rs, mid + 1, r, k - lsiz); }
	}
} tr;

int n, q;

struct Task {
	i64 val;
	int flag;
};
std::vector <Task> tasks[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n >> q;
	rep (i, 1, n) {
		int l, r, x; std::cin >> l >> r >> x;
		tasks[l].push_back (Task { x, 1 });
		tasks[r + 1].push_back (Task { x, -1 });
	}

	rep (i, 1, n) {
		tr.root[i] = tr.root[i - 1];
		for (auto task : tasks[i]) {
			tr.modify (tr.root[i], tr.root[i], 1, 1e7, task.val, task.flag);
		}
	}

	int lastans = 1;
	while (q--) {
		i64 x, a, b, c; std::cin >> x >> a >> b >> c;
		int k = 1 + (a * lastans + b) % c;
		lastans = tr.query (tr.root[x], 1, 1e7, k); std::cout << lastans << "\n";
	}

	return 0;
}

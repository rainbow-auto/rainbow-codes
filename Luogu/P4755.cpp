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

int n;
int a[maxn];

struct SparseTable {
	int lg2[maxn];
	std::pair <int, int> st[25][maxn];
	inline void init () {
		rep (i, 1, n) { st[0][i] = { a[i], i }; }
		rep (j, 1, 20) {
			rep (i, 1, (n - (1 << j) + 1)) {
				st[j][i] = std::max (st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
			}
		}
		lg2[1] = 0;
		rep (i, 2, n) { lg2[i] = lg2[i >> 1] + 1; }
	}

	inline std::pair <int, int> query (int l, int r) {
		int len = lg2[r - l + 1];
		return std::max (st[len][l], st[len][r - (1 << len) + 1]);
	}
} st;

struct Tree {
	struct Node {
		int ls, rs;
		i64 sum;
	} tr[maxn << 5];
	int root, tot;

	inline void pushUp (int now) { tr[now].sum = tr[tr[now].ls].sum + tr[tr[now].rs].sum; }

	void modify (int& now, int l, int r, int pos, int val) {
		if (not now) { now = ++tot; }
		if (l == r) { tr[now].sum += val; return; }

		int mid = (l + r) >> 1;
		if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); }
		else { modify (tr[now].rs, mid + 1, r, pos, val); }
		pushUp (now);
	}

	i64 query (int now, int l, int r, int L, int R) {
		if (not now) { return 0; }
		if (L <= l and r <= R) { return tr[now].sum; }
		
		i64 res = 0;

		int mid = (l + r) >> 1;
		if (L <= mid) { res += query (tr[now].ls, l, mid, L, R); }
		if (R > mid) { res += query (tr[now].rs, mid + 1, r, L, R); }
		return res;
	}
} tr;

struct Task {
	int x;
	i64 flag;
};
std::vector <Task> tasks[maxn];

i64 ans;
inline void run () {
	rep (i, 1, n) {
		tr.modify (tr.root, 1, 1e9, a[i], 1);
		for (auto task : tasks[i]) {
			ans += task.flag * tr.query (tr.root, 1, 1e9, 0, task.x);
		}
	}
}

inline void addTask (int l, int r, int x) {
	tasks[r].push_back (Task { x, 1 });
	tasks[l - 1].push_back (Task { x, -1 });
}

void solve (int l, int r) {
	if (l > r) { return; }
	if (l == r) { ans += a[l] == 1; return; }

	int mx, pos; std::tie (mx, pos) = st.query (l, r);

	int lenL = pos - l + 1;
	int lenR = r - (pos + 1) + 1;

	if (lenL < lenR) {
		rep (i, l, pos) {
			addTask (pos, r, mx / a[i]);
		}
	} else {
		rep (i, pos, r) {
			addTask (l, pos, mx / a[i]);
		}
	}
	solve (l, pos - 1); solve (pos + 1, r);
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n;
	rep (i, 1, n) { std::cin >> a[i]; }

	st.init ();

	solve (1, n);

	run ();

	std::cout << ans << "\n";

	return 0;
}

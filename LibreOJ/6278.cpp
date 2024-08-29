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
bool MemST;

const int maxn = 50005;

int n;

int bcnt;
int belong[maxn];
i64 L[maxn], R[maxn];

i64 tag[maxn];
i64 a[maxn];

std::vector <i64> nums[maxn];

inline void init () {
	memset (L, 0x3f, sizeof (L));
	int B = sqrt (n);
	rep (i, 1, n) {
		int curr = i / B + 1;
		belong[i] = curr;
		L[curr] = std::min (L[curr], i);
		R[curr] = std::max (R[curr], i);
		bcnt = curr;
	}
}

inline void pushDown (int id) {
	rep (i, L[id], R[id]) { a[i] += tag[id]; }
	tag[id] = 0;
}

inline void rebuild (int id) {
	nums[id].clear ();
	rep (i, L[id], R[id]) { nums[id].push_back (a[i]); }
	std::sort (nums[id].begin (), nums[id].end ());
}

inline void add (int l, int r, i64 c) {
	if (belong[l] == belong[r]) {
		pushDown (belong[l]);
		rep (i, l, r) { a[i] += c; }
		rebuild (belong[l]);
		return;
	}

	pushDown (belong[l]);
	rep (i, l, R[belong[l]]) { a[i] += c; }
	rebuild (belong[l]);

	pushDown (belong[r]);
	rep (i, L[belong[r]], r) { a[i] += c; }
	rebuild (belong[r]);

	rep (i, belong[l] + 1, belong[r] - 1) { tag[i] += c; }
}

inline int query (int l, int r, i64 c) {
	if (belong[l] == belong[r]) {
		int res = 0;
		rep (i, l, r) { res += bool (a[i] + tag[belong[i]] < c * c); }
		return res;
	}

	int res = 0;
	rep (i, l, R[belong[l]]) { res += bool (a[i] + tag[belong[i]] < c * c); }
	rep (i, L[belong[r]], r) { res += bool (a[i] + tag[belong[i]] < c * c); }

	rep (i, belong[l] + 1, belong[r] - 1) {
		res += std::lower_bound (nums[i].begin (), nums[i].end (), c * c - tag[i]) - nums[i].begin ();
	}

	return res;
}

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n;
	init ();

	rep (i, 1, n) { std::cin >> a[i]; nums[belong[i]].push_back (a[i]); }
	rep (i, 1, bcnt) { std::sort (nums[i].begin (), nums[i].end ()); }

	rep (t, 1, n) {
		int op, l, r, c;
		std::cin >> op >> l >> r >> c;		

		if (op == 0) { add (l, r, c); }
		if (op == 1) { std::cout << query (l, r, c) << "\n"; }
	}

	return 0;
}

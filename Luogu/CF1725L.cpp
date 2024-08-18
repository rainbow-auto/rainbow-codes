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

int n;
int a[maxn];

i64 pre[maxn];

struct FenwickTree {
	i64 tr[maxn];
	int siz;

	inline int lowbit (int x) { return x & (-x); }

	inline void modify (int pos, int val) { for (int i = pos; i <= siz; i += lowbit (i)) { tr[i] += val; } }

	inline i64 query (int pos) { int res = 0; for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; } return res; }
	inline i64 query (int l, int r) { return query (r) - query (l - 1); }
} tr;

inline void solve () {
	rep (i, 1, n) { pre[i] = pre[i - 1] + a[i]; }
	
	rep (i, 1, n) {
		if (pre[i] < 0) { std::cout << "-1\n"; return; }
		if (pre[i] > pre[n]) { std::cout << "-1\n"; return; }
	}

	std::vector <i64> vals;
	rep (i, 1, n) { vals.push_back (pre[i]); }
	std::sort (vals.begin (), vals.end ());
	vals.erase (std::unique (vals.begin (), vals.end ()), vals.end ());

	rep (i, 1, n) {
		pre[i] = std::lower_bound (vals.begin (), vals.end (), pre[i]) - vals.begin () + 1;
	}

	tr.siz = vals.size ();

	i64 ans = 0;
	rep (i, 1, n) {
		ans += tr.query (pre[i] + 1, tr.siz);
		tr.modify (pre[i], 1);
	}

	std::cout << ans << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n;	
	rep (i, 1, n) { std::cin >> a[i]; }

	solve ();

	return 0;
}

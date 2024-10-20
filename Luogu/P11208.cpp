#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 100005;

int n;
int a[maxn];

struct FenwickTree {
	i64 tr[maxn];
	inline int lowbit(int x) { return x & -x; }
	inline void add(int pos, int val) {
		for (int i = pos; i <= n; i += lowbit(i)) tr[i] += val;
	}

	inline i64 qry(int pos) {
		int res = 0;
		for (int i = pos; i; i -= lowbit(i)) res += tr[i];
		return res;
	}
} tr;

int pos[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) pos[a[i]] = i;

	i64 ans = n;
	i64 cur = 0;
	per (i, n, 1) {
		cur += tr.qry(pos[i]);
		tr.add(pos[i], 1);
		ans = std::min(ans, cur + (i - 1));
	}

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}

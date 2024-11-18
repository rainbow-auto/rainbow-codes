#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int mod = 998244353;

int n, k;
int a[maxn];

struct Tree {
	int tr[maxn];
	inline int lowbit(int x) { return x & (-x); }

	inline void mdf(int pos, int x) {
		for (int i = pos; i <= n; i += lowbit(i)) (tr[i] += x) %= mod;
	}

	inline int qry(int pos) {
		for (int i = pos; i; i -= lowbit(i)) (res += tr[i]) %= mod;
		return res;
	}

	inline int qry(int l, int r) {
		if (l > r) return 0;
		return qry(r) - qry(l - 1);
	}

	inline void clr() { std::memset(tr, 0, sizeof tr); }
}

int pre[maxn], suf[maxn];

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n) std::cin >> a[i];

	i64 ans = 0;

	rep (i, 1, k - 1) tr.ins(a[i]);
	rep (i, k, n) {
		pre[i] = pre[i - 1] + tr.qry(a[i] + 1);
	}

	tr.clr();

	per (i, n, n - k + 2) tr.ins(a[i]);
	per (i, n - k + 1, 1)
}

bool MemED;
int main() {
	fastread
	// lookMem	

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

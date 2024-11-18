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
const int maxn = 200005;

int n, k;
int a[maxn];

struct FenwickTree {
	int tr[maxn];
	inline int lowbit(int x) { return x & (-x); }

	inline void mdf(int pos, int x) {
		for (int i = pos; i <= n; i += lowbit(i)) (((tr[i] += x) %= mod) += mod) %= mod;
	}

	inline int qry(int pos) {
		if (pos <= 0) return 0;
		int res = 0;
		for (int i = pos; i; i -= lowbit(i)) (res += tr[i]) %= mod;
		return res;
	}

	inline int qry(int l, int r) {
		if (l > r) return 0;
		return qry(r) - qry(l - 1);
	}

	inline void clr() { std::memset(tr, 0, sizeof tr); }
} tr;

inline i64 ksm(i64 a, i64 b) {
	i64 res = 1;
	for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
	return res;
}

inline i64 inv(i64 x) { return ksm(x, mod - 2); }

inline i64 choose2(i64 x) { return x * (x - 1) % mod * inv(2) % mod; }

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n) std::cin >> a[i];

	i64 tot = 0;
	rep (i, 1, n) {
		(tot += tr.qry(a[i] + 1, n)) %= mod;
		tr.mdf(a[i], 1);
	}

	i64 cnt = choose2(k) * inv(2) % mod;

	tr.clr();
	i64 cur = 0;
	rep (i, 1, k) {
		(cur += tr.qry(a[i] + 1, n)) %= mod;
		tr.mdf(a[i], 1);
	}

	i64 ans = 0;
	rep (i, 1, n - k + 1) {
		(ans += (((tot - cur) % mod + mod) % mod + cnt) % mod * inv(n - k + 1) % mod) %= mod;
		(((cur -= tr.qry(a[i] - 1)) %= mod) += mod) %= mod; tr.mdf(a[i], -1);
		if (i + k > n) break;
		(cur += tr.qry(a[i + k] + 1, n)) %= mod; tr.mdf(a[i + k], 1);
	} 

	std::cout << ans << "\n";
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

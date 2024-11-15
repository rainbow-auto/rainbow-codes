#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

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

const int maxn = 205;
const int maxT = 300005;
const i64 mod = 998244353;

int n, T;
i64 a[maxn], t[maxn];

i64 f[maxT];

inline void upd(int t) {
	per (j, T, t) (f[j] += f[j - t]) %= mod;
}

inline void clr() {
	std::memset(f, 0, sizeof f);
	f[0] = 1;
}

i64 pw2[maxn];
i64 pre[maxn];

void solve() {
	int _; std::cin >> _;
	std::cin >> n >> T;

	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) std::cin >> t[i];

	pw2[0] = 1;
	rep (i, 1, n) pw2[i] = pw2[i - 1] * 2ll % mod;
	rep (i, 1, n) pre[i] = pre[i - 1] + t[i];

	i64 ans = 0;
	clr();
	rep (i, 1, n) {
		rep (j, 0, T - t[i]) (ans += f[j] * a[i] % mod * pw2[n - i] % mod) %= mod;
		upd(t[i]);
	}

	clr();
	per (i, n, 1) {
		rep (j, 0, T - pre[i]) (ans += f[j] * a[i] % mod * pw2[i - 1] % mod) %= mod;
		upd(t[i]);
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

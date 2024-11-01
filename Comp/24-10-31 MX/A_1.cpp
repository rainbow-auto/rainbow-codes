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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 3005;
const i64 mod = 1e9 + 7;

int n, k;
i64 pw2[maxn];

bool L[maxn], R[maxn];
bool ops[maxn];

namespace Task1 {
	inline i64 chk(bool init) {
		bool limL = true, limR = true;
		bool flg = true;
		rep (i, 1, n - 1) {
			int mn = limL ? L[i] : 0;
			int mx = limR ? R[i] : 1;
			bool cur = ops[i] ^ init;
			if (not (mn <= cur and cur <= mx)) return 0;
			limL = (limL and (cur == mn));
			limR = (limR and (cur == mx));
		}

		db << "chk " << init << "\n";

		i64 res = 0;
		rep (i, 1, n - 1) (res += 1ll * (ops[i] ^ init) * (pw2[n - i - 1])) %= mod;
		res += pw2[n - 1];

		db << "res: " << res << "\n";
		return res;
	}

	inline void solve() {
		i64 ans = (chk(false) + chk(true)) % mod;

		std::cout << ans << "\n";
	}
}

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n - 1) {
		char c; std::cin >> c;
		ops[i] = (c == 'R');
	}

	rep (i, 1, n) {
		char c; std::cin >> c;
		L[i - 1] = c - '0';
	}	
	
	rep (i, 1, n) {
		char c; std::cin >> c;
		R[i - 1] = c - '0';
	}

	pw2[0] = 1;
	rep (i, 1, n) pw2[i] = pw2[i - 1] * 2ll % mod;

	if (k == 0) Task1::solve();
	// else Task2::solve();
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

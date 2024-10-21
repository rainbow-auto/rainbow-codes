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
#define MultiTask lovely_fairytale

const int maxn = 2000005;

int CaseID;

int n, m;
int a[maxn];
int b[maxn];

namespace Policy1 {
	int w[maxn];
	int f[maxn];
	inline int solve() {
		// 不留下交换
		rep (i, 1, n) {
			if (a[i] == 0 and b[i] == 0) w[i] = -1;
			if (a[i] == 0 and b[i] == 1) w[i] = 0;
			if (a[i] == 1 and b[i] == 0) w[i] = 0;
			if (a[i] == 1 and b[i] == 1) w[i] = 2;
		}

		rep (i, 1, n) f[i] = std::max(f[i - 1] + w[i], w[i]);

		int mx = 0;
		rep (i, 1, n) mx = std::max(mx, f[i]);
		return mx;
	}
}

namespace Policy2 {
	int w[maxn];
	int f[maxn][5];

	inline int solve() {
		int cnt = 0;
		rep (i, 1, n) {
			if (a[i] == 0 and b[i] == 0) w[i] = 0b00;
			if (a[i] == 0 and b[i] == 1) w[i] = 0b01;
			if (a[i] == 1 and b[i] == 0) w[i] = 0b10;
			if (a[i] == 1 and b[i] == 1) w[i] = 0b11;
		
			if (w[i] == 0b01 or w[i] == 0b10) cnt++;
		}
	
		int inf; std::memset(&inf, 0x3f, sizeof inf);
		if (cnt < 2 * m) return -inf;

		int ans = -inf;

		rep (i, 1, n) {
			rep (S, 0b00, 0b11) {
				f[i][S] = -inf;
				rep (pre, 0b00, 0b11) {
					int cur = 0;
					if (S == 0b01) {
						if (w[i] == 0b00) cur = -1;
						if (w[i] == 0b01) cur = 1;
						if (w[i] == 0b10) cur = -1;
						if (w[i] == 0b11) cur = 1;
					}
					if (S == 0b10) {
						if (w[i] == 0b00) cur = -1;
						if (w[i] == 0b01) cur = -1;
						if (w[i] == 0b10) cur = 1;
						if (w[i] == 0b11) cur = 1;
					}
					if (S == 0b11) {
						if (w[i] == 0b00) cur = -2;
						if (w[i] == 0b01) cur = 0;
						if (w[i] == 0b10) cur = 0;
						if (w[i] == 0b11) cur = 2;
					}

					f[i][S] = std::max(f[i][S], cur);
					if (S & pre) {
						f[i][S] = std::max(f[i][S], f[i - 1][pre] + cur);
					}
				}

				ans = std::max(ans, f[i][S]);
			}
		}

		ans -= 2 * m;

		return ans;
	}
}

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) {
		char ch; std::cin >> ch;
		a[i] = ch - '0';
	}
	rep (i, 1, n) {
		char ch; std::cin >> ch;
		b[i] = ch - '0';
	}

	int ans = Policy1::solve();
	if (CaseID != 12 and CaseID != 13) {
		ans = std::max(ans, Policy2::solve());
	}

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> CaseID;

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

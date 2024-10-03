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

const int maxn = 100005;

int n;
int a[maxn];

namespace Task0 {

	int ans;

	void dfs(int ansnow) {
		bool st = true;
		rep (i, 1, n) st &= a[i] <= 0;

		if (st) return ans = std::min(ans, ansnow), void(0);

		rep (i, 1, n) {
			bool flg = false;
			rep (j, 1, i) flg |= a[j] > 0;
			if (not flg) continue;

			rep (j, 1, i) a[j]--;
			dfs(ansnow + i);
			rep (j, 1, i) a[j]++;
		}

		rep (i, 1, n) {
			bool flg = false;
			per (j, n, n - i + 1) flg |= a[j] > 0;
			if (not flg) continue;

			per (j, n, n - i + 1) a[j]--;
			dfs(ansnow + i);
			per (j, n, n - i + 1) a[j]++;
		}
	}

	void solve() {
		std::memset(&ans, 0x3f, sizeof ans);
		dfs(0);
		std::cout << ans << "\n";
	}
}

namespace Task1 {
	void solve() {
		i64 ans = 0;
		while (true) {
			bool st = true;
			rep (i, 1, n) st &= a[i] <= 0;
			if (st) break;

			rep (i, 1, n) db << a[i] << " \n"[i == n];

			int cur = 1e9, len = 0;
			int t = 0;

			int pre = 0;
			rep (i, 1, n) {
				pre += a[i] >= 0;

				int now = i - pre;
				if (now < cur) {
					cur = now; len = i;
					t = 1;
				} else if (now == cur) {
					len = std::max(len, (int) i);
					t = 1;
				}
			}

			int suf = 0;
			rep (i, 1, n) {
				suf += a[n - i + 1] >= 0;
				int now = i - suf;
				if (now < cur) {
					cur = now; len = i;
					t = -1;
				} else if (now == cur) {
					len = std::max(len, (int) i);
					t = -1;
				}
			}

			db << "cur : " << cur << " len : " << len << "\n";

			if (t == 1) {
				rep (i, 1, len) {
					a[i] --;
				}
				ans += len;
			} else {
				per (i, n, n - len + 1) {
					a[i] --;
				}
				ans += len;
			}
		}

		std::cout << ans << "\n";
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];

	Task0::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}

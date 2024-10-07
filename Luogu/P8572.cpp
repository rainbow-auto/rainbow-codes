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

const int maxn = 500005;
const int maxB = 711;

int n, k, q;

std::vector<int> a[maxn];
std::vector<i64> sum[maxn];

namespace Case1 {
	void solve() {
		while (q--) {
			int l, r; std::cin >> l >> r;
			i64 ans = 0;
			rep (i, 1, k) {
				ans = std::max(ans, sum[i][r] - sum[i][l - 1]);
			}
			std::cout << ans << "\n";
		}
	}
}

namespace Case2 {
	i64 ans[maxB][maxB];
	void solve() {
		rep (l, 1, n) {
			rep (r, l, n) {
				rep (i, 1, k) {
					ans[l][r] = std::max(ans[l][r], sum[i][r] - sum[i][l - 1]);
				}
			}
		}

		while (q--) {
			int l, r; std::cin >> l >> r;
			std::cout << ans[l][r] << "\n";
		}
	}
}

void solve() {
	std::cin >> n >> k >> q;

	rep (i, 1, k) a[i].resize(n + 1);
	rep (i, 1, k) sum[i].resize(n + 1);

	rep (i, 1, k) {
		rep (j, 1, n) {
			std::cin >> a[i][j];
			sum[i][j] = sum[i][j - 1] + a[i][j];
		}
	}

	if (k < 711) Case1::solve();
	else Case2::solve();
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

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

const i64 mod = 998244353;

int n, m;
int k;

void solve() {
	std::cin >> n >> m;
	std::cin >> k;

	if (k == 1) {
		std::cout << "1\n";
		return;
	}
	if (k == 2) {
		std::cout << (n + m - 2) % mod << "\n";
		return;
	}
	if (k == 3) {
		std::cout << 4ll * (n - 1) % mod * (m - 1) % mod << "\n";
	}
	if (k == 4) {
		if (m < 2 or n < 2) {
			std::cout << "0\n";
			return;
		}
		i64 res = 0;
		(res += 1ll * (n - 1) * (m - 1) % mod * (m - 2) % mod) %= mod;
		(res += 1ll * (m - 1) * (n - 1) % mod * (n - 2) % mod) %= mod;
		(res += 1ll * (n - 1) * (m - 1)) %= mod;
		std::cout << res << "\n";
		return;
	}
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen("floor.in", "r", stdin);
	freopen("floor.out", "w", stdout);

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}

#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using u64 = unsigned long long;
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

const int maxn = 1000005;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

u64 sum[maxn];

void solve() {
	int n; std::cin >> n;
	int q; std::cin >> q;

	rep (i, 1, n) sum[i] = 0;

	std::set <u64> vis;
	auto gen = [&vis]() -> u64 {
		u64 res = rng();
		while(vis.count(res)) res = rng();
		vis.insert(res);
		return res;
	};

	std::map <int, u64> val;
	rep (i, 1, n) {
		int x; std::cin >> x;
		if (not val.count(x)) {
			val[x] = gen();
		}

		sum[i] = (sum[i - 1] xor val[x]);
	}

	while (q--) {
		int l, r; std::cin >> l >> r;
		if (sum[l - 1] ^ sum[r]) std::cout << "NO\n";
		else std::cout << "YES\n";
	}
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}

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

const int maxn = 205;

int n;
int t[maxn], w[maxn];

int f[maxn];
int sum;

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> t[i] >> w[i];
	rep (i, 1, n) sum += t[i];

	memset(f, 0x3f, sizeof f);
	f[0] = 0;

	rep (i, 1, n) {
		per (j, sum, t[i]) {
			f[j] = std::min(f[j], f[j - t[i]] + w[i]);
		}			
	}

	per (i, sum, 0) {
		if (sum - i >= f[i]) {
			std::cout << sum - i << "\n";
			break;
		}
	}
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

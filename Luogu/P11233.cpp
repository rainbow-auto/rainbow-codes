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

const int maxn = 1000005;

int n;
i64 a[maxn], aR;

i64 colmx[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];

	aR = 0;
	rep (i, 1, n) aR = std::max(aR, a[i]);
	rep (i, 1, aR) colmx[i] = -0x3f3f3f3f;

	i64 sum = 0;
	rep (i, 2, n) sum += (a[i - 1] == a[i]) * a[i];

	i64 mx = 0;
	n = std::unique(a + 1, a + n + 1) - a - 1;
	rep (i, 1, n) {
		i64 fnew = std::max({ mx, colmx[a[i]] + a[i] });
		mx = std::max(mx, fnew);
		colmx[a[i - 1]] = std::max(colmx[a[i - 1]], fnew);
	}

	std::cout << sum + mx << "\n";
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

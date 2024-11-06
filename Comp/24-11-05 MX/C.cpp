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

int n, m, k;

void solve() {
	std::cin >> n >> m;
	std::cin >> k;

	std::vector<std::vector<int>> A(k, std::vector<int>(k));

	rep (i, 1, n) {
		rep (j, 1, m) {
			int x; std::cin >> x;
			A[i % k][j % k] += x;
		}
	}	

	std::vector<int> a(k), b(k);
	// \forall a_i + b_j = A_{i, j}
	a[0] = A[0][0];
	b[0] = 0;

	rep (i, 1, k - 1) a[i] = A[i][0] - b[0];
	rep (i, 1, k - 1) b[i] = A[0][i] - a[0];

	bool ans = true;
	rep (i, 0, k - 1) rep (j, 0, k - 1) ans &= (a[i] + b[j] == A[i][j]);

	if (ans) std::cout << "YES\n";
	else std::cout << "NO\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::freopen("matrix.in", "r", stdin);
	std::freopen("matrix.out", "w", stdout);

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
